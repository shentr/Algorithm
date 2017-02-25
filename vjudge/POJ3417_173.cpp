// POJ3417
//http://poj.org/problem?id=3417


#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
const int maxn=120010;
const int maxm=40;
int dp[2*maxn][maxm];
bool vis[maxn];
struct edge
{
    int u,v,w,next;
} e[2*maxn];
int tot,tot2,head[maxn];
int ver[2*maxn],R[maxn*2],first[maxn];
long long sum[2*maxn];
int dis[maxn];
inline void addedge(int u,int v,int w)
{
    e[tot2].u=u;
    e[tot2].v=v;
    e[tot2].w=w;
    e[tot2].next=head[u];
    head[u]=tot2++;
    e[tot2].u=v;
    e[tot2].v=u;
    e[tot2].w=w;
    e[tot2].next=head[v];
    head[v]=tot2++;
}

void dfs(int u,int dep)
{
    vis[u]=true;
    ver[++tot]=u;
    first[u]=tot;
    R[tot]=dep;
    for(int k=head[u]; k!=-1; k=e[k].next)
    {
        if(!vis[e[k].v])
        {
            int v=e[k].v;
            int w=e[k].w;
            dis[v]=dis[u]+w;
            dfs(v,dep+1);
            ver[++tot]=u;
            R[tot]=dep;
        }
    }
}
void ST(int n)
{
    for(int i=1; i<=n; i++)
        dp[i][0]=i;
    for(int j=1; (1<<j)<=n; j++)
    {
        for(int i=1; i+(1<<j)-1<=n; i++)
        {
            int a=dp[i][j-1];
            int b=dp[i+(1<<(j-1))][j-1];
            dp[i][j]=R[a]<R[b]?a:b;
        }
    }
}
int rmq(int l,int r)
{
    int k=0;
    while((1<<(k+1))<=r-l+1)
        k++;
    int a=dp[l][k];
    int b=dp[r-(1<<k)+1][k];
    return R[a]<R[b]?a:b;
}
int LCA(int u,int v)
{
    int x=first[u];
    int y=first[v];
    if(x>y)
        swap(x,y);
    int res=rmq(x,y);
    return ver[res];
}
void dfs2(int x,int fa)
{
    for(int i=head[x]; i!=-1; i=e[i].next)
    {
        int t=e[i].v;
        if(t==fa)
            continue;
        dfs2(t,x);
        sum[x]+=sum[t];
    }
}
void init()
{
    memset(head,-1,sizeof(head));
    memset(vis,0,sizeof(vis));
    memset(ver,0,sizeof(ver));
    memset(dp,0,sizeof(dp));
    memset(R,0,sizeof(R));
    memset(dis,0,sizeof(dis));
    memset(sum,0,sizeof(sum));
    tot2=0;
}
int main()
{
    int n,m;
    //ios::sync_with_stdio(false);
   // while(cin>>n>>m)
   while(scanf("%d%d",&n,&m)!=EOF)
    {
        init();
        for(int i=1; i<=n-1; i++)
        {
            int u,v,w;
            w=0;
            //cin>>u>>v;
            scanf("%d%d",&u,&v);
            addedge(u,v,w);
        }
        tot=0;
        vis[1]=1;
        dfs(1,1);
        ST(2*n-1);
        for(int i=1;i<=m;i++)
        {
            int u,v;
           // cin>>u>>v;
           scanf("%d%d",&u,&v);
            int lca=LCA(u,v);
            sum[u]++;
            sum[v]++;
            sum[lca]-=2;
        }
        dfs2(1,1);
        long long ans=0;
        for(int i=2; i<=n; i++)
        {
            if(sum[i]==0)
                ans+=m;
            else if(sum[i]==1)
                ans++;
           // else if(sum[i]>=2)
           //     continue;
        }
        //cout<<ans<<endl;
        printf("%lld\n",ans);
    }
    return 0;
}
