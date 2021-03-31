#include <stdio.h>
#include <stdlib.h>
#define true 1
struct STACK{
	int *elems;
	int max;
	int pos;
};
void initSTACK(STACK *const p, int m);	//初始化p指向的栈：最多m个元素
void initSTACK(STACK *const p, const STACK&s); //用栈s初始化p指向的栈
int  size (const STACK *const p);		//返回p指向的栈的最大元素个数max
int  howMany (const STACK *const p);	//返回p指向的栈的实际元素个数pos
int  getelem (const STACK *const p, int x);	//取下标x处的栈元素
STACK *const push(STACK *const p, int e); 	//将e入栈，并返回p
STACK *const pop(STACK *const p, int &e); 	//出栈到e，并返回p
STACK *const assign(STACK*const p, const STACK&s); //赋s给p指的栈,并返回p
void print(const STACK*const p);			//打印p指向的栈
void destroySTACK(STACK*const p);		//销毁p指向的栈	

//初始化p指向的栈：最多m个元素
void initSTACK(STACK *const p, int m){
	p->max=m;
	//动态分配空间
	p->elems=(int *)malloc(sizeof(int)*m);
	p->pos=0;
}
 
//用栈s初始化p指向的栈
void initSTACK(STACK *const p, const STACK&s){
	//深拷贝
	p->max=s.max;
	p->elems=(int *)malloc(sizeof(int)*s.max);
    p->pos=s.pos;
	for (int i=0; i<s.pos; i++){
		p->elems[i]=s.elems[i];
	}
}

//返回p指向的栈的最大元素个数max
int size(const STACK *const p){
	return p->max;
}

//返回p指向的栈的实际元素个数pos
int howMany(const STACK *const p){
	return p->pos;
}

//取下标x处的栈元素
int getelem(const STACK *const p, int x){
	//若栈满，返回-1
	if (x > p->pos)
		return -1;
	return p->elems[x];
}

//将e入栈，并返回p
STACK *const push(STACK *const p, int e){
	//操作成功返回p，否则返回NULL做判断
	if (p->max > p->pos){
		p->elems[p->pos]=e;
		p->pos+=1;
		return p;
	}else
		return NULL;
}

//出栈到e，并返回p
STACK *const pop(STACK *const p, int &e){
	//操作成功返回p，否则返回NULL做判断
	if (p->pos){
		p->pos-=1;
		e=p->elems[p->pos];
		return p;
	}else
		return NULL;
}

//赋s给p指的栈,并返回p			
STACK *const assign(STACK *const p,const STACK &s){
	//深拷贝
	p->max=s.max;
	p->elems=(int *)malloc(sizeof(int)*s.max);
	p->pos=s.pos;
	for (int i=0; i<s.pos; i++)
		p->elems[i]=s.elems[i];
	return p;
}

//打印p指向的栈
void print(const STACK *const p){
	for (int i=0; i<p->pos; i++){
		printf("%d  ",p->elems[i]);
	}
}

//销毁p指向的栈
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
		//遇到命令参数时
		if (argv[i][0]=='-'){
			switch(argv[i][1]){
				//初始化栈
				case 'S':{
					i+=1;
					count=atoi(argv[i]);
					initSTACK(p,count);
					printf("S  %d  ",count);
					break;
				}
				//插入元素并打印栈
				case 'I':{
					i+=1;
					j=0;
					while(true && (i+j < argc)){
						if (argv[i+j][0]=='-')
							break;
						//已完成插入操作，判断是否插入成功
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
                //取出栈元素并打印栈
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
                //移植到新栈上并打印新栈 
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
                //用当前栈深拷贝构造一个新栈 
	    		case 'C':{
	    			i+=1;
					STACK* tail=(STACK *)malloc(sizeof(STACK));
					//已完成深拷贝操作，判断是否深拷贝成功
					if(assign(tail, *p)==NULL){
						printf("C  E  ");
						return 0;
					}else
						printf("C  ");
					p=tail;
                    print(p);
                    break;
	    		}
               //栈实际元素个数 
	    		case 'N':{
	    			i+=1;
	    			printf("N  %d  ",howMany(p));
	    			break;
	    		}
				//取某个位置的栈元素 
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


