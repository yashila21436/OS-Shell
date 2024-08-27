#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <dirent.h>
void DeleteIFile(char* fileName){
	struct dirent *files;
	char openCurrentDirectory[1000];
	getcwd(openCurrentDirectory,1000);
	DIR *directory=opendir(openCurrentDirectory);
	if(!directory){
		printf("There is no such directory.");
	}
	else{
		while((files=readdir(directory))!=NULL){
		if(strcmp(fileName,files->d_name)==0){
			remove(fileName);
			printf("Deleted");
			printf("\n");
			break;
	
		}
		else{
			printf("There is no such file");
			printf("\n");
			break;
		}
	}
}
}
int main(char* argc,char* argument[]){
//	argument[1]="test";
//	printf("%s",&argument[1]);
	DeleteIFile(argument[1]);
}	
			 

