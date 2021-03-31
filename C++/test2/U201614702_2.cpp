#include <stdlib.h>
#include <stdio.h>
#define true 1
class STACK{
    int  *const  elems;	//�����ڴ����ڴ��ջ��Ԫ��
    const  int   max;	//ջ�ܴ�ŵ����Ԫ�ظ���
    int   pos;			//ջʵ������Ԫ�ظ�����ջ��ʱpos=0;
public:
STACK(int m);		//��ʼ��ջ�����m��Ԫ��
STACK(const STACK&s); //��ջs������ʼ��ջ
int  size ( ) const;		//����ջ�����Ԫ�ظ���max
int  howMany ( ) const;	//����ջ��ʵ��Ԫ�ظ���pos
int  getelem (int x) const;	//ȡ�±�x����ջԪ��
STACK& push(int e); 	//��e��ջ,������ջ
STACK& pop(int &e); 	//��ջ��e,������ջ
STACK& assign(const STACK&s); //��s��ջ,�����ر���ֵ��ջ
void print( ) const;		//��ӡջ
~STACK( );				//����ջ
};
	
//��ʼ��ջ�����m��Ԫ��
STACK::STACK(int m): max(m),elems(new int[m]),pos(0){
	
}

//��ջs������ʼ��ջ
STACK::STACK(const STACK&s): elems(new int[s.size()]),pos(s.howMany()),max(s.size()){
	for(int i=0;i<s.pos;i++){
		this->elems[i]=s.getelem(i);
	}
}
	
//����ջ�����Ԫ�ظ���max
int  STACK::size ( ) const{
	return max;
}
	
//����ջ��ʵ��Ԫ�ظ���pos
int  STACK::howMany ( ) const{
	return pos;
}
	
//ȡ�±�x����ջԪ��
int  STACK::getelem (int x) const{
	if (x > pos)
		return -1;
	return elems[x]; 
}
	
//��e��ջ,������ջ
STACK& STACK::push(int e){
	if (max > pos){
		elems[pos]=e;
		pos+=1;
	}
    return *this;
}

//��ջ��e,������ջ
STACK& STACK::pop(int &e){
	if(pos){
		pos-=1;
		e=elems[pos];
	}
        return *this;
}

//��s��ջ,�����ر���ֵ��ջ
STACK& STACK::assign(const STACK&s){
	*(int *)(&max)=s.size();
	*(int **)(&elems)=new int [s.size()];
	pos=s.howMany();
	for(int i=0;i<pos;i++)
		elems[i]=s.getelem(i);
	return *this;
}
	
//��ӡջ
void STACK::print( ) const{
	for(int i=0;i<pos;i++)
		printf("%d  ",elems[i]);
}
	
//����ջ
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
		//�����������ʱ
		if (argv[i][0]=='-'){
			switch(argv[i][1]){
				//��ʼ��ջ
				case 'S':{
					i+=1;
					count=atoi(argv[i]);
					p->~STACK();
					p=new STACK(count);
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
						p->push(atoi(argv[i+j]));
						//����ɲ���������ж��Ƿ����ɹ�
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
				//ȡ��ջԪ�ز���ӡջ
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
				//��ֲ����ջ�ϲ���ӡ��ջ
	    		case 'A':{
					i+=1;
					count=atoi(argv[i]);
                    STACK* tail=new STACK(*p);
					printf("A  ");
                    p=tail;
					p->print();
					break;
	    		}
				//�õ�ǰջ�������һ����ջ
	    		case 'C':{
	    			i+=1;
					STACK* tail=new STACK(p->size());
					tail->assign(*p);
					//���������������ж��Ƿ�����ɹ�
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
				//ջʵ��Ԫ�ظ���
	    		case 'N':{
	    			i+=1;
					printf("N  %d  ",p->howMany());
	    			break;
	    		}
				//ȡĳ��λ�õ�ջԪ��
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
