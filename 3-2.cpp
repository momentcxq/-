// msgbox项目
# include <windows.h>

// 告诉连接器与包括MessageBox API函数的user32库进行连接
#pragma comment(lib,"user32.lib")

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
	::MessageBox(
		NULL,						// 没有父窗口
		"hello windows 2000",       // 消息框中的文本
		"GREET",					// 消息框的标题
		MB_OK);						// 其中只有一个ok按钮

    // 返回0以便通知系统不进入消息循环
	return 0;
}