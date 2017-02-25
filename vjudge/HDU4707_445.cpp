// HDU4707
//http://acm.hdu.edu.cn/showproblem.php?pid=4707


#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
const int maxn=100000+5;
const int INF=0x3f3f3f3f;
struct EdgeNode
{
    int to;
    int w;
    int next;
};
EdgeNode edges[maxn*100];
int N,M;
int head[maxn],edge;
bool vis[maxn];
queue<int>que;
int dis[maxn],cnt[maxn];
void addedge(int u,int v,int c)
{
    edges[edge].w=c;
    edges[edge].to=v;
    edges[edge].next=head[u];
    head[u]=edge++;
}
void init()
{
    memset(head,-1,sizeof(head));
    edge=0;
}
void spfa(int s,int n)
{
    int u;
    for(int i=0; i<=n; i++)
        dis[i]=INF;
    memset(vis,0,sizeof(vis));
    while(!que.empty())
        que.pop();
    que.push(s);
    vis[s]=true;
    dis[s]=0;
    memset(cnt,0,sizeof(cnt));
    cnt[s]=1;
    while(!que.empty())
    {
        u=que.front();
        que.pop();
        vis[u]=false;
        for(int i=head[u]; i!=-1; i=edges[i].next)
        {
            int v=edges[i].to;
            int w=edges[i].w;
            if(dis[v]>dis[u]+w)
            {
                dis[v]=dis[u]+w;
                if(!vis[v])
                {
                    vis[v]=true;
                    que.push(v);
                    //if(++cnt[v]>=n)
                       // return false;
                }
            }
        }
    }
    //return true;
}
int main()
{
    ios::sync_with_stdio(false);
    int T,n,d,x,y;
    cin>>T;
    while(T--)
    {
        init();

        cin>>n>>d;
        for(int i=1;i<=n-1;i++)
        {
            cin>>x>>y;
            addedge(x+1,y+1,1);
            addedge(y+1,x+1,1);
        }


        spfa(1,n);
        long long sum=0;
        for(int i=1;i<=n;i++)
        {
            if(dis[i]>d)
                sum++;
        }
//        for(int i=1;i<n;i++)
//            cout<<dis[i]<<" ";
//        cout<<endl;
        cout<<sum<<endl;
    }
    return 0;
}
