#include "headers.h"
int num=0;
char pidname[100][100];
int pid_status[100];
void background_process(char **args,pid_t *pid)
{
	pid_t  wpid;
  	int status;

 	pid[num] = fork();
	strcpy(pidname[num],args[0]);
  	if (pid[num] == 0)
  	{
   		execvp(args[0], args);
  	}
   	else if (pid[num] < 0)
  	{
    	perror("lsh");
  	}
  	else
   		signal(SIGCHLD,SIG_DFL);
  	num++;
}
void check_background(pid_t *pid)
{
	for (int i = 0; i < num; ++i)
	{
		int status;
		if (waitpid(pid[i],&status,WNOHANG)!=0)
		{
			if(pid_status[i]!=-1)
			{
				printf("process with pid %d terminated sucessfully\n",pid[i] );
				pid_status[i]=-1;
			}
		}
	}
}