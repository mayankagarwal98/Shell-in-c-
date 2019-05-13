#include "headers.h"


void change_directory_function(char *dirname)
{
	int a=0;
	if (dirname==NULL || strcmp(dirname,"~")==0)
	{
		a=chdir(getenv("HOME"));

	}
	else 
		a=chdir(dirname);
	if(a==-1)
	{
		perror("lsh");
	}
}
