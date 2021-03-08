#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

struct movie {

	void (*showmovie)();
	char *name;
	
};

struct movie *movielist[10];
int count = 0; 

void printMovieD(struct movie *mov) {
	puts(mov->name);
}

void addMovie() {
	int i ;
	char buf[8];
	int size ;
	
	if(count >= 11){
		puts("List full");
		return ;
	}
	
	for(i = 0 ; i < 10 ; i++) {
		if(!movielist[i]) {
		
			movielist[i] = (struct movie*)malloc(sizeof(struct movie));
			if(!movielist[i]){
				puts("List memory allocation error");
				exit(-1);
			}
			movielist[i]->showmovie = printMovieD;
			
			printf("The movie size is: ");
			read(0,buf,8);
			size = atoi(buf);
			movielist[i]->name = (char *)malloc(size);
			
			if(!movielist[i]->name){
				puts("List memory allocation error");
				exit(-1);
			}
			
			printf("The movie is: ");
			read(0,movielist[i]->name, size);
			puts("Congrats! A new movie added!!");
			count++;
			break;
		}
	}
}

void delMovie() {
	char buf[4];
	int i;
	printf("Index: ");
	read(0,buf,4);
	i = atoi(buf);
	
	if(i < 0 || i >= count) {
		puts("Out of bound!");
		return;
	}
	
	if(movielist[i]) {
		free(movielist[i]->name);
		free(movielist[i]);
		puts("Deleted");
	}
}

void printMovie(){
	char buf[4];
	int i;
	printf("Index: ");
	
	read(0,buf,4);
	
	i = atoi(buf);
	if(i < 0 || i >= count){
		puts("Out of bound!");
		return;
	}
	
	if(movielist[i]){
		movielist[i]->showmovie(movielist[i]);
	}
}

void backdoor(){
    puts("There are enough movies!");
    system("/bin/sh");
}


void menu(){
	puts("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");
	puts(" 1. Add a movie     ");
	puts(" 2. Delete a movie  ");
	puts(" 3. Display name    ");
	puts(" 4. Quit            ");
	puts("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");
	printf("Enter: ");
};

int main(){
    setvbuf(stdout,0,2,0);
    setvbuf(stdout,0,1,0);
    puts("You have access to Cheem's Movie List!");
	char buf[4];
	while(1){
		menu();
		read(0, &buf, 4);
		
		switch(atoi(buf)){
		
			case 1 :
				addMovie();
				break ;
			case 2 :
				delMovie();
				break ;
			case 3 :
				printMovie();
				break ;
			case 4 :
				exit(0);
				break ;
			default :
				puts("Invalid choice");
				break ;
		}
	}
	return 0;
}
