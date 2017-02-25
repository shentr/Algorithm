// POJ3767
//http://poj.org/problem?id=3767


#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
const int maxn=1010;
const int INF=99999999;
struct EdgeNode
{
    int to;
    int w;
    int next;
};
EdgeNode edges[maxn*maxn];
int N,M;
int g[maxn][maxn];
int num[maxn];
int head[maxn],edge;
bool vis[maxn];
queue<int>que;
int dis[maxn],dis1[maxn],dis2[maxn];
void addedge(int u,int v,int c)
{
    edges[edge].w=c;
    edges[edge].to=v;
    edges[edge].next=head[u];
    head[u]=edge++;
}
void init()
{
    memset(dis,0,sizeof(dis));
    memset(dis1,0,sizeof(dis1));
    memset(dis2,0,sizeof(dis2));
    memset(head,-1,sizeof(head));
    memset(g,0,sizeof(g));
    memset(num,0,sizeof(num));
    edge=0;
}
void spfa(int s,int n)
{
    int u;
    for(int i=0; i<=n; i++)
    {
        dis[i]=INF;
    }
    memset(vis,0,sizeof(vis));
    while(!que.empty())
        que.pop();
    que.push(s);
    vis[s]=true;
    dis[s]=0;
    while(!que.empty())
    {
        u=que.front();
        que.pop();
        vis[u]=false;
        if(num[u]!=num[s])
            continue;
        for(int i=head[u]; i!=-1; i=edges[i].next)
        {
            int v=edges[i].to;
            int w=edges[i].w;
            if(dis[v]>dis[u]+w&&num[v]==num[s])
            {
                dis[v]=dis[u]+w;
                if(!vis[v])
                {
                    vis[v]=true;
                    que.push(v);
                }
            }
        }
    }
}
int main()
{
    int x,y,z,n,m;
    while(cin>>n)
    {
        if(n==0)
            break;
        init();
        cin>>m;
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                g[i][j]=INF;
        for(int i=1; i<=m; i++)
        {
            cin>>x>>y>>z;
            addedge(x,y,z);
            addedge(y,x,z);
            g[x][y]=g[y][x]=z;
        }
        for(int i=1; i<=n; i++)
        {
            cin>>num[i];
        }
        spfa(1,n);
        for(int i=1; i<=n; i++)
            dis1[i]=dis[i];
        spfa(2,n);
        for(int i=1; i<=n; i++)
            dis2[i]=dis[i];
        long long sum=INF;
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
            {
                if(dis1[i]+g[i][j]+dis2[j]<sum)
                    sum=dis1[i]+g[i][j]+dis2[j];
                //cout<<sum<<endl;
            }
        if(sum==INF)
            cout<<-1<<endl;
        else
            cout<<sum<<endl;
        /* for(int i=1;i<=n;i++)
         {
             cout<<dis1[i]<<" ";
         }
         cout<<endl;
         for(int i=1;i<=n;i++)
         {
             cout<<dis2[i]<<" ";
         }
         cout<<endl;*/
        //cout<<INF<<endl;
    }
    return 0;
}
