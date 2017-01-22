#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<sys/wait.h>
#define SIZE 80

int main(int argv,char *args[])
{
	char buffer[SIZE],*token[SIZE],*file;
	while(1)
	{
		printf("user/rsh$ ");
		//if(!scanf(" %80[^\n]s",buffer))continue;
		gets(buffer,SIZE);
		if(feof(stdin))
		{
			strcpy(buffer,"exit ");
			printf("exit\n");
		}
		token[0]=strtok(buffer," ");
		int i=1;
		do
		{
			token[i]=strtok(NULL," ");
		}while(token[i++]!=NULL);
		int pid=fork();
		if(pid==0)
		{
			//printf("%s\n",token[0]);
			if(strcmp(token[0],"exit")==0)
			{
				//printf("rsh closing... have a nice day\n");
				return 0;
			}
			else if(strcmp(token[0],"cd")==0)
			{
				if(token[1]!=NULL&&token[2]==NULL)
				{
					if(chdir(token[1]))
					{
						printf("error in changing directory\n");
					}
				}
				else
				{
					printf("cd <path> is the format\n");
				}
			}
			else
				execvp(token[0],token);
		}
		else
		{
			if(strcmp(token[0],"exit")==0)
			{
				printf("rsh closing... have a nice day\n");
				return 0;
			}
			waitpid(pid,NULL,0);
		}
	} 
	return 0;
}