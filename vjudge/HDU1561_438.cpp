// HDU1561
//http://acm.hdu.edu.cn/showproblem.php?pid=1561


#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
int n,m,edge,a;
const int maxn=205;
int dp[maxn][maxn];
int head[maxn],val[maxn];
struct node
{
    int to;
    int next;
}tree[maxn];
void init()
{
    memset(dp,0,sizeof(dp));
    memset(head,-1,sizeof(head));
    edge=0;
}
void addedge(int u,int v)
{
    tree[edge].to=v;
    tree[edge].next=head[u];
    head[u]=edge++;
}
void dfs(int u)
{
    dp[u][1]=val[u];
    for(int i=head[u];i!=-1;i=tree[i].next)
    {
        int v=tree[i].to;
        dfs(v);
        for(int j=n;j>=1;j--)
            for(int k=1;k<j;k++)
            dp[u][j]=max(dp[u][j],dp[u][j-k]+dp[v][k]);
    }
}

int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(n==0&&m==0)
            break;
        init();
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d",&a,&val[i]);
            addedge(a,i);
        }
        dfs(0);
        printf("%d\n",dp[0][m+1]);
    }
    return 0;
}
