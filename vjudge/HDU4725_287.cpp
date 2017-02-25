// HDU4725
//http://acm.hdu.edu.cn/showproblem.php?pid=4725


#include <iostream>
#include <string.h>
#include <queue>
#include <stdio.h>
using namespace std;
const int INF=0x3f3f3f3f;
const int maxn=200005;
const int maxm=800010;
struct Edge
{
    int to,next,w;
} edge[maxm];
int tot;
int head[maxn];
void init()
{
    tot = 0;
    memset(head,-1,sizeof(head));
}
void addedge(int u,int v,int w)
{
    edge[tot].to=v;
    edge[tot].w=w;
    edge[tot].next=head[u];
    head[u]=tot++;
}
int d[maxn*2];
bool vis[maxn*2];
struct node
{
    int u,w;
    node(int u,int d):u(u),w(d) {}
};
bool operator < (node a,node b)
{
    return a.w > b.w;
}
void  dijk(int s,int n)
{
    memset(vis,0,sizeof(vis));
    priority_queue<node> que;
    for(int i=0; i<=n; i++) d[i]=INF;
    d[s]=0;
    que.push(node(s,0));
    while(!que.empty())
    {
        node tmp = que.top();
        que.pop();
        int u=tmp.u;
        if(vis[u]) continue;
        vis[u]=true;
        for(int e=head[u]; e!=-1; e=edge[e].next)
        {
            int v=edge[e].to,w=edge[e].w;
            if(vis[v]) continue;
            if(d[u]+w<d[v])
            {
                d[v]=d[u]+w;
                que.push(node(v,d[v]));
            }
        }
    }
}
int a[maxn*2];
int main()
{
    //ios::sync_with_stdio(false);
    int T,n,m,t,u,v,w;
    int cases=1;
    scanf("%d",&T);
    //cin>>T;
    while(T--)
    {
        init();
        memset(a,0,sizeof(a));
        memset(d,0,sizeof(d));
        memset(vis,0,sizeof(vis));
        //cin>>n>>m>>t;
        scanf("%d%d%d",&n,&m,&t);
        int val;
        for(int i=1;i<=n;i++)
            {
                //cin>>val;
                scanf("%d",&val);
                a[i]=val;
                vis[val]=1;
            }
            for(int i=1;i<=n;i++)
            {
                if(a[i]==1)
                {
                    addedge(a[i]+n,i,0);
                    if(vis[a[i]+1]&&a[i]<n)
                        addedge(i,a[i]+n+1,t);
                }
                else if(a[i]==n)
                {
                    addedge(a[i]+n,i,0);
                    if(vis[a[i]-1]&&a[i]>1)
                        addedge(i,a[i]+n-1,t);
                }
                else
                {
                    addedge(a[i]+n,i,0);
                    if(vis[a[i]+1]&&a[i]<n)
                        addedge(i,a[i]+n+1,t);
                      if(vis[a[i]-1]&&a[i]>1)
                        addedge(i,a[i]+n-1,t);
                }
            }
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            //cin>>u>>v>>w;
            addedge(u,v,w);
            addedge(v,u,w);
        }
        dijk(1,n*2);
        if(d[n]==INF)
            d[n]=-1;
       // cout<<"Case #"<<cases++<<": ";
        //cout<<d[n]<<endl;
        printf("Case #");
        printf("%d",cases++);
        printf(": ");
        printf("%d\n",d[n]);

    }
    return 0;
}
