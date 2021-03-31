#include<iostream>
#include<string.h>
#include<stdio.h>
#define MAX 10
#define NUM_MAX 32767
using namespace std;
int length=0;
//定义有向图权重矩阵D,前驱矩阵Q
int D[MAX][MAX],Q[MAX][MAX];
void Floyd_Warshall(int n);
void PRINT(int a[MAX][MAX],int i,int j,int result[]);
int main(){
   // freopen("out.dat","w",stdout);
    freopen("in.dat","r",stdin);
    //输入测试组数
    int loop,m=0;
    cin>>loop;
    cout<<loop<<endl;
    //对每一组进行运算
    for(m=0;m<loop;m++){
        int i,j,k,n;
        //输入当前组包含结点数n
        cin>>n;
        cout<<n<<endl;
        //将当前组数据存入矩阵L
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                cin>>D[i][j];
                //表示两结点之间没有边或者为同一个结点,此时前驱矩阵为100
                if(D[i][j]==100 || i==j){
                    D[i][j]=NUM_MAX;
                    Q[i][j]=100;
                }
                //为初始前驱矩阵赋值
                else
                    Q[i][j]=i;
            }
        }
        Floyd_Warshall(n);
        for(i=0;i<n;i++){
            memset(D[i],0,n*sizeof(int));
            memset(Q[i],0,n*sizeof(int));
        }
    }
    return 0;
}

void Floyd_Warshall(int n){
    int i,j,k;
        //自底向上计算最短路径权重矩阵和前驱构造矩阵
        for(k=0;k<n;k++){
            int judge=0;
			//输出结点间最短路径长度
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                cout<<D[i][j]<<' ';
            }
            cout<<endl;
        }
        cout<<endl;
            for(i=0;i<n;i++){
                for(j=0;j<n;j++){
                	//同一结点定义长度为0,前驱结点为空 
                	if(i==j){
            			D[i][j]=0;
						Q[i][j]=100;
						continue;	
					}
					//judge存放比较结果,并判断较小值下最短路径是否存在 
                    judge=D[i][j] > D[i][k]+D[k][j] ? 1:0;
                    //judge为1,判断D[i][k]和D[k][j]是否为真实存在的边 
                    if(judge){
                        if(D[i][k]<NUM_MAX && D[k][j]<NUM_MAX){
                            D[i][j]=D[i][k]+D[k][j];
                            Q[i][j]=Q[k][j];
                        }else{
                            D[i][j]=NUM_MAX;
                            Q[i][j]=100;
                        }
                    }else{
                    	//judge为0,判断D[i][j]是否为真实存在的边
                        if(D[i][j]<NUM_MAX){
                            D[i][j]=D[i][j];
                            Q[i][j]=Q[i][j];
                        }else{
                            D[i][j]=NUM_MAX;
                            Q[i][j]=100;
                        }
                    }
                }
            }
        }

        //输出结点间最短路径长度
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                cout<<D[i][j]<<' ';
            }
            cout<<endl;
        }

        //输出结点间前驱矩阵
/*     for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                cout<<Q[i][j]<<' ';
            }
            cout<<endl;
        }
*/

        //调用递归函数
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                length=0;
                int result[MAX];
                //初始化结果数组 
                memset(result,0,sizeof(result));
                //调用PRINT函数,结果返回result 
                PRINT(Q,i,j,result);
                //判断result,若首项返回-1表示同一位置,否则逆序输出前驱结点路径 
                while(length>=0){
                    if(result[length]==-1){
                        cout<<"NULL"<<endl;
                        length--;
                    }
                    else if(length)
                        cout<<result[length--]<<' ';
                    else
                        cout<<result[length--]<<endl;
                }
            }
        }

}

//输出函数
void PRINT(int a[MAX][MAX],int i,int j,int result[MAX]){
    if(i==j)
        result[length]=i+1;
    else if(a[i][j]==100)
        result[length]=-1;
    else{
        result[length++]=j+1;
        PRINT(a,i,a[i][j],result);
    }
}
