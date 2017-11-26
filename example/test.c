#include <stdio.h>

FILE *fpr=NULL;
FILE *fpw=NULL;
int main(int argc,char *argv[])
{
    char ch='\0';

    if((fpr=fopen(argv[1],"r"))==NULL)
    {
        fprintf(stderr,"%s文件打开错误",argv[1]);
        goto CLOSE_R;
    }
    if((fpw=fopen(argv[2],"w"))==NULL)
    {
        fprintf(stderr,"%s文件打开失败",argv[2]);
        goto CLOSE_W;
    }

    while((ch=fgetc(fpr))!=EOF)
    {
        printf("%c",ch);
        ch-=(*argv[3]);
        fputc(ch,fpw);
    }
CLOSE_W:
    fclose(fpw);
CLOSE_R:
    fclose(fpr);
    return 0;
}