// POJ3159
//http://poj.org/problem?id=3159


/*题意：flymouse是幼稚园班上的班长，
一天老师给小朋友们买了一堆的糖果，
由flymouse来分发。flymouse希望自己
分得的糖果数尽量多于snoopy。对于其他
小朋友而言，则必须自己得到的糖果不少
于班上某某，给出m个这种约束关系（u，v, w）
即同学u的糖果数不能比同学v的糖果数少w。
问flymouse最多能多snoopy几个糖果。
*/
#include <iostream>
#include <queue>
#include <string.h>
#include <stdio.h>
using namespace std;
const int INF=0x3f3f3f3f;
const int maxm=150005;
const int maxn=30005;
struct EdgeNode
{
    int to,w,next;
};
EdgeNode edges[maxm];
int N,M;
int head[maxn],edge;
bool vis[maxn];
queue<int>que;
int dis[maxn];
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
bool spfa(int s,int n)
{
    int stack[maxn],outque[maxn],top=0;
    memset(vis,0,sizeof(vis));
    memset(outque,0,sizeof(outque));
    for(int i=0;i<=n;i++)
        dis[i]=INF;
    stack[top++]=s;
    vis[s]=1;
    dis[s]=0;
    while(top)
    {
        int tmp=stack[--top];
        vis[tmp]=0;
        outque[tmp]++;
        if(outque[tmp]>n)
            return 0;//判断负环，这里当然没有必要写它
        int k=head[tmp];
        while(k>-1)
        {
              if(dis[edges[k].to]>edges[k].w+dis[tmp])
            {
                dis[edges[k].to]=edges[k].w+dis[tmp];
                if(vis[edges[k].to]==0)
                {
                    vis[edges[k].to]=1;
                    stack[top++]=edges[k].to;
                }
            }
            k=edges[k].next;
        }
    }
    return 1;
}
/*void spfa(int s,int n)
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
                }
            }
        }
    }
}*/
int main()
{
    //ios::sync_with_stdio(false);
    int n,m,u,v,w;
   // while(cin>>n>>m)
   while(scanf("%d%d",&n,&m)!=EOF)
    {
        init();
        for(int i=1; i<=m; i++)
        {
           // cin>>u>>v>>w
           scanf("%d%d%d",&u,&v,&w);
            addedge(u,v,w);
        }
        spfa(1,n);
        //cout<<dis[n]<<endl;
        printf("%d\n",dis[n]);
    }
    return 0;
}
