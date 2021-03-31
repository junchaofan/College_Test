#include <iostream>
#include <stdio.h>
#include <cmath>
#include <string.h>
#include <algorithm>


#define MAXNUM 100
using namespace std;

struct point{
    double x,y;
}p[MAXNUM];

//存放结果
int q[MAXNUM]={0};
using namespace std;

//比较横坐标
bool cmpx(point a,point b){
    return a.x < b.x;
}

//比较纵坐标
bool cmpy(int a,int b){
    return p[a].y < p[b].y;
}

double dist(point a,point b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

void print(int low,int high,double k){
    for(int i=low;i<=high;i++)
        for(int j=i+1;j<=high;j++){
            double num=dist(p[i],p[j]);
            if(num==k)
                cout<<p[i].x<<' '<<p[i].y<<' '<<p[j].x<<' '<<p[j].y<<endl;
        }
}

double min_dist_points(int low,int high){
    if(low==high)
        return dist(p[low],p[high]);
    if(low+1==high)
        return dist(p[low],p[high]);
    if(low+2==high){
        double d1=dist(p[low],p[high]);
        double d2=dist(p[low],p[low+1]);
        double d3=dist(p[low+1],p[high]);
        if(d1<=d2 && d1<=d3)
            return d1;
       else if(d2<=d1 && d2<=d3)
            return d2;
       else
            return d3;
    }
    int mid=(low+high)/2;
    double dc=0;
    double dl=min_dist_points(low,mid);
    double dr=min_dist_points(mid+1,high);
    if (dl < dr)
        dc=dl;
    else
        dc=dr;
    int i,k,j;
    for (i=low,k=0;i<high;i++){
        if (p[i].x >= p[mid].x-dc && p[i].x <= p[mid].x+dc)
            q[k++]=i;
    }
    sort(q,q+k,cmpy);
    for (i=0;i<k;i++){
        for (j=i+1;j<k;j++){
            if (p[q[i]].y+dc <= p[q[j]].y)
                break;
            if (dc > dist(p[q[i]],p[q[j]]))
                dc=dist(p[q[i]],p[q[j]]);
        }
    }
    return dc;
}

int main(){
    freopen("in.dat","r",stdin);
    freopen("out.dat","w",stdout);
	int n,num;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>num;
		for(int i=0;i<num;i++){
			cin>>p[i].x;
			cin>>p[i].y;
		}
		double dc=min_dist_points(0,num-1);
		print(0,num-1,dc);
		cout<<endl;
	}
    return 0;
}
