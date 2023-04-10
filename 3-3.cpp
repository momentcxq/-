// prochandle项目
#include<windows.h>
#include<iostream>

// 确定自己的优先权的简单应用程序
void main()
{
    // 从当前过程中提取句柄
	HANDLE hProcessThis=::GetCurrentProcess();

	// 请求内核提供该过程所属的优先权类
	DWORD dwPriority=::GetPriorityClass(hProcessThis);

    // 发出消息，为用户描述该类	
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
        