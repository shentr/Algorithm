// UVA11478
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=11478


#include <iostream>
#include <stdio.h>
#include <queue>
#include <string.h>
using namespace std;
const int INF=0x3f3f3f3f;
const int maxn=505;
int n,m,l,r,mid;
int head[maxn],cnt[maxn],edge;
bool vis[maxn];
int dis[maxn];
struct Edgenode
{
    int to,next;
    int w;
};
Edgenode edges[maxn*maxn];
void add(int u,int v,int c)
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
    l=1,r=0,mid=0;
}
bool spfa()
{
    queue<int>que;
    int u;
    for(int i=1; i<=n; i++)
    {
        dis[i]=INF;
        cnt[i]=0;
        que.push(i);
    }
    //dis[y]=0;
   // que.push(y);
    memset(vis,0,sizeof(vis));
    //vis[y]=1;
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
                    if(++cnt[v]>=n)
                        return 0;
                }
            }
        }
    }
    return 1;
}
bool check(int x)
{
    bool flag=0;
    for(int i=1; i<=n; i++)
        for(int k=head[i]; k!=-1; k=edges[k].next)
            edges[k].w-=x;
    //for(int i=1; i<=n; i++)
    {
        if(!spfa())//这块是把所有点找一遍，看看能否找到环
            flag=1;
    }
    for(int i=1; i<=n; i++)
        for(int k=head[i]; k!=-1; k=edges[k].next)
        {
            edges[k].w+=x;
        }
    return flag;
}
int main()
{
    int a,b,w;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        init();
        for(int i=1; i<=m; i++)
        {
            scanf("%d%d%d",&a,&b,&w);
            add(a,b,w);
            r=max(r,w);
        }
        if(!check(r+1))//还有这里就是如果我减掉最大值+1，还是不能构成负环，那么就说明无法成环
            printf("Infinite\n");
        else if(check(l))
        {
            printf("No Solution\n");
        }
        /*else
        {
            while(l<r)
            {
                mid=(r+l+1)/2;
                if(check(mid))
                {
                    r=mid-1;
                }
                else l=mid;
            }
            printf("%d\n",l);
        }*/
        else
        {
            while(l<=r)
            {
                mid=(r+l)/2;
                if(check(mid))
                {
                    r=mid-1;
                }
                else l=mid+1;
            }
            printf("%d\n",r);
        }

    }
    return 0;
}
