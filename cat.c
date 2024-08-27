#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/wait.h>
void cat(char* fileName){
	char openCurrentDirectory[1000];
	getcwd(openCurrentDirectory,1000);
	DIR* directory=opendir(openCurrentDirectory);
	struct dirent* files;
	FILE* o;
	char reading;
	if(!directory){
		printf("There is no such directory");
	}
	else{
		while((files=readdir(directory))!=NULL){
			if(strcmp(fileName,files->d_name)==0){
				o=fopen(fileName,"r");
				while(reading!=EOF){
					reading=fgetc(o);
					printf("%c",reading);
//					printf("\n");
				}
			}
				
		}
	}
}
int main(char* argc,char* argument[]){
//	printf("%s",argument[1]);
	cat(argument[1]);
	printf("\n");
}
