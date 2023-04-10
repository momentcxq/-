// mappings��Ŀ
# include <windows.h>
# include <iostream>

// �ٲ÷��ʵĻ�����
static HANDLE g_hMutexMapping = INVALID_HANDLE_VALUE;

// ���ӹ����ڴ��е���ֵ�ļ��߳�
static DWORD WINAPI ThreadProc(LPVOID lpParam)
{
    // �������������
    HANDLE hMapping = reinterpret_cast <HANDLE> (lpParam) ;

    // �ȴ����ļ��ķ���
    :: WaitForSingleObject(g_hMutexMapping, INFINITE) ;

    // ӳ����ͼ
    LPVOID pFile = :: MapViewOfFile(
        hMapping,							// �����ļ��Ķ���
        FILE_MAP_ALL_ACCESS,				// ��ö�дȨ��
        0,									// ���ļ��Ŀ�ͷ�� (��32λ) ��ʼ
        0,									// ... (��32λ)
        0) ;								// ӳ�������ļ�
    if (pFile != NULL)
    {
        // �����ݿ���������
        LONG * pnData = reinterpret_cast <LONG *> (pFile) ;

        // �Ŷ�����
        ++ (* pnData) ;

        // ��ʾ����ֵ
        std :: cout << "thread: " << :: GetCurrentThreadId()
                       << "value: " << (* pnData) << std :: endl;

        // �ͷ��ļ���ͼ
        :: UnmapViewOfFile(pFile) ;
        pFile = NULL;
    }

    // �ͷŶ��ļ��ķ���Ȩ
    :: ReleaseMutex(g_hMutexMapping) ;

    return(0) ;
}

// �����������ݿռ�
HANDLE MakeSharedFile()
{
    // �����ļ�ӳ�����
    HANDLE hMapping = :: CreateFileMapping(
        INVALID_HANDLE_VALUE,				// ʹ��ҳʽ�ļ���ʱ�ļ�
        NULL,								// ȱʡ�İ�ȫ��
        PAGE_READWRITE,						// �ɶ�дȨ
        0,									// ������� (��32λ)
        sizeof(LONG) ,						// ... (��32λ)
        NULL) ;								// ������
    if (hMapping != INVALID_HANDLE_VALUE)
    {
        // ���ļ�ӳ���ϴ�����ͼ
        LPVOID pData = :: MapViewOfFile(
            hMapping,						// �����ļ��Ķ���
            FILE_MAP_ALL_ACCESS,			// ��ö�дȨ
            0,								// ���ļ��Ŀ�ͷ��(��32λ)��ʼ
            0,								// ... (��32λ)
            0 ) ;							// ӳ�������ļ�
        if (pData != NULL)
        {
            :: ZeroMemory(pData, sizeof(LONG)) ;
        }

        // �ر��ļ���ͼ
        :: UnmapViewOfFile(pData) ;
    }

    return (hMapping) ;
}

void main()
{
    // ���������ļ�
    HANDLE hMapping = :: MakeSharedFile() ;

    // �����ٲõĻ�����
    g_hMutexMapping = :: CreateMutex(NULL, FALSE, NULL) ;

    // �����ļ�����100���߳�����д
    for (int nTotal = 100; nTotal > 0; -- nTotal)
    {
        // �����߳�
        HANDLE hThread = :: CreateThread(
            NULL,								// ȱʡ�İ�ȫ��
            0,									// ȱʡ��ջ
            ThreadProc,							// �̺߳���
            reinterpret_cast <LPVOID> (hMapping) , 			// ����
            0,									// ������Ĵ�����־
            NULL) ;								// �����߳�id

        // �ȴ������߳��ͷ�
        if (nTotal == 1)
        {
            std :: cout << "all threads created, waiting..." << std :: endl;
            :: WaitForSingleObject(hThread, INFINITE) ;
        }

		:: Sleep(500) ;							// ���������ر����Կ���������

        // �ͷ�ָ���̵߳ľ��
        :: CloseHandle(hThread) ;
        hThread = INVALID_HANDLE_VALUE;
    }

    // �رն���
    :: CloseHandle(hMapping) ;
    hMapping = INVALID_HANDLE_VALUE;

    :: CloseHandle(g_hMutexMapping) ;
    g_hMutexMapping = INVALID_HANDLE_VALUE;
}
