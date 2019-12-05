
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>
#include<sys/stat.h>

int main(int argc,char*argv[])
{
    if(argc==1)
    {
        printf("no dirent name!\n");
        exit(0);
}
        int i=1;
        for(;i<argc;i++)
        {
                if(unlink(argv[i])==-1)
            {
                
                perror("rm  error");
                continue;
            }
        }
            exit(0);
        }

