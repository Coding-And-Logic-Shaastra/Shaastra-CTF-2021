#include <stdio.h>

int main() {
    int buff = 0;
    char feed[30];

    setbuf(stdout, NULL);
    setbuf(stdin, NULL);
    setbuf(stderr, NULL);

    puts("WELCOME TO SHAASTRACTF DOG FEEDER!!! FEED ME!!");
    gets(feed);

    puts("I HAVE EATEN!");
    if (buff == 0xcafecafe) {
        puts("I AM FULL");
        system("/bin/cat flag.txt");
    }
    else {
    puts("I NEED MORE FOOD");
    }
}
