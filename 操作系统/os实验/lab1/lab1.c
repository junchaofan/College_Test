#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

pid_t pid1,pid2;

void func1(int sig){
	if(sig==SIGUSR1){
		printf("Child Process 1 is Killed by Parent!\n");
	}
	exit(0);
}

void func2(int sig){
	if(sig==SIGUSR2){
		printf("Child Process 2 is Killed by Parent!\n");
	}
	exit(0);
}

void killall(int sig){
	if(sig==SIGINT){
		kill(pid1,SIGUSR1);
		kill(pid2,SIGUSR2);
	}
	return;
}

int main(){
	//设置计数器
	int cnt=0;
	char buf1[30],buf2[30];
	//创建无名管道
	int pipefd[2];
	if(pipe(pipefd)==-1){
		printf("pipe error!\n");
		return 0;
	}
	//创建子进程
	while((pid1=fork())==-1){
		printf("fork1 error!\n");
	}
	if(pid1!=0){
		while((pid2=fork())==-1){
		printf("fork2 error!\n");
		}
		if(pid2!=0){
			//设置软中断信号
			signal(SIGINT,killall);
			int p;
			waitpid(pid1,&p,0);
			waitpid(pid2,&p,0);
			close(pipefd[0]);
			close(pipefd[1]);
			printf("Parent Process is Killed!\n");
			exit(0);
		}else{
			//设置忽略信号
			signal(SIGINT,SIG_IGN);
			signal(SIGUSR2,func2);
			while(1){
				if(read(pipefd[0],buf1,30)){
					printf("%s\n",buf1);
				}
			}
		}
	}else{
		signal(SIGINT,SIG_IGN);
		signal(SIGUSR1,func1);
		while(1){
			cnt+=1;
			sprintf(buf2,"I send you %d times.",cnt);
			write(pipefd[1],buf2,30);
			sleep(1);
		}
	}
}
