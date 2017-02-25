// HDU4081
//http://acm.hdu.edu.cn/showproblem.php?pid=4081


#include <iostream>
#include <math.h>
#include <string.h>
#include <stdio.h>
using namespace std;
const int MAXN=1005;
const int INF=0x3f3f3f3f;
bool vis[MAXN];
double lowc[MAXN];
int pre[MAXN];
double Max[MAXN][MAXN];
bool used[MAXN][MAXN];
double cost [MAXN][MAXN];
struct sa
{
    int x,y,p;
} num[1005];
double Dis(sa a,sa b)
{
    return sqrt((double)(a.x-b.x)*(a.x-b.x)+(double)(a.y-b.y)*(a.y-b.y));
}
/*double max(double m1,double m2)
{
    if(m1>m2)
        return m1;
    return m2;
}*/
double prim(int n)
{
    double ans=0;
    memset(vis,false,sizeof(vis));
    memset(Max,0,sizeof(Max));
    memset(used,false,sizeof(used));
    vis[0]=true;
    pre[0]=-1;
    for(int i=1; i<n; i++)
    {
        lowc[i]=cost[0][i];
        pre[i]=0;
    }
    lowc[0]=0;
    for(int i=1; i<n; i++)
    {
        double minc=INF*1.0;
        int p=-1;
        for(int j=0; j<n; j++)
            if(!vis[j]&&minc>lowc[j])
            {
                minc=lowc[j];
                p=j;
            }
        ans+=minc;
        vis[p]=true;
        used[p][pre[p]]=used[pre[p]][p]=true;
        for(int j=0; j<n; j++)
        {
            if(vis[j]&&j!=p)
                Max[j][p]=Max[p][j]=max(Max[j][pre[p]],lowc[p]);
            if(!vis[j]&&lowc[j]>cost[p][j])
            {
                lowc[j]=cost[p][j];
                pre[j]=p;
            }
        }
    }
    return ans;
}
int main()
{
    int n,t;
    cin>>t;
     //scanf("%d",&t);
    while(t--)
    {
        cin>>n;
        //scanf("%d",&n);
        for(int i=0; i<n; i++)
        {
           //scanf("%d%d%d",&num[i].x,&num[i].y,&num[i].p);
            cin>>num[i].x>>num[i].y>>num[i].p;
        }
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                //if(i==j)
                   // cost[i][j]=0;
                cost[i][j]=cost[j][i]=Dis(num[i],num[j]);
            }
        }
        double dis=prim(n);
       // cout<<dis<<endl;
        double sum=-1;
        for(int i=0; i<n; i++)
            for(int j=i+1; j<n; j++)
            {
                if(used[i][j])
                    sum=max(sum,1.0*(num[i].p+num[j].p)/(dis-cost[i][j]));
                else
                    sum=max(sum,1.0*(num[i].p+num[j].p)/(dis-Max[i][j]));
            }
        printf("%.2f\n",sum);
    }
    return 0;
}
