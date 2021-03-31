#include<iostream>
#include<string.h>
#include<stdio.h>
#define MAX 2000
using namespace std;

//ʵ�ֱȽϲ���
int compare(int a[],int b[]){
    for(int i=max(a[0],b[0]);i>=1;i--){
            if(a[i]>b[i])
                return 1;
            else if(a[i]<b[i])
                return 0;
        }
    return 1;
}

//ʵ���������
void print(int s[],int sign){
    if(s[0]==0){
        cout<<0<<endl;
        return;
    }
    if(sign==1)
        cout<<'-';
    int judge=0;
    for(int i=s[0];i>=1;i--){
        if(s[i]==0){
            judge+=1;
        }else
            break;
    }
    for(int i=s[0]-judge;i>=1;i--){
        cout<<s[i];
    }
    cout<<endl;
}

//ʵ�ּӷ�����
//A,B��Ϊ����
void add_operation(int A[],int B[],int C[]){
    int i=1,j=1,k=1,r=0;
    //r��ʾ��λ
    while(i<=A[0] || j<=B[0] || r){
        int ain = i<=A[0] ? A[i++]:0;
        int bin = j<=B[0] ? B[j++]:0;
        C[k]=ain+bin+r;
        r=C[k]>9 ? 1:0;
        C[k++]%=10;
    }
    C[0]=k-1;
}

//ʵ�ּ�������
//A,B��Ϊ������A>B
void sub_operation(int A[],int B[],int C[]){
     int i=1;
    int r=0,k=1;
    while(i<=A[0]){
        //rΪ1��ʾ��λ
        r=A[i] >= B[i] ? 0:1;
        C[k++]=10*r+A[i]-B[i];
        //��������λ,�����λ�������������λ��λ
        if(r){
            int tip=0,num=i+1;
            while(A[num]==0){
                num+=1;
                tip+=1;
            }
            A[num]-=1;
            while(tip){
                A[i+tip]=9;
                tip-=1;
            }
            i+=1;
            continue;
        }
        A[i]=A[i++]-r;
    }
    for(i=k;i>=1;i--){
        if(C[i]!=0){
            C[0]=i;
            break;
        }
    }
}

//ʵ�ֳ˷�����
//A,B��Ϊ����
void mul_operation(int A[],int B[],int C[]){
    //A[0],B[0]�洢����λ��
    //ͳһ�����λ���������
    int m=max(A[0],B[0]);
    if(m<=2){
        int num=(A[1]+A[2]*10)*(B[1]+B[2]*10);
        C[1]=num%10;
        C[2]=(num/10)%10;
        C[3]=(num/100)%10;
        C[4]=num/1000;
        if(C[4])
            C[0]=4;
        else if(C[3])
            C[0]=3;
        else if(C[2])
            C[0]=2;
        else if(C[1])
            C[0]=1;
        else
            C[0]=0;
        return;
    }
    //lenl�����벿��,lenr����Ұ벿��
    int lenl=m/2,lenr=m-m/2;
    int AC[MAX],BD[MAX],ABCD[MAX];
    //Сд��ĸ�������������ĸߵͲ���,[0]���λ��
    int a[MAX]={0},b[MAX]={0},c[MAX]={0},d[MAX]={0};
    int ba[MAX]={0},cd[MAX]={0},bc[MAX]={0},sum[MAX]={0};
    int i=1,judge=1;
    //judge��ʾ(B-A)(C-D)�ķ���,1Ϊ��,0Ϊ��
    a[0]=c[0]=lenr;
    b[0]=d[0]=lenl;
    for(i=1;i<=m;i++){
        if(i<=lenl){
            b[i]=A[i];
            d[i]=B[i];
        }else{
            a[i-lenl]=A[i];
            c[i-lenl]=B[i];
        }
    }
    //����AC��BD����
    mul_operation(a,c,AC);
    mul_operation(b,d,BD);
    //compare�����Ƚ������ִ�С
    int flag1=compare(a,b);
    int flag2=compare(c,d);
    if(flag1 && flag2) {
        sub_operation(a,b,ba);
        sub_operation(c,d,cd);
        judge=0;
    }else if(flag1 && !flag2){
        sub_operation(a,b,ba);
        sub_operation(d,c,cd);
        judge=1;
    }else if(!flag1 && flag2){
        sub_operation(b,a,ba);
        sub_operation(c,d,cd);
        judge=1;
    }else{
        sub_operation(b,a,ba);
        sub_operation(d,c,cd);
        judge=0;
    }
    add_operation(AC,BD,bc);
    mul_operation(ba,cd,ABCD);
    if(judge){
        add_operation(bc,ABCD,sum);
    }else{
        sub_operation(bc,ABCD,sum);
    }
    //����C[]����
    for(i=AC[0];i>=1;i--){
        AC[2*lenl+i]=AC[i];
    }
    for(i=sum[0];i>=1;i--){
        sum[lenl+i]=sum[i];
    }
    for(i=1;i<=lenl*2;i++){
        AC[i]=0;
        sum[i]=i<=lenl ? 0:sum[i];
    }
    AC[0]+=2*lenl;
    sum[0]+=lenl;
    add_operation(AC,BD,bc);
    add_operation(bc,sum,C);
}

