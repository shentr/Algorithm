// HDU4324
//http://acm.hdu.edu.cn/showproblem.php?pid=4324


#include <iostream>
#include <string.h>
#include <stdio.h>
#include <queue>
using namespace std;
const int N=2005;
bool vis[N];
int head[N],degree[N];
int q[N],cnt,num;
struct edgenode
{
    int  to,next;
} edge[N*N];
void init()
{
    cnt=0;
    memset(vis,false,sizeof(vis));
    memset(head,-1,sizeof(head));
    memset(degree,0,sizeof(degree));
}
void add(int u,int v)
{
    degree[v]++;
    edge[cnt].to=v;
    edge[cnt].next=head[u];
    head[u]=cnt++;
}
bool topu(int n)
{
    queue<int>q;
  
    num=0;
    for(int i=0; i<n; i++)
    {
        if(!degree[i])
            {
                q.push(i);
                num++;
            }
    }
    while(!q.empty())
    {
        int t=q.front();
        q.pop();
        for(int k=head[t]; k!=-1; k=edge[k].next)
        {
            degree[edge[k].to]--;
            if(!degree[edge[k].to])
                {
                    q.push(edge[k].to);
                    num++;
                }
        }
    }
    return num==n;
}
int main()
{
    int T,n,case2=1;
    scanf("%d",&T);
    char s[2005];
    while(T--)
    {
        bool flag=0;
        scanf("%d",&n);
        init();
        for(int i=0; i<n; i++)
        {
            scanf("%s",s);
            for(int j=0; j<n; j++)
            {
                if(s[j]=='1')
                {
                    add(i,j);
                }
            }
        }
        flag=topu(n);
        if(flag)
        {
            printf("Case #%d: ",case2++);
            printf("No\n");
        }
        else
        {
            printf("Case #%d: ",case2++);
            printf("Yes\n");
        }
    }
    return 0;
}
