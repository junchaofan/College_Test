#include <stdio.h>
#include <pthread.h>
#include <sys/sem.h>
#include <sys/types.h>
int a=0,SemId;
union semum{
	short val; //供SETVAL使用
	struct semid_ds* buf; //semid_ds结构
	unsigned short* array; //SETALL所用数组值
	struct seminfo *_buf; //为控制IPC_INFO提供缓存
}arg;

void P(int semid,int index){
	struct sembuf sem;
	sem.sem_num=index;
	sem.sem_op=-1;
	sem.sem_flg=0;
	semop(semid,&sem,1);
	return;
}

void V(int semid,int index){
	struct sembuf sem;
	sem.sem_num=index;
	sem.sem_op=1;
	sem.sem_flg=0;
	semop(semid,&sem,1);
	return;
}

void subp1(void){
	int i;
	for(i=1;i<=100;i++){
		P(SemId,0);
		printf("OPERATION:ADD(from 1 to %d)\t",i);
		a+=i;
		V(SemId,1);
	}
	return;
}

void subp2(void){
	int i;
	for(i=1;i<=100;i++){
		P(SemId,1);
		printf("RESULT(from 1 to %d):%d\n",i,a);
		V(SemId,0);
	}
	return;
}

int main(){
	//同步，故创建两个信号灯
	key_t key=0;
	SemId=semget(key,2,IPC_CREAT|0666);
	if(SemId==-1){
		printf("semget error!\n");
		return 0;
	}
	//设置0信号灯，为1时表示可以执行加法操作
	arg.val=1;
	semctl(SemId,0,SETVAL,arg);
	//设置1信号灯，为1时表示可以执行打印操作
	arg.val=0;
	semctl(SemId,1,SETVAL,arg);
	pthread_t p1,p2;
	pthread_create(&p1,NULL,(void *)subp1,NULL);
	pthread_create(&p2,NULL,(void *)subp2,NULL);
	pthread_join(p1,NULL);
	pthread_join(p2,NULL);
	semctl(SemId,0,IPC_RMID);
	return 0;
}
