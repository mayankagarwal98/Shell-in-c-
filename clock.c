 #include "headers.h"
int interupt=1;
 void handle_sigint(int sig) 
{ 
    interupt=0; 
} 
void clock_command(char **args)
{
	char time[100];
	char date[100];
	int x;
	interupt =1;
  	sscanf(args[2], "%d", &x);
    signal(SIGINT, handle_sigint); 
	while(interupt)
	{
		FILE *in_file1  = fopen("/proc/driver/rtc", "r");
		if (in_file1 == NULL)
		{
			printf("error in reading the rtc drivers\n");
			exit(-1);
		}
		fscanf(in_file1, "%s", time);
		fscanf(in_file1, "%s", time);
		fscanf(in_file1, "%s", time);
		fscanf(in_file1, "%s", date);
		fscanf(in_file1, "%s", date);
		fscanf(in_file1, "%s", date);
		printf("%s %s\n",date,time);
		sleep(x);
	}
}