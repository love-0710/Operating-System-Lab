#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>

void childProcess(void){
	pid_t pid1;
	pid1 = getpid();
	printf("\n The ID of child is %d \n",pid1);
}

void parentProcess(void){
	pid_t pid = getppid();
	printf("\n The ID of parent is %d\n",pid);
}

void main(){
	pid_t pid;
	pid = fork();
	if(pid<0){
		printf("\n Error in system call");
		exit(0);
	}
	else if(pid==0){
		childProcess();
	}
	else{
		parentProcess();
	}
}
