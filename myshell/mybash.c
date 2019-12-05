

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<assert.h>
#include<sys/types.h>
#include<fcntl.h>
int main(int argc,char*argv[],char*envp[])
{
    while(1)
    {
        char buff[128]={0};
        printf("[stu@localhost ~]$ ");
        fflush(stdout);
        fgets(buff,128,stdin);
        buff[strlen(buff)-1]=0;//'\0',把/n改成0

        if(buff[0]=='\0')
        {
            continue;
        }
        if(strcmp(buff,"exit")==0)
        {
            break;
        }
        pid_t pid = fork();
        assert(pid != -1);
        if(pid==0)
        {
            execlp(buff,buff,(char*)0);
            perror("execl error");
            exit(0);
        }
    }
}
