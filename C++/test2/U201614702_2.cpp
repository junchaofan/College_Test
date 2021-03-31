#include <stdlib.h>
#include <stdio.h>
#define true 1
class STACK{
    int  *const  elems;	//申请内存用于存放栈的元素
    const  int   max;	//栈能存放的最大元素个数
    int   pos;			//栈实际已有元素个数，栈空时pos=0;
public:
STACK(int m);		//初始化栈：最多m个元素
STACK(const STACK&s); //用栈s拷贝初始化栈
int  size ( ) const;		//返回栈的最大元素个数max
int  howMany ( ) const;	//返回栈的实际元素个数pos
int  getelem (int x) const;	//取下标x处的栈元素
STACK& push(int e); 	//将e入栈,并返回栈
STACK& pop(int &e); 	//出栈到e,并返回栈
STACK& assign(const STACK&s); //赋s给栈,并返回被赋值的栈
void print( ) const;		//打印栈
~STACK( );				//销毁栈
};
	
//初始化栈：最多m个元素
STACK::STACK(int m): max(m),elems(new int[m]),pos(0){
	
}

//用栈s拷贝初始化栈
STACK::STACK(const STACK&s): elems(new int[s.size()]),pos(s.howMany()),max(s.size()){
	for(int i=0;i<s.pos;i++){
		this->elems[i]=s.getelem(i);
	}
}
	
//返回栈的最大元素个数max
int  STACK::size ( ) const{
	return max;
}
	
//返回栈的实际元素个数pos
int  STACK::howMany ( ) const{
	return pos;
}
	
//取下标x处的栈元素
int  STACK::getelem (int x) const{
	if (x > pos)
		return -1;
	return elems[x]; 
}
	
//将e入栈,并返回栈
STACK& STACK::push(int e){
	if (max > pos){
		elems[pos]=e;
		pos+=1;
	}
    return *this;
}

//出栈到e,并返回栈
STACK& STACK::pop(int &e){
	if(pos){
		pos-=1;
		e=elems[pos];
	}
        return *this;
}

//赋s给栈,并返回被赋值的栈
STACK& STACK::assign(const STACK&s){
	*(int *)(&max)=s.size();
	*(int **)(&elems)=new int [s.size()];
	pos=s.howMany();
	for(int i=0;i<pos;i++)
		elems[i]=s.getelem(i);
	return *this;
}
	
//打印栈
void STACK::print( ) const{
	for(int i=0;i<pos;i++)
		printf("%d  ",elems[i]);
}
	
//销毁栈
STACK::~STACK( ){
	if(elems){		
		delete elems;
		*(int **)(&elems)=0;
	}
	pos=0;
	*(int *)(&max)=0;
}

int main(int argc, char *argv[]){
	STACK *p=new STACK(10);
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
					p->~STACK();
					p=new STACK(count);
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
						p->push(atoi(argv[i+j]));
						//已完成插入操作，判断是否插入成功
						if (p->getelem(p->howMany()-1)!=atoi(argv[i+j])){
							printf("I  E  ");
							return 0;
						}else
							j+=1;
					}
					printf("I  ");
					p->print();
					break;
				}
				//取出栈元素并打印栈
	    		case 'O':{
					i+=1;
					int k;
	    			count=atoi(argv[i]);
					for(j=0;j<count;j++){
						k=p->howMany();
						p->pop(e);
						if(p->howMany()!=k-1){
							printf("O  E  ");
							return 0;
						}
					}
					printf("O  ");
					p->print();
					break;
	    		}
				//移植到新栈上并打印新栈
	    		case 'A':{
					i+=1;
					count=atoi(argv[i]);
                    STACK* tail=new STACK(*p);
					printf("A  ");
                    p=tail;
					p->print();
					break;
	    		}
				//用当前栈深拷贝构造一个新栈
	    		case 'C':{
	    			i+=1;
					STACK* tail=new STACK(p->size());
					tail->assign(*p);
					//已完成深拷贝操作，判断是否深拷贝成功
					for (int k=0;k<p->howMany();k++){
						if(p->getelem(k)!=tail->getelem(k)){
							printf("C  E  ");
							return 0;
						}
					}
					printf("C  ");
					p=tail;
                    p->print();
                    break;
	    		}
				//栈实际元素个数
	    		case 'N':{
	    			i+=1;
					printf("N  %d  ",p->howMany());
	    			break;
	    		}
				//取某个位置的栈元素
				case 'G':{
					i+=1;
                    e=atoi(argv[i]);
					if(p->getelem(e)==-1){
						printf("G  E  ");
						return 0;
					}else
						printf("G  %d  ",p->getelem(e));
					break;
				}
			}
		}else
			i+=1;
	}
	return 0;
}
