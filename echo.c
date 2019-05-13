#include "headers.h"

void echo_command(char **argtodisplay)
{
	if (argtodisplay[1] == NULL)
	{
		printf("Please give argument to display");
	}
	else
	{
		int i=1;
		while(argtodisplay[i]!=NULL)
		{
			printf("%s ",argtodisplay[i]);
			i++;
		}
	}
	printf("\n");
}
