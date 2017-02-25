// Aizu2249
//undefined2249


#include <iostream>
#include <stdio.h>
#include <queue>
#include <string.h>
using namespace std;
const int INF=0x3f3f3f3f;
const int maxm=20005;
const int maxn=10005;
struct EdgeNode
{
    int to;
    int w;
    int d;
    int next;
};
EdgeNode edges[maxn*maxn];
int n,m;
int head[maxn],edge;
bool vis[maxn];
queue<int>que;
long long dis[maxn],cost[maxn];
void add(int u,int v,int d,int c)
{
    edges[edge].w=c;
    edges[edge].d=d;
    edges[edge].to=v;
    edges[edge].next=head[u];
    head[u]=edge++;
}
void init()
{
    memset(head,-1,sizeof(head));
    edge=0;
}
int spfa(int n)
{
    int u,sum2=0;
    dis[0]=0;
    cost[0]=0;
    for(int i=1; i<=n; i++)
    {
        dis[i]=INF;
        cost[i]=INF;
    }
    memset(vis,0,sizeof(vis));
    while(!que.empty())
        que.pop();
    que.push(1);
    //sum2++;
    vis[1]=true;
    dis[1]=0;
    cost[1]=0;
    while(!que.empty())
    {
        u=que.front();
        que.pop();
        vis[u]=false;

        for(int i=head[u]; i!=-1; i=edges[i].next)
        {
            int v=edges[i].to;
            int w=edges[i].w;
            int d=edges[i].d;
            if(dis[v]>dis[u]+d)
            {
                dis[v]=dis[u]+d;
                //if(cost[v]>w)
                cost[v]=w;
                if(!vis[v])
                {
                    vis[v]=true;
                    que.push(v);
                }

            }
            else if(dis[v]==dis[u]+d)
            {
                if(cost[v]>w)
                    cost[v]=w;
            }
        }
    }
    for(int i=1;i<=n;i++)
        cost[0]+=cost[i];
        return cost[0];

}
int main()
{
    int u0,v0,d0,c0;
    while(cin>>n>>m)
    {
        init();
        if(n==0&&m==0)
            break;
        int sum=0;
        for(int i=1; i<=m; i++)
        {
            cin>>u0>>v0>>d0>>c0;
            add(u0,v0,d0,c0);
            add(v0,u0,d0,c0);
        }
        //cout<<-1<<endl;
        sum=spfa(n);
        //cout<<-2<<endl;
        cout<<sum<<endl;
        //for(int i=0;i<=n;i++)
            //cout<<cost[i]<<endl;
    }
    return 0;
}
