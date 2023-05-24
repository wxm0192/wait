#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
 
//#define BUF 1024
#define BUF 1
 
int main( int argc, char* argv[], char* envp[])
{
    int w1 = 0;
    char buf[BUF];
 
//判断执行复制命令是否正确
    if(argc <= 2)
    {
        printf("no file to operate\n");
        return 0;
    }
 
//判断源文件是否存在
    if(access(argv[1], F_OK) < 0)
    {
        printf("Source File '%s' not exist\n", argv[1]);
        return 0;
    }
 
//判断源文件是否可读
    if(access(argv[1], R_OK) < 0)
    {
        printf("Source File '%s' UnReadable\n", argv[1]);
        return 0;
    }
 
//打开源文件，赋予读权限
    int fr = open(argv[1],O_RDONLY);
//打开目标文件，如果没有则创建并赋予读写权限，如果存在则清空文件
    int fw = open(argv[2],O_WRONLY|O_CREAT|O_TRUNC,0666);
 
//从源文件中读数据到buf，再将buf的数据写到目标文件中
    while((w1 = read(fr, buf, sizeof(buf))) != 0)
    {
        write(fw, buf, w1);
    }
 
//释放资源
    close(fr);
    close(fw);
    return 0;
}


