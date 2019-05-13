#ifndef FUN_H
#define FUN_H
	void getsubstring(char *currdir,char *name);
	char **splitline(char *line);
	void clock_command(char **args);
	void personal_reminder(char **args);
	void process_info(char **args);
	void background_process(char **args,pid_t *pid);
	void check_background(pid_t *pid);
	void foreground_process(char **args);
	void ls_command(char **args,char *currdir);
	void echo_command(char **argtodisplay);
	void change_directory_function(char *dirname);
	void setenv_command(char **args,int position);
	void unsetenv_command(char **args,int position);
	void jobs(pid_t *pid1);
	void kjobs(char **args,int position,int pid_t *pid);
	void fg(char **args,int positio,pid_t pid);
	void overkill(pid_t pid);

#endif










