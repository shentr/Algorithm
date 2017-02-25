// HDU4289
//http://acm.hdu.edu.cn/showproblem.php?pid=4289


#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;
const int oo=1e9;
const int mm=111111;
const int mn=999;
int node,src,dest,edge;
int ver[mm],flow[mm],_next[mm];
int head[mn],work[mn],dis[mn],q[mn];
void prepare(int _node,int _src,int _dest)
{
    node=_node,src=_src,dest=_dest;
    for(int i=0;i<node;++i)
        head[i]=-1;
    edge=0;
}
void addedge(int u,int v,int c)
{
    ver[edge]=v,flow[edge]=c,_next[edge]=head[u],head[u]=edge++;
    ver[edge]=u,flow[edge]=0,_next[edge]=head[v],head[v]=edge++;
}
bool Dicnic_bfs()
{
    int i,u,v,l,r=0;
    for(i=0;i<node;++i)
        dis[i]=-1;
    dis[q[r++]=src]=0;
    for(l=0;l<r;++l)
        for(i=head[u=q[l]];i>=0;i=_next[i])
        if(flow[i]&&dis[v=ver[i]]<0)
    {
        dis[q[r++]=v]=dis[u]+1;
        if(v==dest)
            return 1;
    }
    return 0;
}
int Dicnic_dfs(int u,int exp)
{
    if(u==dest)
        return exp;
    for(int &i=work[u],v,tmp;i>=0;i=_next[i])
        if(flow[i]&&dis[v=ver[i]]==dis[u]+1&&(tmp=Dicnic_dfs(v,min(exp,flow[i])))>0)
    {
        flow[i]-=tmp;
        flow[i^1]+=tmp;
        return tmp;
    }
    return 0;
}
int Dicnic_flow()
{
    int i,ret=0,delta;
    while(Dicnic_bfs())
    {
        for(i=0;i<node;++i)
            work[i]=head[i];
        while(delta=Dicnic_dfs(src,oo))
            ret+=delta;
    }
    return ret;
}
int main()
{
    int n,m,s,d;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        scanf("%d%d",&s,&d);
         prepare(n*2+1,s,d+n);
        /*memset(head,-1,sizeof(head));
        int edge=0;*/
        for(int i=1;i<=n;i++)
        {
            int a;
            scanf("%d",&a);
            addedge(i,i+n,a);
        }
        for(int i=1;i<=m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            addedge(x+n,y,oo);
            addedge(y+n,x,oo);
        }
        printf("%d\n",Dicnic_flow());
    }
    return 0;
}
