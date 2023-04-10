// 定义父进程程序
main()
{
	static char string[] = "parent is using pipe write.";
	int len;
	len = sizeof(string);
	write(1,string,len);
    printf("parent,parent,parent\n\n\n");
	exit(0);
}