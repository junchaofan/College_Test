#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/sem.h>
#include <sys/types.h>
#define true 1
#define N 11
int ticket_num=100;

int SemId;
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

void thread(void* str){
	int num=*((int *)str);
	int sum=0;
	while(true){
		P(SemId,0);
		if(ticket_num){
			sum++;
			printf("%2d号售票台 售出1张票,剩余票数:%d\n",num,--ticket_num);
		}else{
			printf("%2d号售票台 售票%d张\n",num,sum);
			V(SemId,0);
			return;
		}
		V(SemId,0);
		usleep(random()%100000+6666);
	}
	return;
}

int main(){
	key_t key=0;
	SemId=semget(key,1,IPC_CREAT|0666);
	if(SemId==-1){
		printf("semget error!\n");
		return 0;
	}
	//设置0信号灯，为1时表示可以执行加法操作
	arg.val=1;
	semctl(SemId,0,SETVAL,arg);
	pthread_t p[N];
	int nums[N];
	for(int i=1;i<=N;i++){
		nums[i-1]=i;
		pthread_create(&p[i-1],NULL,(void *)thread,nums+i-1);
	}
	for(int i=0;i<N;i++){
		pthread_join(p[i],NULL);
	}
	semctl(SemId,0,IPC_RMID,arg);
	return 0;
}
