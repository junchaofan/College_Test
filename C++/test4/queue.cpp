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
virtual int  size ( ) const;			//返回栈的最大元素个数max
virtual operator int ( ) const;			//返回栈的实际元素个数pos
virtual int operator[ ] (int x) const;	//取下标x处的栈元素
virtual STACK& operator<<(int e); 	//将e入栈,并返回栈
virtual STACK& operator>>(int &e);	//出栈到e,并返回栈
virtual STACK& operator=(const STACK&s); //赋s给栈,并返回被赋值的栈
virtual void print( ) const;			//打印栈
virtual ~STACK( );					//销毁栈
};

//初始化栈：最多m个元素
STACK::STACK(int m): max(m),elems(new int[m]),pos(0){
}

//用栈s拷贝初始化栈
STACK::STACK(const STACK&s): elems(new int[s.max]),pos(s.pos),max(s.max){
	for(int i=0;i<s.pos;i++){
		elems[i]=s.elems[i];
	}
}

//返回栈的最大元素个数max
int  STACK::size( ) const{
	return max;
}

//返回栈的实际元素个数pos
STACK::operator int( ) const{
	return pos;
}

//取下标x处的栈元素
int  STACK::operator[](int x) const{
	if (x > pos)
		return -1;
	return elems[x];
}

//将e入栈,并返回栈
STACK& STACK::operator<<(int e){
	if (max > pos){
		elems[pos]=e;
		pos+=1;
	}
    return *this;
}

//出栈到e,并返回栈
STACK& STACK::operator>>(int &e){
	if(pos){
		pos-=1;
		e=elems[pos];
	}
        return *this;
}

//赋s给栈,并返回被赋值的栈
STACK& STACK::operator=(const STACK&s){
	*(int *)(&max)=s.size();
	*(int **)(&elems)=new int [s.size()];
	pos=s.pos;
	for(int i=0;i<pos;i++)
		elems[i]=s.elems[i];
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

class QUEUE: public STACK{
    STACK  s2;
public:
QUEUE(int m); //每个栈最多m个元素，要求实现的队列最多能入2m个元素
QUEUE(const QUEUE&s); 			//用队列s拷贝初始化队列
virtual operator int ( ) const;			//返回队列的实际元素个数
virtual int full ( ) const;		       //返回队列是否已满，满返回1，否则返回0
virtual int operator[ ](int x)const;   //取下标为x的元素，第1个元素下标为0
virtual QUEUE& operator<<(int e);  //将e入队列,并返回队列
virtual QUEUE& operator>>(int &e);	//出队列到e,并返回队列
virtual QUEUE& operator=(const QUEUE&s); //赋s给队列,并返回被赋值的队列
virtual void print( ) const;			//打印队列
virtual ~QUEUE( );					//销毁队列
};

//每个栈最多m个元素，要求实现的队列最多能入2m个元素
QUEUE::QUEUE(int m):STACK(m),s2(m){}

//用队列s拷贝初始化队列
QUEUE::QUEUE(const QUEUE&s):STACK(s.STACK::size()),s2(s.s2.size()){
    int i=0;
	for(i=0;i<STACK::operator int();i++)
        STACK::operator <<(STACK::operator[ ](i));
    for(i=0;i<int(s.s2);i++)
        s2<<s.s2[i];
}

//返回队列的实际元素个数
QUEUE::operator int ( ) const{
	return STACK::operator int()+s2.operator int();
}

//返回队列是否已满，满返回1，否则返回0
int QUEUE::full ( ) const{
	if (s2.operator int() && STACK::operator int()==s2.size())
		return 1;
	else
		return 0;
}

//取下标为x的元素，第1个元素下标为0
int QUEUE::operator[ ](int x)const{
	int sum=operator int();
	//下标不在队列长度范围内 
    if(x >=sum || sum==0)
        return -1;
    else{
        if(x<s2.operator int())
            return s2[s2.operator int()-x-1];
        else
            return STACK::operator[](x-s2.operator int());
    }
}

//将e入队列,并返回队列
QUEUE& QUEUE::operator<<(int e){
	//队列未满 
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
		//STACK队列未满
			STACK::operator<<(e);
    }
    return *this;
}

//出队列到e,并返回队列
QUEUE& QUEUE::operator>>(int &e){
	//若队列不为空 
   if(operator int()){
   		//若s2不为空 
        if(s2.operator int())
            s2>>e;
        else{
        	//处理入队列，处理后在s2中将元素取出 
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

//赋s给队列,并返回被赋值的队列
QUEUE& QUEUE::operator=(const QUEUE&s){
	//this->s2=s.s2;
	this->s2.operator=(s.s2);
    STACK::operator=(s);
    return *this;
}

//打印队列
void QUEUE::print( ) const{
	//若s2内有元素 
    if(s2.operator int()){
        for(int i=s2.operator int()-1;i>=0;i--)
            printf("%d  ",s2[i]);
    }
    //若继承栈内有元素 
    if(STACK::operator int()){
        for(int i=0;i<STACK::operator int();i++)
            printf("%d  ",STACK::operator[ ](i));
    }
}

//销毁队列
QUEUE::~QUEUE( ){}

//素数返回1,否则返回0
int isPrime(int cnt){
    for(int i=2;i<cnt;i++){
        if(cnt%i==0)
            return 0;
    }
    return 1;
}

//解决跳舞问题
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
