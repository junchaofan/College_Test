#include "head.h"

int main(){
	pid_t pid1,pid2;
	int shmId[BUFNUM],semId,k;
	for(key=key_low;key<key_low+BUFNUM;key++){
		shmId[key-key_low]=shmget(key,BUFLENGTH,IPC_CREAT|0666); //创建共享存储区
	}
	k=shmget(info_key,sizeof(int)*2,IPC_CREAT|0666);
	int *tip=(int *)shmat(k,NULL,0);
	key=sem_key;
	semId=semget(key,3,IPC_CREAT|0666); //创建信号灯
	printf("semId:%d\n",semId);
	if(semId==-1){
		printf("semget error!\n");
		return 0;
	}
	//设置0信号灯，表示缓冲区能写个数
	arg.val=10;
	semctl(semId,0,SETVAL,arg);
	//设置1信号灯，表示缓冲区能读个数
	arg.val=0;
	semctl(semId,1,SETVAL,arg);
	arg.val=1;
	semctl(semId,2,SETVAL,arg);
	//创建子进程
	if((pid1=fork())==-1){
		printf("fork1 error!\n");
		return 0;
	}else
	if(pid1==0){
		//写操作
		printf("writebuf created\n");
		execv("./writebuf",NULL);
	}else{
		if((pid2=fork())==-1){
			printf("fork2 error!\n");
			return 0;
		}else
		if(pid2==0){
			//读操作
			printf("readbuf created\n");
			execv("./readbuf",NULL);
		}else{
			//退出
			int p;
			waitpid(pid1,&p,0);
			waitpid(pid2,&p,0);
			for(int i=0;i<BUFNUM;i++){
				shmctl(shmId[i],IPC_RMID,0);  //撤销共享存储区
			}
			shmctl(k,IPC_RMID,0);
			semctl(semId,0,IPC_RMID);  //删除信号集
			return 0;
		}
	}
}
