#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<sys/wait.h>
#define SIZE 80

int executeCommand(char *token[SIZE],int i,char mode)
{
	int DONT_WAIT=1;
	FILE *fin,*fout;
	switch(mode)
	{
		case '&':
			DONT_WAIT=1;
			break;
		case '|':
			//freopen("out","w",stdin);
			break;
	}
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
				//return 0;
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
			kill(pid, SIGKILL);
			printf("rsh closing... have a nice day\n");
			return 0;
		}
		if(!DONT_WAIT)
		{
			waitpid(pid,NULL,0);
		}
		else
		{
			printf("pid %d running\n",pid);
			return 1;
		}
	}
	return 1;
}

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
		if(buffer[0]==0)continue;
		token[0]=strtok(buffer," ");
		int i=1,j=0;
		do
		{
			token[i]=strtok(NULL," ");
			if(token[i]==NULL)
			{
				if(executeCommand(token+j,i,' ')==0)
				{
					return 0;
				}
				j=i+1;
			}
			else if(token[i]=="&")
			{
				token[i]=NULL;
				if(executeCommand(token+j,i,'&')==0)
				{
					return 0;
				}
				j=i+1;
			}
			else if(token[i]=="|")
			{
				token[i]=NULL;
				if(executeCommand(token+j,i,'|')==0)
				{
					return 0;
				}
				j=i+1;
			}
		}while(token[i++]!=NULL);
	} 
	return 0;
}
