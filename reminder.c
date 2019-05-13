#include "headers.h"
void personal_reminder(char **args)
{
	pid_t  pid1,wpid;
  	int status;

 	pid1= fork();
  	if (pid1 == 0)
  	{
  		int x;
  		sscanf(args[1], "%d", &x);
   		sleep(x);
   		int i=2;
   		printf("\nReminder:");
   		while(args[i]!=NULL)
   		{
   			printf("%s ",args[i] );
   			i++;
   		}
   		printf("\n");
  	}
   	else if (pid1 < 0)
  	{
    	perror("lsh");
  	}
}