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
virtual int  size ( ) const;			//����ջ�����Ԫ�ظ���max
virtual operator int ( ) const;			//����ջ��ʵ��Ԫ�ظ���pos
virtual int operator[ ] (int x) const;	//ȡ�±�x����ջԪ��
virtual STACK& operator<<(int e); 	//��e��ջ,������ջ
virtual STACK& operator>>(int &e);	//��ջ��e,������ջ
virtual STACK& operator=(const STACK&s); //��s��ջ,�����ر���ֵ��ջ
virtual void print( ) const;			//��ӡջ
virtual ~STACK( );					//����ջ
};

//��ʼ��ջ�����m��Ԫ��
STACK::STACK(int m): max(m),elems(new int[m]),pos(0){
}

//��ջs������ʼ��ջ
STACK::STACK(const STACK&s): elems(new int[s.max]),pos(s.pos),max(s.max){
	for(int i=0;i<s.pos;i++){
		elems[i]=s.elems[i];
	}
}

//����ջ�����Ԫ�ظ���max
int  STACK::size( ) const{
	return max;
}

//����ջ��ʵ��Ԫ�ظ���pos
STACK::operator int( ) const{
	return pos;
}

//ȡ�±�x����ջԪ��
int  STACK::operator[](int x) const{
	if (x > pos)
		return -1;
	return elems[x];
}

//��e��ջ,������ջ
STACK& STACK::operator<<(int e){
	if (max > pos){
		elems[pos]=e;
		pos+=1;
	}
    return *this;
}

//��ջ��e,������ջ
STACK& STACK::operator>>(int &e){
	if(pos){
		pos-=1;
		e=elems[pos];
	}
        return *this;
}

