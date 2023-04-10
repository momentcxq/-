//定义子进程程序
main(){
	char output[30];
	read(0,output,30);//从管道中读数据并存放入output中
	printf("%s\nchild,child.\n",output);
	return(0);
}