#include "headers.h"
#define KBLU  "\x1B[34m"
#define RESET "\x1B[0m"
void getsubstring(char *currdir,char *name)
{
	char *newstring=malloc(1000*sizeof(char));
	int i=6+strlen(name);
	for (int j = 0; j < strlen(currdir); ++j)
	{
		newstring[j]=currdir[j+i];		
	}
	if (strlen(currdir)>=i)		
		printf(KBLU "~%s" RESET ,newstring);
	else
		printf(KBLU "%s" RESET,currdir);
	printf(">");	
}