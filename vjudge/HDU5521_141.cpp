// HDU5521
//http://acm.hdu.edu.cn/showproblem.php?pid=5521


#include <iostream>
#include <queue>
#include <algorithm>
#include <string.h>
#include <stdio.h>
#include <math.h>
using namespace std;
const long long INF=pow(10,18);
const int maxm=2111110;
const int maxn=1111110;
struct sa
{
    int num;
    long long ww;
}ans[maxn];
struct EdgeNode
{
    int to;
    int w;
    int next;
};
EdgeNode edges[maxm];
int head[maxn],edge;
bool vis[maxn];
int a[maxn];
int outque[maxn];
queue<int>que;
long long dis[maxn];
long long disx[maxn],disy[maxn];
int T,n,m,t,s;
long long cmp(const sa x,const sa y)
{
    return x.ww<y.ww;
}
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
    for(int i=0; i<=m+n+5; i++)
        dis[i]=INF;
    memset(vis,0,sizeof(vis));
    while(!que.empty())
        que.pop();
    que.push(s);
    vis[s]=true;
    dis[s]=0;
//    memset(cnt,0,sizeof(cnt));
//    cnt[s]=1;
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
}
int top;

int main()
{
    int cases=1;
    scanf("%d",&T);
    while(T--)
    {
        init();
        scanf("%d%d",&n,&m);
        int start=n+1;
        for(int i=1; i<=m; i++)
        {
            scanf("%d%d",&t,&s);
            for(int j=1; j<=s; j++)
            {
                scanf("%d",&a[j]);
                addedge(a[j],start,t);
                addedge(start,a[j],0);
            }
            start++;
        }
        spfa(1,n+1);
        for(int i=1; i<=n; i++)
        {
            disx[i]=dis[i];
        }
        spfa(n,n+1);
        for(int i=1; i<=n; i++)
        {
            disy[i]=dis[i];
        }
       printf("Case #%d: ",cases++);
        if(disx[n]==INF)
        {
          printf("Evil John\n");
            continue;
        }
        long long sum=INF;
        int flag=0;
         for(int i=1; i<=n; i++)
         {
             /*if(disx[i]<disy[i]&&disy[i]!=INF)
             {
                 ans[i].ww=disy[i];
                 ans[i].num=i;
             }
             else if(disx[i]>=disy[i]&&disx[i]!=INF)
             {
                 ans[i].ww=disx[i];
                 ans[i].num=i;
             }*/
             ans[i].ww=max(disx[i],disy[i]);
             if(sum>ans[i].ww)
             {
                 sum=ans[i].ww;
                 flag=i;
             }
             ans[i].num=i;
         }
         //sort(ans+1,ans+n+1,cmp);
        // for(int i=1;i<=n;i++)
           // cout<<ans[i].ww<<endl;
         printf("%I64d\n",sum);
         printf("%d",flag);
         for(int i=1;i<=n;i++)
         {
             if(ans[i].ww==sum&&i!=flag)
                printf(" %d",i);
         }
         printf("\n");
    }
    return 0;
}
