#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <malloc.h>

int main() {
    char *p=NULL,*q;
    // printf("Address of program break: %p\n",sbrk(0));
    p=(char *)malloc(32);
    // *(p) = 'a';
    q = p + 64;
    brk(q);
    printf("_________________________________\n");
    printf("p: %p\n", p);                                   // 0x555555756260
    printf("Address of program break: %p\n",sbrk(0));       // 0x5555557562a0
    printf("The range is %ld\n",(char *)sbrk(0)-p);         // 64
    free(p);
    p=(char *)malloc(48);
    printf("_________________________________\n");
    printf("p: %p\n",p);                                    // 0x5555557566a0
    printf("Address of program break now: %p\n",sbrk(0));   // 0x5555557562a0
    printf("The range is %ld\n", (char *)sbrk(0) - p);      // -1024
    return 0;
}