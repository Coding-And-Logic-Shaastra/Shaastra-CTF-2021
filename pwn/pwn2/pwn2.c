# to compile gcc -O0 -fno-stack-protector pwn2.c -o pwn2 -m32

#include <stdio.h>
#include <stdlib.h>

void dummy()
{
    printf("This is a dummy function!\n");
}

void print_flag()
{
    printf("You have come to a new place!\n");
    FILE* fp = fopen("flag.txt", "r");
    char ch;
    while((ch = getc(fp)) != EOF)
        printf("%c",ch);
    printf("\n");
}

void noob()
{
    printf("This is a noob function!\n");
}

void select_func(char* inp)
{
    void (*func)();
    func = &dummy;
    char buf[30];
    strncpy(buf, inp, 31);
    if(strcmp(buf,"noob") == 0)
        func = &noob;
    (*func)();
}

int main()
{
    setvbuf(stdout,_IONBF,0,0);
    printf("If you know the functions, call one!\n");
    char inp[31];
    gets(inp);
    select_func(inp);
}
