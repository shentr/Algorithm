// POJ2349
//http://poj.org/problem?id=2349


#include <iostream>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <stdio.h>
using namespace std;
const int maxn=505;
const int INF=0x3f3f3f3f;
bool vis[maxn];
double lowc[maxn],g[maxn];
int pre[maxn];
double Max[maxn][maxn],dis[maxn][maxn];
bool used[maxn][maxn];
double cmp(double a,double b)
{
    return a<b;
}
struct sa
{
    int x,y;
} point[maxn];
double prim(double cost[][maxn],int n)
{
    double ans=0.0;
    memset(vis,false,sizeof(vis));
    memset(Max,0,sizeof(Max));
    memset(used,false,sizeof(used));
    memset(lowc,0,sizeof(lowc));
    memset(g,0,sizeof(g));
    vis[0]=true;
    for(int i=1; i<n; i++)
    {
        lowc[i]=cost[0][i]*1.0;
    }
    lowc[0]=0.0;
    for(int i=1; i<n; i++)
    {
        double minc=INF*1.0;
        int p=-1;
        for(int j=0; j<n; j++)
            if(!vis[j]&&minc>lowc[j])
            {
                minc=lowc[j];
                g[j]=lowc[j];
                p=j;
            }
//        if(minc==INF)
//            return -1;
        ans+=minc;
        vis[p]=true;
        for(int j=0; j<n; j++)
        {
            if(!vis[j]&&lowc[j]>cost[p][j])
            {
                lowc[j]=cost[p][j];
            }
        }
    }
    //cout<<ans<<endl;
    return ans;
}
int main()
{
    int T,n,m;
    cin>>T;
    while(T--)
    {
        cin>>n>>m;
        memset(point,0,sizeof(point));
        memset(dis,0,sizeof(dis));
        for(int i=0;i<m;i++)
            for(int j=0;j<m;j++)
            dis[i][j]=INF*1.0;
        for(int i=0; i<m; i++)
        {
            cin>>point[i].x>>point[i].y;
        }
        for(int i=0; i<m; i++)
            for(int j=i+1; j<m; j++)
            {
                dis[i][j]=sqrt((point[i].x-point[j].x)*(point[i].x-point[j].x)+(point[i].y-point[j].y)*(point[i].y-point[j].y));
                dis[j][i]=dis[i][j];
            }
       double sum=prim(dis,m);
        sort(lowc,lowc+m,cmp);
        printf("%.2f\n",lowc[m-n]);
//        for(int i=0; i<m; i++)
//            cout<<lowc[i]<<" ";
//        for(int i=0; i<m; i++)
//
//        {
//            for(int j=0; j<m; j++)
//            {
//                cout<<dis[i][j]<<" ";
//            }
//            cout<<endl;
//        }
    }
    return 0;
}
/*int main()
{
	int N,m,n,i,j;
	cin>>N;
	while(N--)
	{
		cin>>n>>m;
		for(i=0;i<m;i++)
			for(j=0;j<m;j++)
				dis[i][j]=INF*1.0;
		for(i=0;i<m;i++)
			cin>>point[i].x>>point[i].y;
		for(i=0;i<m;i++)
			for(j=i+1;j<m;j++)
				dis[j][i]=dis[i][j]=sqrt((point[i].x-point[j].x)*(point[i].x-point[j].x)+(point[i].y-point[j].y)*(point[i].y-point[j].y));
			prim(m);
			sort(lowc,lowc+m);
			cout<<fixed<<setprecision(2)<<lowc[m-n-1]<<endl;
	}
	return 0;
}*/
