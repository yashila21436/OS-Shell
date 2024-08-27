#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <time.h>
int main(){
	int i=1;
	pid_t pid;
	while(i==1){
		printf(">");
	
		char command[1000];
		scanf("%s",&command);
		if(strcmp(command,"exit")==0){
			i=0;
			break;
		}
		else if(strcmp(command,"pwd")==0){
			char openCurrentDirectory[1000];
			getcwd(openCurrentDirectory,1000);
			printf("%s",openCurrentDirectory);
			printf("\n");
		}
		else if(strcmp(command,"echo")==0){
			char input[1000];
			scanf("%s",&input);
			printf(input);
			fgets(input,1000,stdin);
			puts(input);
		}
		else if(strcmp(command,"cd")==0){
			char input[100];
			scanf("%s",&input);
			if(strcmp(input,"..")==0){
				chdir("..");
			}
			else{
				chdir(input);
			}
		}
		else if(strcmp(command,"ls")==0||strcmp(command,"lst")==0){
			int flagOnlyLs=0;
			int flagTell=0;
			char openCurrentDirectory[1000];
			getcwd(openCurrentDirectory,1000);
			//printf("%d",strlen(command));
			if(strlen(command)==2 ){
				flagOnlyLs=1;
			}
			else if(strlen(command)==3 ){
				flagTell=1;
			}
			else{
				printf("The command you have entered is invalid. Please Enter a valid Command");
			}
			//printf("%d",flagTell);
			if(flagOnlyLs==1){
			strcat(openCurrentDirectory,"/ls");
			char *const argument1[]={openCurrentDirectory,NULL};
			pid=fork();
			if(pid==0){
				execv(argument1[0],argument1);			}
			else{
				wait(NULL);
				
			}
			}
			if(flagTell==1){
				strcat(openCurrentDirectory,"/lsTell");
			//	printf("hi");
				char fileName[1000];
				scanf("%s",&fileName);
//				printf("%s",fileName);
				char *const argument1[]={openCurrentDirectory,fileName,NULL};
				pid=fork();
				if(pid==0){
					execv(argument1[0],argument1);
				}
				else{ 
					wait(NULL);
				}
			}
//			if(flagOnlyLs==1){
//				pid=fork();
//				if(pid==0){
//					execv(argument1[0],argument1);
//				}
//				else{
//					wait(NULL);
//					
//				}
//			}
			
			
		
		}
		else if(strcmp(command,"date")==0){
			int flag=0;
			char openCurrentDirectory[1000];
			getcwd(openCurrentDirectory,1000);
			strcat(openCurrentDirectory,"/date");
//			printf("%d",strlen(command));
			if(strlen(command)==4){
				flag=1;
			}
			else{
				printf("Incorrect command ");
				printf("\n");
			}
			if(flag==1){
				char *const argument[]={openCurrentDirectory,NULL};
				pid=fork();
				if(pid==0){
					execv(argument[0],argument);
				}
				else{
					wait(NULL);
				}
			}
		
		}
		else if(strcmp(command,"cat_c")==0){
			int flag=0;
			char fileName[1000];
			scanf("%s",&fileName);
			char openCurrentDirectory[1000];
			getcwd(openCurrentDirectory,1000);
			strcat(openCurrentDirectory,"/cat");
			if(strlen(command)==5){
				flag=1;
			}
			else{
				printf("Incorrect Command");
				printf("\n");
			}
//			printf("%d",flag);
//			printf("%d",strlen(command));
			if(flag==1){
//				printf("hi");
//				printf("%s",fileName);
				char* const argument[]={openCurrentDirectory,fileName,NULL};
				pid=fork();
				if(pid==0){
					execv(argument[0],argument);
				}
				else{
					wait(NULL);
				}
			}
		}
		else if(strcmp(command,"rm-f")==0){
			int flag=0;
			char fileName[1000];
			scanf("%s",&fileName);
//			printf("%d",strlen(command));
			char openCurrentDirectory[1000];
			getcwd(openCurrentDirectory,1000);
			strcat(openCurrentDirectory,"/rm");
			if(strlen(command)==4){
				flag=1;
			}
			else{
				printf("Incorrect Command");
				printf("\n");
			}
			if(flag==1){
				char* const argument[]={openCurrentDirectory,fileName,NULL};
//				printf("%s",fileName);
//				flag=0;
				pid=fork();
				if(pid==0){
					execv(argument[0],argument);
				}
				else{
					wait(NULL);
				}
			}
		}
		else if(strcmp(command,"rm-i")==0){
			int flag=0;
			char openCurrentDirectory[1000];
			getcwd(openCurrentDirectory,1000);
			if(strlen(command)==4){
				flag=1;
			}
			if(flag==1){
				char fileName[1000];
				scanf("%s",&fileName);
				strcat(openCurrentDirectory,"/rm2");
				char* const argument[]={openCurrentDirectory,fileName,NULL};
				pid=fork();
				if(pid==0){
					execv(argument[0],argument);
				}
				else{
					wait(NULL);
				}
			}
		}
			
		else if(strcmp(command,"date-m")==0){
			int flag=0;
			char openCurrentDirectory[1000];
			getcwd(openCurrentDirectory,1000);
			if(strlen(command)==6){
				flag=1;
			}
			if(flag==1){
//				int m;
//				scanf("%s",&m);
				strcat(openCurrentDirectory,"/dateCommand2");
				char* const argument[]={openCurrentDirectory,NULL};
				pid=fork();
				if(pid==0){
					execv(argument[0],argument);
				}
				else{
					wait(NULL);
				}
			}
		}
		else{
			printf("Invalid command");
			printf("\n");
		}
					
			
	}
	
}
//}