//��s��ջ,�����ر���ֵ��ջ
STACK& STACK::operator=(const STACK&s){
	*(int *)(&max)=s.size();
	*(int **)(&elems)=new int [s.size()];
	pos=s.pos;
	for(int i=0;i<pos;i++)
		elems[i]=s.elems[i];
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

class QUEUE: public STACK{
    STACK  s2;
public:
QUEUE(int m); //ÿ��ջ���m��Ԫ�أ�Ҫ��ʵ�ֵĶ����������2m��Ԫ��
QUEUE(const QUEUE&s); 			//�ö���s������ʼ������
virtual operator int ( ) const;			//���ض��е�ʵ��Ԫ�ظ���
virtual int full ( ) const;		       //���ض����Ƿ�������������1�����򷵻�0
virtual int operator[ ](int x)const;   //ȡ�±�Ϊx��Ԫ�أ���1��Ԫ���±�Ϊ0
virtual QUEUE& operator<<(int e);  //��e�����,�����ض���
virtual QUEUE& operator>>(int &e);	//�����е�e,�����ض���
virtual QUEUE& operator=(const QUEUE&s); //��s������,�����ر���ֵ�Ķ���
virtual void print( ) const;			//��ӡ����
virtual ~QUEUE( );					//���ٶ���
};

//ÿ��ջ���m��Ԫ�أ�Ҫ��ʵ�ֵĶ����������2m��Ԫ��
QUEUE::QUEUE(int m):STACK(m),s2(m){}

//�ö���s������ʼ������
QUEUE::QUEUE(const QUEUE&s):STACK(s.STACK::size()),s2(s.s2.size()){
    int i=0;
	for(i=0;i<STACK::operator int();i++)
        STACK::operator <<(STACK::operator[ ](i));
    for(i=0;i<int(s.s2);i++)
        s2<<s.s2[i];
}

//���ض��е�ʵ��Ԫ�ظ���
QUEUE::operator int ( ) const{
	return STACK::operator int()+s2.operator int();
}

//���ض����Ƿ�������������1�����򷵻�0
int QUEUE::full ( ) const{
	if (s2.operator int() && STACK::operator int()==s2.size())
		return 1;
	else
		return 0;
}

//ȡ�±�Ϊx��Ԫ�أ���1��Ԫ���±�Ϊ0
int QUEUE::operator[ ](int x)const{
	int sum=operator int();
	//�±겻�ڶ��г��ȷ�Χ�� 
    if(x >=sum || sum==0)
        return -1;
    else{
        if(x<s2.operator int())
            return s2[s2.operator int()-x-1];
        else
            return STACK::operator[](x-s2.operator int());
    }
}

//��e�����,�����ض���
QUEUE& QUEUE::operator<<(int e){
	//����δ�� 
    if(full()==0){
        if(STACK::operator int()==STACK::size()){
			for(int i=0;i<STACK::size();i++)
			{
				int k=0;
				STACK::operator>>(k);
				s2<<k;
			}
			STACK::operator<<(e);
		}else
		//STACK����δ��
			STACK::operator<<(e);
    }
    return *this;
}

//�����е�e,�����ض���
QUEUE& QUEUE::operator>>(int &e){
	//�����в�Ϊ�� 
   if(operator int()){
   		//��s2��Ϊ�� 
        if(s2.operator int())
            s2>>e;
        else{
        	//��������У��������s2�н�Ԫ��ȡ�� 
            int cnt=STACK::operator int();
            for(int i=0;i<cnt;i++)
			{
				int k=0;
				STACK::operator>>(k);
				s2<<k;
			}
			s2>>e;
        }
    }
    return *this;
}

//��s������,�����ر���ֵ�Ķ���
QUEUE& QUEUE::operator=(const QUEUE&s){
	//this->s2=s.s2;
	this->s2.operator=(s.s2);
    STACK::operator=(s);
    return *this;
}

//��ӡ����
void QUEUE::print( ) const{
	//��s2����Ԫ�� 
    if(s2.operator int()){
        for(int i=s2.operator int()-1;i>=0;i--)
            printf("%d  ",s2[i]);
    }
    //���̳�ջ����Ԫ�� 
    if(STACK::operator int()){
        for(int i=0;i<STACK::operator int();i++)
            printf("%d  ",STACK::operator[ ](i));
    }
}

//���ٶ���
QUEUE::~QUEUE( ){}

//��������1,���򷵻�0
int isPrime(int cnt){
    for(int i=2;i<cnt;i++){
        if(cnt%i==0)
            return 0;
    }
    return 1;
}

//�����������
int howMany(int M,int F,int m,int f){
    if((m==1 && f==1) || m==f)
        return m;
    QUEUE *ManQueue=new QUEUE(M);
    QUEUE *WomanQueue=new QUEUE(F);
    for(int i=1;i<=M;i++){
        if(i!=m)
            *ManQueue<<0;
        else
            *ManQueue<<1;
    }
    for(int i=1;i<=F;i++){
        if(i!=f)
            *WomanQueue<<0;
        else
            *WomanQueue<<1;
    }
    int Mhead=0,Fhead=0,cnt=0;
    while(!Mhead || !Fhead){
        *ManQueue>>Mhead;
        *ManQueue<<Mhead;
        *WomanQueue>>Fhead;
        *WomanQueue<<Fhead;
        cnt+=1;
    }
    return cnt;
}

int main(){
    int M=0,F=0,m=0,f=0,k=0;
    printf("test num:");
    scanf("%d",&k);
    while(k--){
        while(true){
            printf("Please input the count of male queue,   M = ");
            scanf("%d",&M);
            if(isPrime(M))
                break;
            else
                printf("Input Error!\n");
        }
        while(true){
            printf("Please input the count of female queue, F = ");
            scanf("%d",&F);
            if(isPrime(F) && F!=M)
                break;
            else
                printf("Input Error!\n");
        }
        while(true){
            printf("Please input the count of the man,      m = ");
            scanf("%d",&m);
            if(m<=M)
                break;
            else
                printf("Input Error!\n");
        }
        while(true){
            printf("Please input the count of the woman,    f = ");
            scanf("%d",&f);
            if(f<=F)
                break;
            else
                printf("Input Error!\n");
        }
        printf("The answer is %d\n",howMany(M,F,m,f));
    }
    getchar();
	getchar();
	return 0;
}
