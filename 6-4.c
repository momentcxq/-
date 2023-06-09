// 清单6-4  让扬声器按指定的长度和音频发声
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/ioctl.h>
# include <sys/types.h>
# include <linux/kd.h>

// 设定默认值 
# define DEFAULT_FREQ 440		// 设定一个合适的频率 
# define DEFAULT_LENGTH 200		// 200微秒，发声的长度以微秒为单位 
# define DEFAULT_REPS 1			// 默认不重复发声 
# define DEFAULT_DELAY 100		// 同样以微秒为单位 

// 定义一个结构，存储所需的数据 
typedef struct {
	int freq;					// 期望输出的频率，单位为Hz 
    int length;					// 发声长度，以微秒为单位
    int reps;			        // 重复的次数
    int delay;		            // 两次发声间隔，以微秒为单位 
} beep_parms_t;

// 打印帮助信息并退出 
void usage_bail(const char *executable_name)
{
	printf("Usage: \n \t%s [-f frequency] [-l length] [-r reps]
		[-d delay] \n ",executable_name) ;
    exit(1) ;
}

// 分析运行参数，各项意义如下：
// "-f <以Hz为单位的频率值>"
// "-l <以毫秒为单位的发声时长>"
// "-r <重复次数>"
// "-d <以毫秒为单位的间歇时长>"

void parse_command_line(char **argv, beep_parms_t *result)
{
	char *arg0 = *(argv++) ;
    while (*argv)
	{
		if (!strcmp(*argv, "-f" ) )
		{											// 频率 
             int freq = atoi(*( ++argv) ) ;
             if ( (freq <= 0) || (freq > 10000) )
			 {
                 fprintf(stderr, "Bad parameter: frequency must be from l..10000\n" ) ;
                 exit(1) ;
			 }
			 else
			 {
				 result -> freq = freq;
                 argv++;
			 }
		} else
			if (!strcmp(*argv, "-l") )
			{										// 发声的时间长度
				int length = atoi( *(++argv) ) ;
                if (length < 0)
				{
				    fprintf(stderr, "Bad parameter: length must be >= 0\n" ) ;
                    exit(1) ;
				} else
				{
					result -> length = length;
                    argv++;
				}
			} else 
				if (!strcmp(*argv, "-r" ) )
				{									// 重复次数 
					int reps = atoi( * (++argv) ) ;
                    if (reps < 0)
					{
						fprintf(stderr, "Bad parameter：reps must be >= 0\n" ) ;
                        exit(1) ;
					} else
					{
						result -> reps = reps;
                        argv++;
					}
				} else if (!strcmp(*argv, "-d") )
				{									// 延时
					int delay = atoi( * (++argv) ) ;
                    if (delay < 0)
					{
						fprintf(stderr, "Bad parameter: delay must be >= 0\n" ) ;
                        exit(1) ;
					} else
					{
                      result -> delay = delay;
                      argv++;
					}
				} else
				{
                  fprintf(stderr, "Bad parameter：%s\n" , *argv) ;
                  usage_bail(arg0) ;
				}
	}
}

int main(int argc, char **argv)
{
	int console_fd;
    int i;							// 循环计数器

	// 设发声参数为默认值
	beep_parms_t  parms={DEFAULT_FREQ, DEFAULT_LENGTH, DEFAULT_REPS, DEFAULT_DELAY} ;

	// 分析参数，可能的话更新发声参数
	parse_command_line(argv, &parms) ;

	// 打开控制台，失败则结束程序
	if ( (console_fd = open("/dev/console" , O_WRONLY) )== -1)
	{
		fprintf(stderr, "Failed to open console. \n") ;
		perror("open") ;
        exit(1) ;
	}

	// 真正开始让扬声器发声
	for (i = 0; i < parms.reps; i++)
	{
		// 数字1190000从何而来，不得而知 
		int magical_fairy_number = 1190000/parms.freq;
		ioctl(console_fd, KIOCSOUND, magical_fairy_number);	// 开始发声
        usleep(1000 * parms.length) ;						// 等待…
        ioctl(console_fd, KIOCSOUND, 0) ;					// 停止发声
        usleep(1000 * parms.delay) ;						// 等待…
	}												        // 重复播放
	return EXIT_SUCCESS;
}
