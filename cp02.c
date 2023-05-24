#include <stdio.h>
//复制内容函数
void copy_file(char* src_file, char* dest_file){
        char c;
        FILE *src, *dest;
        src = fopen(src_file, "r");
        dest = fopen(dest_file, "w");
        while((c = fgetc(src)) != EOF){
                fputc(c, dest);
        }
        fclose(src);
        fclose(dest);
}
//主函数
int main(int argc, char **argv)
{
        //参数检查，如果检查通过，则调用复制内容函数
        if (argc == 3)
        {
                copy_file(argv[1], argv[2]);
        }
        else
        {
                printf("Usage: command source destination\n");
        }
                return 0;
}


