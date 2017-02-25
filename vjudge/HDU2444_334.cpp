// HDU2444
//http://acm.hdu.edu.cn/showproblem.php?pid=2444


#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;
const int oo=1e9;
const int mm=131111;
const int mn=999;
int node,src,dest,edge,n,m,a,b;
int ver[mm],flow[mm],_next[mm];
int head[mn],work[mn],dis[mn],q[mn];
vector<int>g[mn];
void prepare(int _node,int _src,int _dest)
{
    node=_node,src=_src,dest=_dest;
    for(int i=0; i<node; i++)
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
    for(i=0; i<node; ++i)
        dis[i]=-1;
    dis[q[r++]=src]=0;
    for(l=0; l<r; ++l)
        for(i=head[u=q[l]]; i>=0; i=_next[i])
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
    for(int &i=work[u],v,tmp; i>=0; i=_next[i])
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
        for(i=0; i<node; i++)
            work[i]=head[i];
        while(delta=Dicnic_dfs(src,oo))
            ret+=delta;
    }
    return ret;
}
int kb[mn];
int judge()
{
    queue<int>que;
    memset(kb,0,sizeof(kb));
    que.push(1);
    kb[1]=1;
    while(!que.empty())
    {
        int c=que.front();
        que.pop();
        for( int i=0;i<g[c].size();i++)
        {
            int t=g[c][i];
            if(kb[t]==0)
            {
                if(kb[c]==1)
                    kb[t]=2;
                else kb[t]=1;
                que.push(t);
            }
            else
            {
                if(kb[c]==1&&kb[t]==1)
                    return -1;
                if(kb[c]==2&&kb[t]==2)
                    return -1;
            }
        }
    }
    return 1;
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
         for(int i=0;i<mn;i++)
            g[i].clear();
        prepare(2*n+2,0,2*n+1);
        for(int i=0; i<m; i++)
        {
            scanf("%d%d",&a,&b);
            addedge(a,b+n,1);
            addedge(b,a+n,1);
            g[a].push_back(b);
        }
       for(int i=1; i<=n; i++)
        {
            addedge(0,i,1);
        }
        for(int i=n+1; i<=2*n; i++)
            addedge(i,2*n+1,1);
        int ans=judge();
        if(ans==-1)
            printf("No\n");
        else
         printf("%d\n",Dicnic_flow()/2);
    }
    return 0;
}
