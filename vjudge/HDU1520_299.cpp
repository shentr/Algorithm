// HDU1520
//http://acm.hdu.edu.cn/showproblem.php?pid=1520


#include <iostream>
#include <string.h>
#include <stdio.h>
//#pragma comment(linker, "/STACK:10240000,10240000")//扩栈
const int maxn=12005;
int n,edge;
bool vis[maxn];
int dp[maxn][2],pre[maxn],head[maxn];
using namespace std;
struct node
{
    int to;
    int next;
};
node edges[maxn];
void init()
{
    memset(vis,0,sizeof(vis));
    memset(dp,0,sizeof(dp));
    memset(pre,0,sizeof(pre));
    memset(head,-1,sizeof(head));
    memset(edges, -1, sizeof(edges));
    edge=0;
}
void addedge(int u,int v)
{
    edges[edge].to=v;
    edges[edge].next=head[u];
    head[u]=edge++;
}
void tree_dp(int x)
{
    vis[x]=1;
    for(int k=head[x]; k!=-1; k=edges[k].next)
    {
        int i=edges[k].to;
        if(!vis[i])
        {
            tree_dp(i);
            dp[x][1]+=dp[i][0];//boss来了，下属没来
            dp[x][0]+=max(dp[i][0],dp[i][1]);//boss没来，下属可能来也可能没来
        }
    }
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        init();
        int a,b,q=0,t=0;
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&dp[i][1]);
            //pre[i]=i;//poj的数据这里有bug，要不然我早就过了，可能会出现不是1到n的数，比如4  1,1,1,1  2，7    5， 2就没法解决，但是我个人认为这个地方应该没问题的，是数据的问题
        }
        while(scanf("%d%d",&a,&b)!=EOF)
        {
            if(a==0||b==0)
                break;
            addedge(a,b);
            addedge(b,a);
            pre[a]=b;
            q=b;
        }
        tree_dp(q);
        printf("%d\n",max(dp[q][0],dp[q][1]));
    }
    return 0;
}
