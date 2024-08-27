#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
void monthRet(int monthNumber){
	char* month[]={"Jan","Feb","March","April","May","June","July","Aug","Sep","Oct","Nov","Dec"};
	if(monthNumber==1){
		printf("%s",month[0]);
	}
	else if(monthNumber==2){
		printf("%s",month[1]);
	}
	else if(monthNumber==3){
		printf("%s",month[2]);
	}
	else if(monthNumber==4){
		printf("%s",month[3]);
	}
	else if(monthNumber==5){
		printf("%s",month[4]);
	}
	else if(monthNumber==6){
		printf("%s",month[5]);
	}
	else if(monthNumber==7){
		printf("%s",month[6]);
	}
	else if(monthNumber==8){
		printf("%s",month[7]);
	}
	else if(monthNumber==9){
		printf("%s",month[8]);
	}
	else if(monthNumber==10){
		printf("%s",month[9]);
	}
	else if(monthNumber==11){
		printf("%s",month[10]);
	}
	else if(monthNumber==12){
		printf("%s",month[11]);
	}
	else{
		printf("Enter a valid Month number");
	}
		
}
int main(char* argc,char* argument[]){
	int m;
	scanf("%d",&m);
	monthRet(m);
	printf("\n");
	return 0;
}
