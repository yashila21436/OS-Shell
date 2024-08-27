#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/wait.h>
void tellIfDirectory(char* fileName){
	int flag=0;
	char openCurrentDirectory[1000];
	getcwd(openCurrentDirectory,1000);
	DIR* directory=opendir(openCurrentDirectory);
	struct dirent* files;
	if(!directory){
		printf("There is no such directory");
	}
	else{
		while((files=readdir(directory))!=NULL){
			if(strcmp(files->d_name,fileName)==0){
				flag=1;
				printf("There is a file with this name.");
				printf("\n");
				break;
			}
			
		}
	if(flag==0){
	printf("There is no such file.");
	printf("\n");
	}
	}
}
int main(char* argc,char* argv[]){
//	printf("%s",argv[1]);
//	argv[1]="demo.asm";
	tellIfDirectory(argv[1]);
	return 0;
}	
