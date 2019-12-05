
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<assert.h>
#include<sys/types.h>
#include<fcntl.h>
#include<sys/wait.h>
#define MAX_ARG 10
int main()
{
    while(1)
    {
        char buff[128]={0};//存放输入的命令和参数
        printf("[stu@localhost ~]$ ");
        fflush(stdout);

        fgets(buff,128,stdin);//ls,ps,-f,cp a.c b.c
        buff[strlen(buff)-1]=0;//'\0'

        char * myargv[MAX_ARG] = {0};//myargv[0] = "ps",myargv[1] = "-f" myargv[2]=0
        
        int i = 0;
        char *s = strtok(buff," ");
        char *cmd_name = s;//命令名字
        while(s != NULL)
        {
            myargv[i++] = s;
            s = strtok(NULL,"");
        }


        if(cmd_name==NULL)
        {
            continue;
        }
        if(strcmp(cmd_name,"cd")==0)
        {
            
        }
        else if(strcmp(cmd_name,"exit")==0)
        {
            break;
        }
        else
        {
            pid_t pid = fork();
            if(pid==-1)
        {
            perror("execl error");
            continue;
        }
        if(pid == 0)
        {
            execvp(cmd_name,myargv);
            perror("execvp error");
            exit(0);
        }
        wait(NULL);
}
    }
}
