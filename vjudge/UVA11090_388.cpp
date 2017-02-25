// UVA11090
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=11090


#include <iostream>
#include <stdio.h>
#include <queue>
#include <string.h>
using namespace std;
const int INF=0x3f3f3f3f;
const int maxn=100;
struct Edgenode
{
    int to,next;
    double w;
};
Edgenode edges[maxn*maxn];
int n,m;
int head[maxn],cnt[maxn],edge;
bool vis[maxn];

double dis[maxn];
void add(int u,int v,double c)
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
bool spfa(int y)
{
    queue<int>que;
    int u;
    for(int i=0; i<=n; i++)
    {
        dis[i]=INF;
        cnt[i]=0;
        //vis[i]=0;

    }
    dis[y]=0;
    que.push(y);
    memset(vis,0,sizeof(vis));
    vis[y]=1;
    while(!que.empty())
    {
        u=que.front();
        que.pop();
        vis[u]=false;
        for(int i=head[u]; i!=-1; i=edges[i].next)
        {
            int v=edges[i].to;
            double w=edges[i].w;
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

bool check(double x)
{
    bool flag=0;
    for(int i=1; i<=n; i++)
        for(int k=head[i]; k!=-1; k=edges[k].next)
            edges[k].w-=x;
    for(int i=1; i<=n; i++)
    {
        if(!spfa(i))
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
    int t,case2=1;
    int a,b;
    double w,l=INF*1.0,r=0.0,mid=0.0;
    cin>>t;
    while(t--)
    {
        init();
        //cin>>n>>m;
        scanf("%d%d",&n,&m);
        for(int i=1; i<=m; i++)
        {
            //cin>>a>>b>>w;
            scanf("%d%d%lf",&a,&b,&w);
            add(a,b,w);
            l=min(l,w);
            r=max(r,w);
        }
        //cout<<m<<endl;
        printf("Case #%d: ",case2++);
        //if(m==1)
        if(!check(r+1))
            printf("No cycle found.\n");
        else
        {

            double s=1e-8;
            while(r-l>s)
            {
                mid=(r+l)/2.0;
                if(check(mid))
                {
                    r=mid;
                }
                else l=mid;
            }
            printf("%.2lf\n",r);
        }
    }
    return 0;
}
