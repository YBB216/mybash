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
    char buff[256]={0};
    getcwd(buff,256);
    printf("%s\n",buff);
}
