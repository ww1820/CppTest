# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
 
int main(void)
{
     FILE *stream;
     if ((stream = fopen ( "./log.txt" , "a" )) == NULL) //打开文件流
     {
         printf( "error: %d\n" , errno);
         exit (1);
     }
     
     char buf[20]="hello world\n\0";
     
     fputs ( buf , stream);//带缓冲区的写
 
     sleep(20);
 
     return 0;
}

