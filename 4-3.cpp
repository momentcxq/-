// fileobj��Ŀ
# include <windows.h>
# include <iostream>

// Ҫʹ�õ��ļ���
static LPCTSTR g_szFileName = "w2kdg.Fileobj.file.data.txt" ;

// �������ļ��ж�ȡ��ǰ���ݵļ��߳�ʱ���������ĸ��������ӣ���д�������ļ���
static DWORD WINAPI ThreadProc (LPVOID lpParam)
{
    // ����������Ϊ������
    LONG nAdd = reinterpret_cast <LONG> (lpParam) ;

    // ������ȫ��ָ���ļ���
    TCHAR szFullName [MAX_PATH] ;
    :: GetTempPath(MAX_PATH, szFullName) ;
    :: strcat(szFullName, g_szFileName) ;

    // ���ļ�����
	HANDLE hFile = :: CreateFile(
        szFullName,									// �ļ�����ȫ����
        GENERIC_READ | GENERIC_WRITE,				// �������еķ���Ȩ
        FILE_SHARE_READ,							// ���������̶߳�ȡ
        NULL,										// ȱʡ�İ�ȫ��
        OPEN_ALWAYS,								// ��������ļ�
        FILE_ATTRIBUTE_NORMAL,						// ��ͨ�ļ�
        NULL) ;										// ��ģ���ļ�
    if (hFile != INVALID_HANDLE_VALUE)
    {
        // ��ȡ��ǰ����
        LONG nValue(0) ;
        DWORD dwXfer(0) ;
        :: ReadFile(
            hFile,									// Ҫ��ȡ���ļ�
            reinterpret_cast <LPVOID> (&nValue) ,	// ������
            sizeof(nValue) ,						// ����������
            &dwXfer,								// ��ȡ���ֽ���
            NULL) ;									// ���ص�I/O
        if (dwXfer == sizeof(nValue) )
        {
            // ��ʾ��ǰ����
            std :: cout << "read: " << nValue << std :: endl;
        }

        // ������ֵ
        nValue += nAdd;

        // д�����ô洢����
        :: SetFilePointer(hFile, 0, NULL, FILE_BEGIN) ;
        :: WriteFile(
            hFile,									// Ҫд����ļ�
            reinterpret_cast <LPCVOID> (&nValue) ,	// ����
            sizeof(nValue),							// ����������
            &dwXfer,								// д����ֽ���
            NULL) ;									// ���ص�I/O
        if (dwXfer == sizeof(nValue) )
        {
            std :: cout << "write: " << nValue << std :: endl;
        }

        // ����ļ�
        :: CloseHandle(hFile) ;
        hFile = INVALID_HANDLE_VALUE;
    }

    return(0) ;
}

void main()
{
    // ����100���̴߳��ļ��н��ж�д
    for (int nTotal = 100; nTotal > 0; --nTotal)
    {
        // �����߳�
        HANDLE hThread = :: CreateThread(
            NULL,							// ȱʡ�İ�ȫ��
            0, 								// ȱʡ�Ķ�ջ
            ThreadProc,						// �̺߳���
            reinterpret_cast <LPVOID> (1) ,	// ����
            0,								// ������Ĵ�����־
            NULL) ;							// �����߳�id

        // �ȴ��߳����
        :: WaitForSingleObject(hThread, INFINITE) ;

        // �ͷ�ָ���̵߳ľ��
        :: CloseHandle(hThread) ;
        hThread = INVALID_HANDLE_VALUE;
    }
}
