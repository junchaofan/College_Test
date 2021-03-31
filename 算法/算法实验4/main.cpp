#include<iostream>
#include<string.h>
#include<stdio.h>
#define MAX 10
#define NUM_MAX 32767
using namespace std;
int length=0;
//��������ͼȨ�ؾ���D,ǰ������Q
int D[MAX][MAX],Q[MAX][MAX];
void Floyd_Warshall(int n);
void PRINT(int a[MAX][MAX],int i,int j,int result[]);
int main(){
   // freopen("out.dat","w",stdout);
    freopen("in.dat","r",stdin);
    //�����������
    int loop,m=0;
    cin>>loop;
    cout<<loop<<endl;
    //��ÿһ���������
    for(m=0;m<loop;m++){
        int i,j,k,n;
        //���뵱ǰ����������n
        cin>>n;
        cout<<n<<endl;
        //����ǰ�����ݴ������L
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                cin>>D[i][j];
                //��ʾ�����֮��û�б߻���Ϊͬһ�����,��ʱǰ������Ϊ100
                if(D[i][j]==100 || i==j){
                    D[i][j]=NUM_MAX;
                    Q[i][j]=100;
                }
                //Ϊ��ʼǰ������ֵ
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
        //�Ե����ϼ������·��Ȩ�ؾ����ǰ���������
        for(k=0;k<n;k++){
            int judge=0;
			//����������·������
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                cout<<D[i][j]<<' ';
            }
            cout<<endl;
        }
        cout<<endl;
            for(i=0;i<n;i++){
                for(j=0;j<n;j++){
                	//ͬһ��㶨�峤��Ϊ0,ǰ�����Ϊ�� 
                	if(i==j){
            			D[i][j]=0;
						Q[i][j]=100;
						continue;	
					}
					//judge��űȽϽ��,���жϽ�Сֵ�����·���Ƿ���� 
                    judge=D[i][j] > D[i][k]+D[k][j] ? 1:0;
                    //judgeΪ1,�ж�D[i][k]��D[k][j]�Ƿ�Ϊ��ʵ���ڵı� 
                    if(judge){
                        if(D[i][k]<NUM_MAX && D[k][j]<NUM_MAX){
                            D[i][j]=D[i][k]+D[k][j];
                            Q[i][j]=Q[k][j];
                        }else{
                            D[i][j]=NUM_MAX;
                            Q[i][j]=100;
                        }
                    }else{
                    	//judgeΪ0,�ж�D[i][j]�Ƿ�Ϊ��ʵ���ڵı�
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

        //����������·������
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                cout<<D[i][j]<<' ';
            }
            cout<<endl;
        }

        //�������ǰ������
/*     for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                cout<<Q[i][j]<<' ';
            }
            cout<<endl;
        }
*/

        //���õݹ麯��
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                length=0;
                int result[MAX];
                //��ʼ��������� 
                memset(result,0,sizeof(result));
                //����PRINT����,�������result 
                PRINT(Q,i,j,result);
                //�ж�result,�������-1��ʾͬһλ��,�����������ǰ�����·�� 
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

//�������
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
