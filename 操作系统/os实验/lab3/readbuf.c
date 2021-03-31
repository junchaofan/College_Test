#include "head.h"

int main(){
	int semId,shmId,cnt=0;
	char *data[BUFNUM];
	for(key=key_low;key<key_low+BUFNUM;key++){
		//获取key的共享内存组
		shmId=shmget(key,BUFLENGTH,0666);
		data[cnt++]=(char *)shmat(shmId,NULL,0);
	}
	cnt=shmget(info_key,sizeof(int)*2,0666);
	int *tip=(int *)shmat(cnt,NULL,0);
	int num=BUFLENGTH,read_howmany=0;
	key=sem_key;
	//获取已存在的信号集
	semId=semget(key,3,0666);
	FILE *fp;
	if((fp=fopen("main","r"))==NULL){
		printf("read file open error\n");
		return 0;
	}
	while(true){
		P(semId,0);
		memset(data[read_howmany%BUFNUM],'\0',BUFLENGTH);
		num=fread(data[read_howmany%BUFNUM],sizeof(char),BUFLENGTH,fp);
		printf("buffer block[%d] geting,size:%d\n",read_howmany,num);
		read_howmany+=1;
		V(semId,1);
		if(num!=BUFLENGTH){
			P(semId,2);
			*tip=read_howmany;
			*(tip+1)=num;
			V(semId,2);
			fclose(fp);
			break;
		}
	}
	return 0;
}

