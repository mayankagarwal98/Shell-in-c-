#include "headers.h"
int position=0;
#define DELIMITER " \t\r\n\a"
char **splitline(char *line)
{
  int bufsize = 1024;
  position = 0;
  char **tokens = malloc(bufsize * sizeof(char*));
  char *token, **tokens_backup;
  if (!tokens) {
    fprintf(stderr, "lsh: allocation error\n");
    exit(EXIT_FAILURE);
  }
  token = strtok(line, DELIMITER);
  while (token != NULL) {
    tokens[position] = token;
    position++;

    if (position >= bufsize) {
      bufsize += 1024;
      tokens_backup = tokens;
      tokens = realloc(tokens, bufsize * sizeof(char*));
      if (!tokens) {
		free(tokens_backup);
        fprintf(stderr, "lsh: allocation error\n");
        exit(EXIT_FAILURE);
      }
    }
    token = strtok(NULL, DELIMITER);
  }
  tokens[position] = NULL;
  return tokens;
}
void execute(char **args,char *currdir,pid_t *pid)
{
	if (args[0]==NULL)
	{
		return;
	}
		int std_in=dup(0);
		int std_out=dup(1);
  if(args[0][0]!='\0')
  {
    int inflag=0, outcount=0, appendcount=0;
    char inpfile[64], outputfile[16][64], appendfile[16][64];
    int fd;
    int i;
    for(i=0;args[i]!='\0';i++)
    {
      if(strcmp(args[i],"<")==0)
      {        
        args[i]=NULL;
        strcpy(inpfile,args[i+1]);
				
        inflag=1;           
      }
      else if(strcmp(args[i],">")==0)
      {      
        args[i]=NULL;
        strcpy(outputfile[outcount++],args[i+1]);
      }         
      else if(strcmp(args[i],">>")==0)
      {      
        args[i]=NULL;
        strcpy(appendfile[appendcount++],args[i+1]);
      }  
    }
    if(inflag!=0)
    { 
      fd = open(inpfile, O_RDONLY, 0);
      if(fd<0) perror("Error opening input file");
      if(dup2(fd,0) < 0) ("Error - input duping");
      close(fd);
    }
		
    for (i = 0; i < outcount; ++i)
    {
      fd = open(outputfile[i], O_WRONLY | O_TRUNC | O_CREAT  ,0644);
      if(fd<0) perror("Error opening output file");
      if(dup2(fd,1)<0) perror("Error - output duping");
      close(fd);
    }
    for (i = 0; i < appendcount; ++i)
    {
      fd = open(appendfile[i], O_WRONLY | O_APPEND | O_CREAT, 0644);
      if(fd<0) perror("Error opening the output(append) file");
      if(dup2(fd,1)<0) perror("Error - output(append) duping");
      close(fd);
    }
	}
	if(strcmp(args[0],"cd")==0)
	{
		change_directory_function(args[1]);
	}
  else if(strcmp(args[0],"bg")==0)
  {
    bg(args,position,pid);
  }
	else if (strcmp(args[0],"echo")==0)
	{
		echo_command(args);
	}
	else if (strcmp(args[0],"pwd")==0)
	{
		printf("%s\n",currdir );
	}
	else if (strcmp(args[0],"setenv")==0)
	{
		setenv_command(args,position);
	}
	else if (strcmp(args[0],"unsetenv")==0)
	{
		unsetenv_command(args,position);
	}
	else if (strcmp(args[position-1],"&")==0)
	{
		args[position-1]=NULL;
		background_process(args,pid);
	}
	else if(strcmp(args[0],"jobs")==0)
	{
		 jobs(pid);
	}
  else if(strcmp(args[0],"fg")==0)
  {
    fg(args,position,pid);
  }
	else if (strcmp(args[0],"ls")==0 && position<=2)
	{
		ls_command(args,currdir);
	}
  else if (strcmp(args[0],"kjob")==0)
  {
    kjobs(args,position,pid);
  }
  else if(strcmp(args[0],"overkill")==0)
  {
    overkill(pid);
  }
	else if (strcmp(args[0],"pinfo")==0 && position<=2)
	{
		process_info(args);
	}
	else if (strcmp(args[0],"remindme")==0)
	{
		personal_reminder(args);
	}
	else if (strcmp(args[0],"clock")==0 && position==3)
	{
		clock_command(args);
	}
	else if (strcmp(args[0],"quit")==0){
		exit(-1);
	}
	else 
		foreground_process(args);
dup2(std_in,0);
dup2(std_out,1);
}
int position1=0;
#define DELIMITER1 ";"

