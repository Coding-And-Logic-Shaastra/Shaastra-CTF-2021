#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char HEADER[] = "!!!!!!!!!!!!!!!!!!!!!!! WELCOME TO LOGIN PORTAL !!!!!!!!!!!!!!!!!!!!!!!\n\n";

const char SECURITY_BREACH[] = "SECURITY BREACH!!!\n";


int main(int argc, char *argv[]) {
    printf("%s", HEADER);
    if (argc != 2) {
        printf("Wrong Format\n");
        printf("Correct Format: %s 'passcode' (without quotes) \n", argv[0]);
        return 1;
    } 
    else {
		char *shift = (char *)malloc(strlen(argv[1]) + 1);
		strcpy(shift, argv[1]);
		for (unsigned long i = 0; i < strlen(shift) ; i++) {
			shift[i] = shift[i] + 1;
		}

		if (!strcmp(shift, "TjoHMfDbFtbS")) {  //SinGLeCaEsaR
			printf("Correct!\n");
			printf("Welcome back!\n");
			printf( "ShaastraCTF{%s}\n", shift);
		} 
		else {
			printf("%s", SECURITY_BREACH);
			printf("Incorrect passcode\n");
		}
	}
    return 1;
}
