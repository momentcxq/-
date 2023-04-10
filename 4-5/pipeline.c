// ����ܵ�����
# define STD_INPUT 0				// �����׼�����豸������
# define STD_OUTPUT 1				// �����׼����豸������

int fd[2];

main()
{
	static char process1[]="father",process2[]="child";
	pipe(fd);						// ����ܵ�
	pipeline(process1,process2);	// �����Զ��庯��pipeline()
	exit(1);						// �������
}

pipeline(char* process1,char* process2)
{
    int i;
	while ((i=fork())==-1);			// �������̣�ֱ�������ɹ�Ϊֹ
    if(i)
	{
		close(fd[0]);				// �رչܵ�����������
		close(STD_OUTPUT);			// �رձ�׼���������1
		dup(fd[1]);					// ָ����׼���������1Ϊ�ܵ�дָ��
		close(fd[1]);				// �ر�ԭʼ�ܵ�дָ��
		execl(process1,process1,0);	// �ó���father1���ǵ�ǰ����
		printf(" father failed.\n");// execl()ִ��ʧ��
	}
	else
	{
		close(fd[1]);				// �رչܵ����������
		close(STD_INPUT);			// �رձ�׼����������0
		dup(fd[0]);					// ָ����׼����������0Ϊ�ܵ���ָ��
		close(fd[0]);				// �ر�ԭʼ�ܵ���ָ��
		execl(process2,process2,0);	// �ó���child1���ǵ�ǰ����
		printf("child failed.\n");	// execl()ִ��ʧ��
	}
	exit(2);						// �������
}