char **splitline_semicolon(char *line)
{
  int bufsize = 1024;
  position1 = 0;
  char **tokens = malloc(bufsize * sizeof(char*));
  char *token, **tokens_backup;

  if (!tokens) {
    fprintf(stderr, "lsh: allocation error\n");
    exit(EXIT_FAILURE);
  }

  token = strtok(line, DELIMITER1);
  while (token != NULL) {
    tokens[position1] = token;
    position1++;

    if (position1 >= bufsize) {
      bufsize += 1024;
      tokens_backup = tokens;
      tokens = realloc(tokens, bufsize * sizeof(char*));
      if (!tokens) {
		free(tokens_backup);
        fprintf(stderr, "lsh: allocation error\n");
        exit(EXIT_FAILURE);
      }
    }

    token = strtok(NULL, DELIMITER1);
  }
  tokens[position1] = NULL;
  return tokens;
}
int position2=0;
#define DELIMITER2 "|"
char **splitline_pipe(char *line)
{
  int bufsize = 1024;
  position2 = 0;
  char **tokens = malloc(bufsize * sizeof(char*));
  char *token, **tokens_backup;

  if (!tokens) {
    fprintf(stderr, "lsh: allocation error\n");
    exit(EXIT_FAILURE);
  }
  token = strtok(line, DELIMITER2);
  while (token != NULL) {
    tokens[position2] = token;
    position2++;

    if (position2 >= bufsize) {
      bufsize += 1024;
      tokens_backup = tokens;
      tokens = realloc(tokens, bufsize * sizeof(char*));
      if (!tokens) {
		free(tokens_backup);
        fprintf(stderr, "lsh: allocation error\n");
        exit(EXIT_FAILURE);
      }
    }

    token = strtok(NULL, DELIMITER2);
  }
  tokens[position2] = NULL;
  return tokens;
}
#define GRN   "\x1B[32m"
#define RESET "\x1B[0m"

int main(char const *argv[])
{
	pid_t pid[1000];
	// signal (SIGINT, SIG_IGN);
  // signal (SIGQUIT, SIG_IGN);
  // signal (SIGTSTP, SIG_IGN);
	while(1)
	{	
		check_background(pid);
		char *name = getlogin();
		struct utsname buf;
		uname(&buf);
		char *currdir=malloc(1000*sizeof(char));
		int size=1000;
		getcwd(currdir,size);
		printf("<" GRN "%s@%s" RESET ":",name,buf.nodename);
		getsubstring( currdir, name);
		char  **args,**args2;
		char *line = NULL;
		ssize_t bufsize=0;
		getline(&line,&bufsize,stdin);
		char **args1;
		args1=splitline_semicolon(line);
		for (int i = 0; i < position1; ++i)
		{
			int p[2];
			int fd=0;
			pid_t newproc;
			args=splitline_pipe(args1[i]);
			if (position2>1)
			{
				for(int j=0; j< position2; j++)
				{	
					args2=splitline(args[j]);
					pipe(p);
					newproc=fork();
					if(newproc==0)
      	  {
      	  	dup2(fd , 0);
      	    if(args[j+1]!=NULL) dup2(p[1],1);
      	    close(p[0]);
						getcwd(currdir,size);
						execute(args2,currdir,pid);
      	    exit(2);
      	  }
      		else
      	  {
      	    wait(NULL);
      	    close(p[1]);
      	  	fd = p[0];
      	    i++;
					}
				}
			}
			else
			{
				args2=splitline(args[0]);
				getcwd(currdir,size);
				execute(args2,currdir,pid);
			}
			free(args);
		}
		free(args1);
		free(line);
	}
	return 0;
}