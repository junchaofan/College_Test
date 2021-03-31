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
	P(semId,2);
	*tip=0;
	*(tip+1)=BUFLENGTH;
	V(semId,2);
	int write_howmany=0,t1,t2;
	key=sem_key;
	//获取已存在的信号集
	semId=semget(key,3,0666);
	FILE *fp;
	if((fp=fopen("result","w+"))==NULL){
		printf("write file open error\n");
		return 0;
	}
	while(true){
		P(semId,2);
		if(*tip!=0 && *(tip+1)!=BUFLENGTH){
			t1=*tip;
			t2=*(tip+1);
			V(semId,2);
			break;
		}
		V(semId,2);
		P(semId,1);
		fwrite(data[write_howmany%BUFNUM],sizeof(char),BUFLENGTH,fp);
		V(semId,0);
		printf("buffer block[%d] puting,size:%d\n",write_howmany,BUFLENGTH);
		write_howmany+=1;
	}
	while(write_howmany<t1-1){		
		P(semId,1);
		fwrite(data[write_howmany%BUFNUM],sizeof(char),BUFLENGTH,fp);
		V(semId,0);
		printf("buffer block[%d] puting,size:%d\n",write_howmany,BUFLENGTH);
		write_howmany+=1;
	}
	if(t2!=0){
		P(semId,1);
		fwrite(data[write_howmany%BUFNUM],sizeof(char),t2,fp);
		V(semId,0);
		printf("buffer block[%d] puting,size:%d\n",write_howmany,t2);
	}
	fclose(fp);
	return 0;
}
