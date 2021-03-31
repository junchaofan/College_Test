#include <stdio.h>
#include <stdlib.h>
#define true 1
struct STACK{
	int *elems;
	int max;
	int pos;
};
void initSTACK(STACK *const p, int m);	//��ʼ��pָ���ջ�����m��Ԫ��
void initSTACK(STACK *const p, const STACK&s); //��ջs��ʼ��pָ���ջ
int  size (const STACK *const p);		//����pָ���ջ�����Ԫ�ظ���max
int  howMany (const STACK *const p);	//����pָ���ջ��ʵ��Ԫ�ظ���pos
int  getelem (const STACK *const p, int x);	//ȡ�±�x����ջԪ��
STACK *const push(STACK *const p, int e); 	//��e��ջ��������p
STACK *const pop(STACK *const p, int &e); 	//��ջ��e��������p
STACK *const assign(STACK*const p, const STACK&s); //��s��pָ��ջ,������p
void print(const STACK*const p);			//��ӡpָ���ջ
void destroySTACK(STACK*const p);		//����pָ���ջ	

//��ʼ��pָ���ջ�����m��Ԫ��
void initSTACK(STACK *const p, int m){
	p->max=m;
	//��̬����ռ�
	p->elems=(int *)malloc(sizeof(int)*m);
	p->pos=0;
}
 
//��ջs��ʼ��pָ���ջ
void initSTACK(STACK *const p, const STACK&s){
	//���
	p->max=s.max;
	p->elems=(int *)malloc(sizeof(int)*s.max);
    p->pos=s.pos;
	for (int i=0; i<s.pos; i++){
		p->elems[i]=s.elems[i];
	}
}

//����pָ���ջ�����Ԫ�ظ���max
int size(const STACK *const p){
	return p->max;
}

//����pָ���ջ��ʵ��Ԫ�ظ���pos
int howMany(const STACK *const p){
	return p->pos;
}

//ȡ�±�x����ջԪ��
int getelem(const STACK *const p, int x){
	//��ջ��������-1
	if (x > p->pos)
		return -1;
	return p->elems[x];
}

//��e��ջ��������p
STACK *const push(STACK *const p, int e){
	//�����ɹ�����p�����򷵻�NULL���ж�
	if (p->max > p->pos){
		p->elems[p->pos]=e;
		p->pos+=1;
		return p;
	}else
		return NULL;
}

//��ջ��e��������p
STACK *const pop(STACK *const p, int &e){
	//�����ɹ�����p�����򷵻�NULL���ж�
	if (p->pos){
		p->pos-=1;
		e=p->elems[p->pos];
		return p;
	}else
		return NULL;
}

//��s��pָ��ջ,������p			
STACK *const assign(STACK *const p,const STACK &s){
	//���
	p->max=s.max;
	p->elems=(int *)malloc(sizeof(int)*s.max);
	p->pos=s.pos;
	for (int i=0; i<s.pos; i++)
		p->elems[i]=s.elems[i];
	return p;
}

//��ӡpָ���ջ
void print(const STACK *const p){
	for (int i=0; i<p->pos; i++){
		printf("%d  ",p->elems[i]);
	}
}

//����pָ���ջ
void destroySTACK(STACK *const p){
	p->pos=0;
	p->max=0;
	free(p->elems);
	p->elems=NULL;
}

int main(int argc, char *argv[]){
	STACK* p=(STACK *)malloc(sizeof(STACK));
	int e;
	int i=0,j,count;
	while (i<argc){
		//�����������ʱ
		if (argv[i][0]=='-'){
			switch(argv[i][1]){
				//��ʼ��ջ
				case 'S':{
					i+=1;
					count=atoi(argv[i]);
					initSTACK(p,count);
					printf("S  %d  ",count);
					break;
				}
				//����Ԫ�ز���ӡջ
				case 'I':{
					i+=1;
					j=0;
					while(true && (i+j < argc)){
						if (argv[i+j][0]=='-')
							break;
						//����ɲ���������ж��Ƿ����ɹ�
						if (push(p,atoi(argv[i+j]))==NULL){
							printf("I  E  ");
							return 0;
						}else
							j+=1;
					}
					printf("I  ");
					print(p);
					break;
				}
                //ȡ��ջԪ�ز���ӡջ
	    		case 'O':{
					i+=1;
	    			count=atoi(argv[i]);
					for(j=0;j<count;j++){
						if(pop(p,e)==NULL){
							printf("O  E  ");
							return 0;
						}
					}
					printf("O  ");
					print(p);
					break;
	    		}
                //��ֲ����ջ�ϲ���ӡ��ջ 
	    		case 'A':{
					i+=1;
					count=atoi(argv[i]);
                    STACK* tail=(STACK *)malloc(sizeof(STACK));
					initSTACK(tail,*p);
					printf("A  ");
                    p=tail;
					print(p);
					break;
	    		}
                //�õ�ǰջ�������һ����ջ 
	    		case 'C':{
	    			i+=1;
					STACK* tail=(STACK *)malloc(sizeof(STACK));
					//���������������ж��Ƿ�����ɹ�
					if(assign(tail, *p)==NULL){
						printf("C  E  ");
						return 0;
					}else
						printf("C  ");
					p=tail;
                    print(p);
                    break;
	    		}
               //ջʵ��Ԫ�ظ��� 
	    		case 'N':{
	    			i+=1;
	    			printf("N  %d  ",howMany(p));
	    			break;
	    		}
				//ȡĳ��λ�õ�ջԪ�� 
				case 'G':{
					i+=1;
                    e=atoi(argv[i]);
					if(getelem(p,e)==-1){
						printf("G  E  ");
						return 0;
					}else
						printf("G  %d  ",getelem(p,e));
					break;
				}
			}
		}else
			i+=1;
	}
	return 0;
}


