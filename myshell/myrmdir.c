
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
          //  if(mkdir(argv[i],0775)==-1)
                if(rmdir(argv[i])==-1)
            {
                //perror("mkdir error");
                perror("rmdir error");
                continue;
            }
        }
            exit(0);
        }

