#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/wait.h>
void deleteIFile(char* fileName){
	char openCurrentDirectory[1000];
	getcwd(openCurrentDirectory,1000);
	struct dirent *files;
	DIR* directory=opendir(openCurrentDirectory);
	if(!directory){
		printf("There is no such directory.");
	}
	else{
		while((files=readdir(directory))!=NULL){
			if(strcmp(fileName,files->d_name)==0){
				printf("Do you want to delete this file y/n");
				char c;
				scanf("%c",&c);
				if(c=='y'|| c=='Y'){
					remove(fileName);
					printf("Deleted ");
					printf("\n");
					break;
				}
				else{
					break;
				}

			}
		}
	}
}
int main(char* argc,char* argument[]){
	deleteIFile(argument[1]);
	return 0;
}	
