#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/wait.h>
#include <sys/stat.h>
#define true 1
#define BUFNUM 10
#define BUFLENGTH 100
#define key_low 100
#define info_key 99
#define sem_key 98
key_t key=1;
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
