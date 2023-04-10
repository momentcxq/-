// ����largealloc
# include <windows.h>
# include <iostream>

// ������ָ�����ȵ�����������ڴ��ļ�㷽��
void FillZero(LPVOID pBlock, DWORD dwSize)
{
    _try
    {
        BYTE* arFill = (BYTE *) pBlock;
        for (DWORD dwFill = 0; dwFill < dwSize; ++dwFill)
        {
            arFill [dwFill] = 0; 
        }
        std :: cout << "Memory zeroed." << std :: endl;
    }
    _except(EXCEPTION_EXECUTE_HANDLER)
    {
        std :: cout << "Could not zero memory. " << std :: endl;
    }
}

void main()
{
    // �򵥵ĳ���
    DWORD c_dwGigabyte = 1 << 30;
    DWORD c_dwMegabyte = 1 << 20;

    // ʹ���ڴ���������1GB��
    {
        LPVOID pBlock = :: malloc(c_dwGigabyte) ;
        :: FillZero (pBlock, c_dwMegabyte) ;
        :: free(pBlock) ;
    }

    // ʹ����������Ի������1GB��
    {
        LPVOID pBlock = :: VirtualAlloc(
            NULL,				// ��ָ����ʼ��ַ
            c_dwGigabyte,		// Ҫ��1GB
            MEM_COMMIT,		    // ��������洢
            PAGE_READWRITE) ;	// �Դ˵Ķ�д����
            :: FillZero(pBlock, c_dwMegabyte) ;
            :: VirtualFree(pBlock, 0, MEM_RELEASE) ;
    }

    // ʹ����������Ի������1GB��
    {
        LPVOID pBlock = :: VirtualAlloc(
            NULL,				// ��ָ����ʼ��ַ
            c_dwGigabyte,		// Ҫ��1GB
            MEM_RESERVE,		// ����������洢
            PAGE_READWRITE) ;	// �Դ˵Ķ�д����
        :: FillZero(pBlock, c_dwMegabyte) ;
        :: VirtualFree(pBlock, 0, MEM_RELEASE) ;
	}

	//ʹ������������������1GB�飬��Ϊ�����1MB����洢
	{
        LPVOID pBlock = :: VirtualAlloc(
            NULL,				// ��ָ����ʼ��ַ
            c_dwGigabyte,		// Ҫ��1GB
            MEM_RESERVE,		// ����������洢
            PAGE_READWRITE) ;	// �Դ˵Ķ�д����

        :: VirtualAlloc(
            pBlock,
            c_dwMegabyte,
            MEM_COMMIT,
            PAGE_READWRITE) ;

        :: FillZero(pBlock, c_dwMegabyte) ;
        :: VirtualFree(pBlock, 0, MEM_RELEASE) ;
    }
}

