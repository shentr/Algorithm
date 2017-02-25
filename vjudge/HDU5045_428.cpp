// HDU5045
//http://acm.hdu.edu.cn/showproblem.php?pid=5045


#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
/*const int mm=66666;
const int mn=5555;
const int oo=1e9;
int src,dest,node,edge;
int ver[mm],flow[mm],_next[mm];
double cost[mm],dis[mn];
int head[mn],p[mn],q[mn];*/
const int oo=1e9;
const int mm=11111;
const int mn=888;
int node,src,dest,edge;
int ver[mm],flow[mm],_next[mm];
double cost[mm],dis[mn];
int head[mn],p[mn],q[mn],vis[mn];

void prepare(int _node,int _src,int _dest)
{
    node=_node,src=_src,dest=_dest;
    for(int i=0; i<node; ++i)head[i]=-1,vis[i]=0;
    edge=0;
}
void addedge(int u,int v,int f,double c)
{
    ver[edge]=v,flow[edge]=f,cost[edge]=c,_next[edge]=head[u],head[u]=edge++;
    ver[edge]=u,flow[edge]=0,cost[edge]=-c,_next[edge]=head[v],head[v]=edge++;
}

bool spfa()
{
    int i,u,v,l,r=0;
    double tmp;
    for(i=0; i<node; ++i)
        dis[i]=oo;
    dis[q[r++]=src]=0;
    p[src]=p[dest]=-1;
    for(l=0; l!=r; (++l>=mn)?l=0:l)
        for(i=head[u=q[l]],vis[u]=0; i>=0; i=_next[i])
            if(flow[i]&&dis[v=ver[i]]>(tmp=dis[u]+cost[i]))
            {
                dis[v]=tmp;
                p[v]=i^1;
                if(vis[v])continue;
                vis[q[r++]=v]=1;
                if(r>=mn)r=0;
            }
    return p[dest]>-1;
}

double spfaflow()
{
    int i,delta;
    double ret=0;
    while(spfa())
    {
        for(i=p[dest],delta=oo; i>=0; i=p[ver[i]])
            if(flow[i^1]<delta)delta=flow[i^1];
        for(i=p[dest]; i>=0; i=p[ver[i]])
            flow[i]+=delta,flow[i^1]-=delta;
        ret+=delta*dis[dest];
    }
    return ret;
}
/*void prepare(int _node,int _src,int _dest)
{
    node=_node,src=_src,dest=_dest;
    for(int i=0;i<node;++i)head[i]=-1;
    edge=0;
}
void addedge(int u,int v,int f,double c)
{
    ver[edge]=v,flow[edge]=f,cost[edge]=c,__next[edge]=head[u],head[u]=edge++;
    ver[edge]=u,flow[edge]=0,cost[edge]=-c,__next[edge]=head[v],head[v]=edge++;
}
bool spfa()
{
    int i,u,v,l,r=0;
    double tmp;
    for(i=0;i<node;++i)dis[i]=oo;
    dis[q[r++]=src]=0;
    p[src]=p[dest]=-1;
    for(l=0;l!=r;(++l==mn)?l=0:l)
        for(i=head[u=q[l]],vis[u]=0;i>=0;i=__next[i])
            if(flow[i]&&dis[v=ver[i]]>(tmp=dis[u]+cost[i]))
            {
                dis[v]=tmp;
                p[v]=i^1;
                if(vis[v])continue;
                vis[q[r++]=v]=1;
                if(r==mn)r=0;
            }
    return p[dest]>-1;
}
double spfaflow()
{
    int delta,i;
    double ret=0;
    while(spfa())
    {
        for(i=p[dest],delta=oo;i>=0;i=p[ver[i]])
            if(flow[i^1]<delta)delta=flow[i^1];
        for(i=p[dest];i>=0;i=p[ver[i]])
            flow[i]+=delta,flow[i^1]-=delta;
        ret+=delta*dis[dest];
    }
    return ret;
}*/
int n,m,T;
double a[15][1005];
/*
int main()
{
    cin>>T;
    int t=1;
    while(T--)
    {
        double sum=0.0;
        cin>>n>>m;
        memset(a,0,sizeof(a));
        for(int i=1; i<=n; i++)
            for(int j=1; j<=m; j++)
            {
                cin>>a[i][j];
            }
        for(int k=0; k<=m/n; k++)
        {
            prepare(2*n+2,0,2*n+1);
            for(int i=1; i<=n; i++)
            {
                addedge(src,i,1,0);
                addedge(i+n,dest,1,0);
                for(int j=1; j<=n; j++)
                    addedge(i,j+n,1,-a[i][j+k*n]);
            }
            sum+=(-spfaflow());
        }
        cout<<"Case #"<<t++<<": ";
        printf("%.5lf\n",sum);

    }
    return 0;
}*/
int main()
{
    int tt=0;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        memset(a,0,sizeof(a));
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                scanf("%lf",&a[i][j]);
        double sum=0;
        for(int k=0;k<=m/n;k++)
        {
            prepare(n*2+2,0,n*2+1);
            for(int i=1;i<=n;i++)
            {
                addedge(src,i,1,0);
                addedge(i+n,dest,1,0);
                for(int j=1;j<=n;j++)
                    addedge(i,j+n,1,-a[i][j+k*n]);
            }
            sum+=(-spfaflow());
        }
        printf("Case #%d: %.5lf\n",++tt,sum);
    }
    return 0;
}

