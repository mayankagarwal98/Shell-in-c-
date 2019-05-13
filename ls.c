#include "headers.h"
void ls_command(char **args,char *currdir)
{
	DIR *dp;
    struct dirent *dirp;
    if ((dp = opendir(currdir)) == NULL)
        printf("can’t open \"%s\" this directory", currdir);
	if (args[1]!=NULL)
	{
		if (strcmp(args[1],"-a")==0)
	 	{
	 		while ((dirp = readdir(dp)) != NULL)
			{
		      	printf("%-7s\n",dirp->d_name);
    		}
		}
		else if(strcmp(args[1],"-l")==0)
		{
			while ((dirp = readdir(dp)) != NULL)
			{
				struct stat fileStat;
				struct timespec st_mtim;
				struct passwd *pw;
				struct group *gr;
	        	stat(dirp->d_name,&fileStat); 
 				if(dirp->d_name[0]!='.')
 				{
		        	printf( (S_ISDIR(fileStat.st_mode)) ? "d" : "-");
                	printf( (fileStat.st_mode & S_IRUSR) ? "r" : "-");
	                printf( (fileStat.st_mode & S_IWUSR) ? "w" : "-");
	                printf( (fileStat.st_mode & S_IXUSR) ? "x" : "-");
	                printf( (fileStat.st_mode & S_IRGRP) ? "r" : "-");
	                printf( (fileStat.st_mode & S_IWGRP) ? "w" : "-");
	                printf( (fileStat.st_mode & S_IXGRP) ? "x" : "-");
	                printf( (fileStat.st_mode & S_IROTH) ? "r" : "-");
	                printf( (fileStat.st_mode & S_IWOTH) ? "w" : "-");
	                printf( (fileStat.st_mode & S_IXOTH) ? "x" : "-");
	                char date[100];
	                strftime(date, 30, "%b %d %H:%M ",localtime(&(fileStat.st_mtime)));
	                printf(" %5ld %5s %5s %5ld %5s %5s\n",fileStat.st_nlink, getpwuid((fileStat.st_uid))->pw_name, getgrgid(fileStat.st_gid)->gr_name,fileStat.st_size,date,dirp->d_name);
		        }
        	}
 
		}
		else if(strcmp(args[1],"-la")==0 || strcmp(args[1],"-al")==0)
		{
			while ((dirp = readdir(dp)) != NULL)
			{
				struct stat fileStat;
				struct timespec st_mtim;
				struct passwd *pw;
				struct group *gr;
	        	stat(dirp->d_name,&fileStat); 
		       	printf( (S_ISDIR(fileStat.st_mode)) ? "d" : "-");
               	printf( (fileStat.st_mode & S_IRUSR) ? "r" : "-");
	            printf( (fileStat.st_mode & S_IWUSR) ? "w" : "-");
	            printf( (fileStat.st_mode & S_IXUSR) ? "x" : "-");
	            printf( (fileStat.st_mode & S_IRGRP) ? "r" : "-");
	            printf( (fileStat.st_mode & S_IWGRP) ? "w" : "-");
	            printf( (fileStat.st_mode & S_IXGRP) ? "x" : "-");
	            printf( (fileStat.st_mode & S_IROTH) ? "r" : "-");
	            printf( (fileStat.st_mode & S_IWOTH) ? "w" : "-");
	            printf( (fileStat.st_mode & S_IXOTH) ? "x" : "-");
	            char date[100];
	          	strftime(date, 30, "%b %d %H:%M ",localtime(&(fileStat.st_mtime)));
	            printf(" %5ld %5s %5s %5ld %5s %5s\n",fileStat.st_nlink, getpwuid((fileStat.st_uid))->pw_name, getgrgid(fileStat.st_gid)->gr_name,fileStat.st_size,date,dirp->d_name);
        	}
		}
		else
		{
			printf("ls_command does not exist\n");
		}
	}
	else
	{
		while ((dirp = readdir(dp)) != NULL)
		{
			if(dirp->d_name[0]!='.')
		      	printf("%s\n",dirp->d_name);
    	}
	}
	
}
