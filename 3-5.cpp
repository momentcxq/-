#include <windows.h>
#include <iostream>
#include <stdio.h>
// �������ݹ����Ľ��̵Ŀ�¡���̲������� ID ֵ
void StartClone(int nCloneID)
{
	// ��ȡ���ڵ�ǰ��ִ���ļ����ļ���
	TCHAR szFilename[MAX_PATH];
	GetModuleFileName(NULL, szFilename, MAX_PATH);
	// ��ʽ�������ӽ��̵������в�֪ͨ�� EXE �ļ����Ϳ�¡ ID
	char szCmdLine[MAX_PATH];
	sprintf_s(szCmdLine, "\"%s\" %d", szFilename, nCloneID);
	// �����ӽ��̵� STARTUPINFO �ṹ
	STARTUPINFO si;
	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si); // �����Ǳ��ṹ�Ĵ�С
	// ���ص������ӽ��̵Ľ�����Ϣ
	PROCESS_INFORMATION pi;
	// ����ͬ���Ŀ�ִ���ļ��������д������̣����������ӽ��̵�����
	BOOL bCreateOK = ::CreateProcess(
		szFilename, // ������� EXE ��Ӧ�ó��������
		szCmdLine, // ��������Ϊ��һ���ӽ��̵ı�־
		NULL, // ȱʡ�Ľ��̰�ȫ��
		NULL, // ȱʡ���̰߳�ȫ��
		FALSE, // ���̳о��
		CREATE_NEW_CONSOLE, // ʹ���µĿ���̨
		NULL, // �µĻ���
		NULL, // ��ǰĿ¼
		&si, // ������Ϣ
		&pi); // ���صĽ�����Ϣ
	// ���ӽ����ͷ�����
	if (bCreateOK)
	{
		CloseHandle(pi.hProcess);
		CloseHandle(pi.hThread);
	}
}
int main(int argc, char* argv[])
{
	// ȷ���������������̣������������ڽ����б��е�λ��
	int nClone = 0;
	//�޸���䣺int nClone;
	//��һ���޸ģ�nClone=0;
	if (argc > 1)
	{
		// �ӵڶ�����������ȡ��¡ ID
		::scanf_s(argv[1], "%d", &nClone);
	}
	//�ڶ����޸ģ�nClone=0;
	// ��ʾ����λ��
	std::cout << "Process ID:" << ::GetCurrentProcessId()
		<< ", Clone ID:" << nClone
		<< std::endl;
	// ����Ƿ��д����ӽ��̵���Ҫ
	const int c_nCloneMax = 5;
	if (nClone < c_nCloneMax)
	{
		// �����½��̵������кͿ�¡��
		StartClone(++nClone);
	}
	// �ȴ���Ӧ���������������
	getchar();
	return 0;
}