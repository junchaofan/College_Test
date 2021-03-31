#include <iostream>
#include <stdio.h>
#define MAX 100

using namespace std;
int root[MAX][MAX];
double e[MAX][MAX],w[MAX][MAX],p[MAX],q[MAX];

//生成最优二叉搜索树
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

//输出最优二叉搜索树 
void CONSTRUCT_OPTIMAL_BST(int i,int j){
    int r=root[i][j];
    //左子树为叶子结点
    if(r<=i)
        cout<<"d"<<r-1<<"为k"<<r<<"的左孩子"<<endl;
    else{
        //左子树非叶子结点
        cout<<"k"<<r-1<<"为k"<<r<<"的左孩子"<<endl;
        CONSTRUCT_OPTIMAL_BST(i,r-1);
    }
    //右子树为叶子结点
    if(r>=j)
        cout<<"d"<<j<<"为k"<<r<<"的右孩子"<<endl;
    else{
        //右子树非叶子结点
        cout<<"k"<<j<<"为k"<<r<<"的右孩子"<<endl;
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
    cout<<"k"<<root[1][m]<<"为根"<<endl;
    CONSTRUCT_OPTIMAL_BST(1,m);
    return 0;
}
