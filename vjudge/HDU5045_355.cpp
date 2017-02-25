// HDU5045
//http://acm.hdu.edu.cn/showproblem.php?pid=5045


#include<iostream> //78ms  
#include<cstdio>   
#include<queue>  
using namespace std;  
const double inf =0x3f3f3f3f;  
const int maxv=50,maxe=500;  
int head[maxv];double e[maxe][4];int nume=0;  
void inline adde(int i,int j,int c,double w)  
{  
    e[nume][0]=j;e[nume][1]=head[i];head[i]=nume;  
    e[nume][2]=c;e[nume++][3]=w;  
    e[nume][0]=i;e[nume][1]=head[j];head[j]=nume;  
    e[nume][2]=0;e[nume++][3]=-w;  
}  
int n,m;int ss,tt;  
void init()  
{  
    nume=0;  
    for(int i=0;i<=2*n+2;i++)  
         head[i]=-1;  
    ss=0;tt=2*n+1;  
}  
int inq[maxv];double d[maxv];int prv[maxv];int pre[maxv];  
bool spfa(double & sums)  
{  
    for(int i=0;i<=tt;i++)  
    {  
        inq[i]=0;  
        d[i]=inf;  
    }  
    queue<int>q;  
    q.push(ss);  
    inq[ss]=1;  
    d[ss]=0;  
    while(!q.empty())  
    {  
        int cur=q.front();  
        q.pop();  
        inq[cur]=0;  
        for(int j=head[cur];j!=-1;j=e[j][1])  
        {  
            int v=e[j][0];  
            if(d[v]>d[cur]+e[j][3]&&e[j][2]>0)  
            {  
                d[v]=d[cur]+e[j][3];  
                pre[v]=j;  
                prv[v]=cur;  
                if(!inq[v])  
                {  
                    inq[v]=1;  
                    q.push(v);  
                }  
            }  
        }  
    }  
    if(d[tt]==inf)return 0;  
    double minf=inf;  
    int cur=tt;  
    while(cur!=ss)  
    {  
        if(minf>e[pre[cur]][2])  
          minf=e[pre[cur]][2];  
        cur=prv[cur];  
    }  
    cur=tt;  
    while(cur!=ss)  
    {  
        e[pre[cur]][2]-=minf;  
        e[pre[cur]^1][2]+=minf;  
        cur=prv[cur];  
    }  
    sums+=minf*d[tt];  
    return 1;  
}  
double mincost()  
{  
    double sums=0;  
    while(spfa(sums));  
    return sums;  
}  
double a[11][1005];  
int main()  
{  
    int T;  
    scanf("%d",&T);int cnt=1;  
    while(T--)  
    {  
        scanf("%d%d",&n,&m);  
        for(int i=1;i<=n;i++)  
         for(int j=1;j<=m;j++)  
               scanf("%lf",&a[i][j]);  
  
        double sums=0;  
        for(int ii=0;ii<m/n;ii++)  
        {  
            init();  
            for(int i=1;i<=n;i++)  
            {  
                adde(ss,i,1,0);  
                adde(i+n,tt,1,0);  
                for(int j=n+1;j<=n+n;j++)  
                {  
                    adde(i,j,1,-a[i][(j-n)+n*ii]);  
                }  
            }  
            sums+=mincost();  
        }  
        init();  
        for(int i=n+1;i<=n+(m%n);i++)  
           adde(i,tt,1,0);  
        for(int i=1;i<=n;i++)  
        {  
                adde(ss,i,1,0);  
                for(int j=n+1;j<=n+(m%n);j++)  
                {  
                    adde(i,j,1,-a[i][(j-n)+n*(m/n)]);  
                }  
        }  
          sums+=mincost();  
        printf("Case #%d: %.5lf\n",cnt++,-sums);  
    }  
    return 0;  
} 