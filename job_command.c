#include "headers.h"
extern int num;
extern char pidname[100][100];
extern int pid_status[100];
void jobs(pid_t *pid1)
{
	check_background(pid1);    
    for(int k=0; k<num;k++)
    {
        if (pid_status[k]!=-1)
            printf("[%d] Running  %s[%d]\n",k+1,pidname[k],pid1[k]);
        else
            printf("[%d] Stopped  %s[%d]\n",k+1,pidname[k],pid1[k]);
    }
}
void kjobs(char **args,int position, pid_t *pid)
{
    if (position==3)
    {
        if(num>=atoi(args[1]))
        {
            if(pid_status[atoi(args[1])-1]==-1)
            {
                printf("already stopped");
            }
            else
            {
                kill(pid[atoi(args[1])-1],atoi(args[2]));
                pid_status[atoi(args[1])-1]=-1;
            }
        }
        else
        {
            printf("process does not exist\n");
        }
    }
    else{
        perror("error");
    }
}
void fg(char **args,int position ,pid_t *pid)
{
    if (position==2)
    {
        if(num>=atoi(args[1]))
        {
            pid_status[atoi(args[1])-1]=-1;
            int status;
            pid_t wpid;
            do 
            {
                wpid = waitpid(pid[atoi(args[1])-1], &status, WUNTRACED);
            } while (!WIFEXITED(status) && !WIFSIGNALED(status));
        }
        else
        {
            printf("process does not exist\n");

        }
    }
    else
    {
        perror("error");
    }
}
void bg(char **args,int position ,pid_t *pid)
{
     if (position==2)
    {
        if(num>=atoi(args[1]))
        {
            pid_status[atoi(args[1])-1]=0;
            kill(pid[atoi(args[1]-1)],SIGCONT);
        }
        else
        {
            printf("process does not exist\n");

        }
    }
    else
    {
        perror("error");
    }
}
void overkill(pid_t *pid)
{
    for(int i=0;i<num;i++)
    {
       if(pid_status[i]!=-1)
        {
            kill(pid[i],9);
            pid_status[i]=-1;
        }
    }
    return;
}