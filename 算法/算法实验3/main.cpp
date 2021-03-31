#include <iostream>
#include <stdio.h>
#define MAX 100

using namespace std;
int root[MAX][MAX];
double e[MAX][MAX],w[MAX][MAX],p[MAX],q[MAX];

//�������Ŷ���������
void OPTIMAL_BST(int n){
	int i=0,j=0;
	for(i=1;i<=n+1;i++){
		e[i][i-1]=q[i-1];
		w[i][i-1]=q[i-1];
	}
	for(int cnt=1;cnt<=n;cnt++){
		for(i=1;i<=n-cnt+1;i++){
			j=i+cnt-1;
			e[i][j]=n;
			w[i][j]=w[i][j-1]+p[i]+q[j];
			for(int dnt=i;dnt<=j;dnt++){
				double m=0;
				m=e[i][dnt-1]+e[dnt+1][j]+w[i][j];
				if(m<e[i][j]){
					e[i][j]=m;
					root[i][j]=dnt;
				}
			}
		}
	}
} 

//������Ŷ��������� 
void CONSTRUCT_OPTIMAL_BST(int i,int j){
    int r=root[i][j];
    //������ΪҶ�ӽ��
    if(r<=i)
        cout<<"d"<<r-1<<"Ϊk"<<r<<"������"<<endl;
    else{
        //��������Ҷ�ӽ��
        cout<<"k"<<r-1<<"Ϊk"<<r<<"������"<<endl;
        CONSTRUCT_OPTIMAL_BST(i,r-1);
    }
    //������ΪҶ�ӽ��
    if(r>=j)
        cout<<"d"<<j<<"Ϊk"<<r<<"���Һ���"<<endl;
    else{
        //��������Ҷ�ӽ��
        cout<<"k"<<j<<"Ϊk"<<r<<"���Һ���"<<endl;
        CONSTRUCT_OPTIMAL_BST(r+1,j);
    }
    return;
}
int main(){
    freopen("out.dat","w",stdout);
    freopen("in.dat","r",stdin);
    int m=0;
    cin>>m;
    for(int i=0;i<=m;i++){
    	cin>>p[i];
	}
	for(int i=0;i<=m;i++){
    	cin>>q[i];
	}
    OPTIMAL_BST(m);
    cout<<"k"<<root[1][m]<<"Ϊ��"<<endl;
    CONSTRUCT_OPTIMAL_BST(1,m);
    return 0;
}
