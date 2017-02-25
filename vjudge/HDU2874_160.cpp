// HDU2874
//http://acm.hdu.edu.cn/showproblem.php?pid=2874


#include <iostream>
#include <string.h>
using namespace std;
const int maxn=20010;
const int maxm=25;
int dp[2*maxn][maxm];
bool vis[maxn];
struct edge
{
    int u,v,w,next;
} e[2*maxn];
int tot,tot2,head[maxn];
int ver[2*maxn],R[maxn],first[maxn];
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
int pre[maxn*2];
int find(int x)
{
    int r=x;
    while(pre[r]!=r)
        r=pre[r];
    int i=x,j;
    while(i!=r)
    {
        j=pre[i];
        pre[i]=r;
        i=j;
    }
    return r;
}
void join(int x,int y)
{
    int fx=find(x);
    int fy=find(y);
    if(fx!=fy)
        pre[fx]=fy;
}
void init()
{
    memset(head,-1,sizeof(head));
    memset(vis,0,sizeof(vis));
    memset(ver,0,sizeof(ver));
    memset(pre,0,sizeof(pre));
    memset(dp,0,sizeof(dp));
    memset(R,0,sizeof(R));
    memset(dis,0,sizeof(dis));
    tot2=0;
}
int main()
{
    ios::sync_with_stdio(false);
    int n,m,c;
    while(cin>>n>>m>>c)
    {
        init();
        for(int i=1; i<=n; i++)
            pre[i]=i;
        for(int i=1; i<=m; i++)
        {
            int u,v,w;
            cin>>u>>v>>w;
            addedge(u,v,w);
            join(u,v);
        }
        for(int i=1; i<=n; i++)
            if(i==pre[i])
            {
                addedge(0,i,0);
            }
        tot=0;
        dfs(0,1);
        ST(2*n-1);
        while(c--)
        {
            int u,v;
            cin>>u>>v;
            if(find(u)!=find(v))
                cout<<"Not connected"<<endl;
            else
            {
                int lca=LCA(u,v);
                cout<<dis[u]+dis[v]-2*dis[lca]<<endl;
            }
        }
    }
    return 0;
}
