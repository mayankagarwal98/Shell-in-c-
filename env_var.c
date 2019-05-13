#include "headers.h"

void setenv_command(char **args,int position)
{
	if(position==1 || position > 3)
	{
		printf("zero or more than two arguments not allowed");
		return; 
	}
	else
	{
		if(position==2)
    	{
      		setenv(args[1] , " " , 2);
    	}
    	else
    	{
      		setenv(args[1] , args[2] , 2);
    	}
	}
}
void unsetenv_command(char **args,int position)
{
	if(position==1)
	{
		printf("zero arguments not allowed");
		return;
	}
	else
	{
		unsetenv(args[1]);
	}
}