#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/wait.h>
//void tellIfDirectory(char* fileName){
//	char openCurrentDirectory[1000];
//	getcwd(openCurrentDirectory,1000);
//	DIR* directory=opendir(openCurrentDirectory);
//	struct dirent* files;
//	if(!directory){
//		printf("There is no such directory");
//	}
//	else{
//		while((files=readdir(directory))!=NULL){
//			if(strcmp(files->d_name,fileName)==0){
//				printf("There is a file with this name.");
//			}
//			else{
//				printf("There is no such file or Directory");
//			}
//		}
//	}
//}	
	
void lsFunc(){
	char openCurrentDirectory[1000];
	getcwd(openCurrentDirectory,1000);
	
	struct dirent* files;
	DIR *directory=opendir(openCurrentDirectory);
	if(!directory){
		printf("There is no such Directory. ");
	}
	while((files=readdir(directory))!=NULL){
	
			printf("%s ",files->d_name);
//			printf("\n");
		}
	
	printf("\n");
}
int main(char* argc,char* argument1[]){

	lsFunc();
	
	return 0;
}

