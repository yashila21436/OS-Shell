#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
void giveDateTime(){
	time_t giveTime;
	time(&giveTime);
	printf(ctime(&giveTime));
}
int main(char* argc,char* argv[]){
	if(argv[1]==NULL){
		giveDateTime();
	}
	return 0;
}
	
	
	
