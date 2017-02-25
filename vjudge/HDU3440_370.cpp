// HDU3440
//http://acm.hdu.edu.cn/showproblem.php?pid=3440


#include <iostream>
#include <queue>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;
const int maxn=1010;
const int INF=0x3f3f3f3f;
struct sa
{
    int val;
    int id;
} a[maxn];
int cmp(sa x,sa y)
{
    return x.val<y.val;
}
struct EdgeNode
{
    int to;
    int w;
    int next;
};
EdgeNode edges[maxn*maxn];
int N,M;
int head[maxn],edge;
bool vis[maxn];
queue<int>que;
int dis[maxn],cnt[maxn];
void addedge(int u,int v,int c)
{
    edges[edge].w=c;
    edges[edge].to=v;
    edges[edge].next=head[u];
    head[u]=edge++;
}
void init()
{
    memset(a,0,sizeof(a));
    memset(cnt,0,sizeof(cnt));
    memset(vis,0,sizeof(vis));
    memset(dis,0,sizeof(dis));
    memset(head,-1,sizeof(head));
    edge=0;
}
bool spfa(int s,int n)
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
    memset(cnt,0,sizeof(cnt));
    cnt[s]=1;
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
                        return false;
                }
            }
        }
    }
    return true;
}
int main()
{
    int T,n,d;
    cin>>T;
    int Case=0;
    while(T--)
    {

        init();
        cin>>n>>d;
        for(int i=1; i<=n; i++)
        {
            cin>>a[i].val;
            a[i].id=i;

        }
        for(int i=1;i<n;i++)
            addedge(i+1,i,-1);
        sort(a+1,a+1+n,cmp);
        for(int i=1; i<n; i++)
        {
            //addedge(i+1,i,-1);
            if(a[i].id<a[i+1].id)
                addedge(a[i].id,a[i+1].id,d);
            else
                addedge(a[i+1].id,a[i].id,d);//只能从一个方向往另一个方向加边
        }
        cout<<"Case "<<++Case<<": ";
        bool flag=1;
        int first, second;

        if(a[1].id<a[n].id)
        {
            first=a[1].id;
            second=a[n].id;

        }

        else
           {
               first=a[n].id;
               second=a[1].id;
           }
           flag=spfa(first,n);
           //cout<<first<<" "<<second<<endl;
        if(flag==false)
            cout<<-1<<endl;
        else
        {
            //if(a[1].id)
            cout<<dis[second]<<endl;
        }
    }
    return 0;
}
