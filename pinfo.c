#include "headers.h"
void process_info(char **args)
{
	if(args[1]==NULL)
	{
		int pid =getpid();
		printf("pid -- %d\n",pid);
		char buf[1000];
		snprintf(buf, sizeof(buf), "/proc/%d/stat", pid);
		FILE *in_file  = fopen(buf, "r");
		if (in_file == NULL)
		{
			printf("error in reading or process id does not exist\n");
			return;
		}
		char number[100];
		for (int i = 0; i < 3; ++i)
		{
			fscanf(in_file, "%s", number );
		}
		printf("Process Status : %s\n",number );
		char buf1[10000];
		snprintf(buf1, sizeof(buf1), "/proc/%d/status", pid);
		FILE *in_file1  = fopen(buf1, "r");
		if (in_file1 == NULL)
		{
			printf("error in reading or process id does not exist\n");
			return;
		}
		int l=0;
		int c=1;
		char number1[100];
		while (strcmp("VmSize:",number1)!=0)
		{
			if(fscanf(in_file1, "%s", number1)==EOF)
			{
				c=0;
				break;
			}
		}
		if (c==1)
		{
			fscanf(in_file1,"%s",number1);
		}
		else
		{
			strcpy(number1,"0");
		}
		printf("Virtual Memory : %s\n",number1);
		char buf2[1000];
		snprintf(buf2, sizeof(buf2), "/proc/%d/exe", pid);
		char buf3[10000];
		char *res = realpath(buf2, buf3);
		if (res)
		{
			char *newstring=malloc(1000*sizeof(char));
			char *name=getlogin();
			int i=6+strlen(name);
			for (int j = 0; j < strlen(res); ++j)
			{
				newstring[j]=res[j+i];		
			}
			printf("Executable Path - ~%s\n",newstring);
		}
		else
		{
			printf("error\n");
			return;
		}
	}
	else
	{
		int pid;
		sscanf(args[1], "%d", &pid);
		printf("pid -- %d\n",pid);
		char buf[1000];
		snprintf(buf, sizeof(buf), "/proc/%d/stat", pid);
		FILE *in_file  = fopen(buf, "r");
		if (in_file == NULL)
		{
			printf("error in reading or process id does not exist\n");
			return;
		}
		char number[100];
		for (int i = 0; i < 3; ++i)
		{
			fscanf(in_file, "%s", number );
		}
		printf("Process Status : %s\n",number );
		char buf1[10000];
		snprintf(buf1, sizeof(buf1), "/proc/%d/status", pid);
		FILE *in_file1  = fopen(buf1, "r");
		if (in_file1 == NULL)
		{
			printf("error in reading or process id does not exist\n");
			return ;
		}
		int l=0;
		int c=1;
		char number1[100];
		while (strcmp("VmSize:",number1)!=0)
		{
			if(fscanf(in_file1, "%s", number1)==EOF)
			{
				c=0;
				break;
			}
		}
		if (c==1)
		{
			fscanf(in_file1,"%s",number1);
		}
		else
		{
			strcpy(number1,"0");
		}
		printf("Virtual Memory : %s\n",number1);	
		char buf2[1000];
		snprintf(buf2, sizeof(buf2), "/proc/%d/exe", pid);
		char buf3[10000];
		char *res = realpath(buf2, buf3);
		if (res)
		{
			printf("Executable Path - %s\n",res );
		}
		else
		{
			printf("error\n");
			return;
		}
	}

}