int main()
{
    //sign��ʾ�������,1��ʾΪ��,Ϊ��Ĭ��Ϊ0
    int sign=0,choice=0,goon=4;
    freopen("out.dat","w",stdout);
	freopen("in.dat","r",stdin);
    cin>>goon;
    char ch;
    char s1[MAX],s2[MAX];
    while(goon--){
        cin>>s1;
        cin>>s2;
        cin>>choice;
        int a,b;
        if(s1[0]=='-')
            a=strlen(s1)-1;
        else{
            a=strlen(s1);
            for(int i=a;i>=1;i--)
                s1[i]=s1[i-1];
            s1[0]='+';
        }

        if(s2[0]=='-')
            b=strlen(s2)-1;
        else{
            b=strlen(s2);
            for(int i=b;i>=1;i--)
                s2[i]=s2[i-1];
            s2[0]='+';
        }
        int n=max(a,b);
        int A[MAX]={0};   //A
        int B[MAX]={0};   //B
        int C[MAX*2+1]={0}; //result C
        //����λ���ַ���ǰ��
        for(int i=1,j=n;i<=n;i++,j--){
            A[i]=i>a ? 0:s1[j+a-n]-'0';
            B[i]=i>b ? 0:s2[j+b-n]-'0';
        }
        //A[0]��B[0]�����鳤��,sign�űȽϷ���
        A[0]=a;
        B[0]=b;
        ch=s2[0]=='+' ? '+':'-';
        s2[0]=s1[0];
        //��|A|>=|B|,sign=1;��|B|>|A|,sign=0
        if(a>b)
            sign=1;
        else if(a<b)
            sign=0;
        else
            sign=strcmp(s1,s2)>=0 ? 1:0;
        s2[0]=ch;
        switch(choice){
        //ִ�мӷ�����
            case 1:{
                //ͬ��ʱ
                if(s1[0]==s2[0]){
                    sign=s1[0]=='-' ? 1:0;
                    add_operation(A,B,C);
                }else
                //Ϊ���������:A-,B+,|A|>|B|;A+,B-,|B|>|A|
                if(sign){
                    sub_operation(A,B,C);
                    sign=s1[0]=='-' ? 1:0;
                }else{
                    sub_operation(B,A,C);
                    sign=s1[0]=='-' ? 0:1;
                }
                print(C,sign);
                break;
            }

            case 2:{
                //ͬ��
                if(s1[0]==s2[0]){
                    if(sign){
                        sign=s1[0]=='-' ? 1:0;
                        sub_operation(A,B,C);
                    }else{
                        sign=s1[0]=='-' ? 0:1;
                        sub_operation(B,A,C);
                    }
                }else if(s1[0]=='+'){
                    sign=0;
                    add_operation(A,B,C);
                }else{
                    sign=1;
                    add_operation(A,B,C);
                }
                print(C,sign);
                break;
            }

            case 3:{
                mul_operation(A,B,C);
                sign=s1[0]==s2[0] ? 0:1;
                print(C,sign);
                break;
            }
        }
    }

}
