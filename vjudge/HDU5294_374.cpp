// HDU5294
//http://acm.hdu.edu.cn/showproblem.php?pid=5294


#include <iostream>
#include <vector>
#include <string.h>
#include <stdio.h>
#include <queue>
using namespace std;
const int maxn=2005;
const int INF=0x3f3f3f3f;
struct Edge
{
    int v;
    int cost;
    Edge(int _v=0,int _cost=0):v(_v),cost(_cost) {}
};
vector <Edge>E[maxn];
void add(int u,int v,int w)
{
    E[u].push_back(Edge(v,w));
}
bool vis [maxn];
int cnt[maxn];
int dist [maxn];
bool spfa(int start,int n)
{
    memset(vis,false,sizeof(vis));
    for(int i=1; i<=n; i++)
        dist[i]=INF;
    vis[start]=true;
    dist[start]=0;
    queue<int>que;
    while(!que.empty())
        que.pop();
    que.push(start);
    memset(cnt,0,sizeof(cnt));
    cnt[start]=1;
    while(!que.empty())
    {
        int u=que.front();
        que.pop();
        vis[u]=false;
        for(int i=0;i<E[u].size();i++)
        {
            int v=E[u][i].v;
            if(dist[v]>dist[u]+E[u][i].cost)
            {
                dist[v]=dist[u]+E[u][i].cost;
                if(!vis[v])
                {
                    vis[v]=true;
                    que.push(v);
                    if(++cnt[v]>n)
                        return false;
                }
            }
        }
    }
    return true;
}
/////////////////////////////
const int oo=1e9;
const int mm=121111;
const int mn=2999;
int node,src,dest,edge;
int ver[mm],flow[mm],_next[mm];
int head[mn],work[mn],dis[mn],q[mn];
void prepare(int _node,int _src ,int _dest)
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
int u[60005],v[60005],w[60005];
int b[mn][2],dist2[mn];
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=0;i<=n;i++)
            E[i].clear();
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&u[i],&v[i],&w[i]);
            add(u[i],v[i],w[i]);
            add(v[i],u[i],w[i]);
        }
        spfa(1,n);
        memcpy(dist2,dist,sizeof(dist));
        //memset(dist,0,sizeof(dist));
        spfa(n,n);
        int k=0;
        for(int i=0;i<m;i++)
        {
            if(dist2[u[i]]>dist2[v[i]])
                swap(u[i],v[i]);
            if(dist[v[i]]+w[i]+dist2[u[i]]==dist2[n])
            {
                b[k][1]=u[i];
                b[k][0]=v[i];
                k++;
            }
        }
        prepare(n+1,1,n);

        for(int i=0;i<k;i++)
        {
            addedge(b[i][1],b[i][0],1);
        }
        int sum=Dicnic_flow();
        for(int i=0;i<n;i++)
            E[i].clear();
        for(int i=0;i<k;i++)
        {
            add(b[i][1],b[i][0],1);
            add(b[i][0],b[i][1],1);
        }
        spfa(1,n);
        printf("%d %d\n",sum,m-dist[n]);
    }
    return 0;
}
