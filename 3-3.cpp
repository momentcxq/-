// prochandle��Ŀ
#include<windows.h>
#include<iostream>

// ȷ���Լ�������Ȩ�ļ�Ӧ�ó���
void main()
{
    // �ӵ�ǰ��������ȡ���
	HANDLE hProcessThis=::GetCurrentProcess();

	// �����ں��ṩ�ù�������������Ȩ��
	DWORD dwPriority=::GetPriorityClass(hProcessThis);

    // ������Ϣ��Ϊ�û���������	
	std::cout<<"current process priority:";
	switch(dwPriority)
	{
        case HIGH_PRIORITY_CLASS:
			std::cout<<"High";
			break;
        case NORMAL_PRIORITY_CLASS:
			std::cout<<"Normal";
			break;
        case IDLE_PRIORITY_CLASS:
			std::cout<<"Idle";
			break;
        case REALTIME_PRIORITY_CLASS:
			std::cout<<"Realtime";
			break;
        default:
			std::cout<<"<unknow>";
			break;
	}

	std::cout<<std::endl;
}
        