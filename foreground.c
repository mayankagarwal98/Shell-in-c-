#include "headers.h"
//  void handle_sigint1(int sig) 
// { 
//     return;
// } 
void foreground_process(char **args)
{
  pid_t pid, wpid;
  int status;

  pid = fork();
  if (pid == 0)
  {
   	int a=execvp(args[0], args);
   	if(a==-1)
   	{
   		perror("lsh");
   	}
  }
   else if (pid < 0)
  {
    perror("lsh");
  }
   else 
  {
    // signal(SIGSTOP, handle_sigint1 ); 
    do 
    {
      wpid = waitpid(pid, &status, WUNTRACED);
    } while (!WIFEXITED(status) && !WIFSIGNALED(status));
  }
}