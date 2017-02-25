// POJ1860
//http://poj.org/problem?id=1860


#include <iostream>
#include <stdio.h>
#include <math.h>
#include <queue>
#include <string.h>
using namespace std;
const int INF=0x3f3f3f3f;
const int maxm=2000;
const int maxn=2000;
struct EdgeNode
{
    int to;
    double r;
    double c;
    double w;
    int next;
};
EdgeNode edges[maxm];
int N,M;
int head[maxn],edge;
int cnt[maxn];
bool vis[maxn];
queue<int>que;
double val;
double dis[maxn];
void addedge(int u,int v,double r,double c)
{
    edges[edge].c=c;
    edges[edge].to=v;
    edges[edge].r=r;
    edges[edge].next=head[u];
    head[u]=edge++;
}
void init()
{
    memset(head,-1,sizeof(head));
    edge=0;
}
int spfa(int s,int n)
{
    int u;
    while(!que.empty())
        que.pop();
    for(int i=0; i<=n; i++)
        dis[i]=0;
    memset(vis,0,sizeof(vis));
    memset(cnt,0,sizeof(cnt));
    vis[s]=true;
    dis[s]=val;
    ++cnt[s];
    que.push(s);

    while(!que.empty())
    {
        u=que.front();
        que.pop();
        vis[u]=false;
        for(int i=head[u]; i!=-1; i=edges[i].next)
        {
            int v=edges[i].to;
            double w=(dis[u]-edges[i].c)*edges[i].r-dis[u];
            // cout<<dis[v]<<" "<<dis[u]<<" "<<w<<endl;
            if(dis[v]<dis[u]+w)
            {
                dis[v]=dis[u]+w;
                if(!vis[v])
                {
                    vis[v]=true;
                    que.push(v);
                    if(++cnt[v]>n)
                        return 0;
                }

            }
        }
    }
    return 1;
}
int main()
{
    int n,m,s;
    int a,b;
    double rab,rba,cab,cba;
    while(cin>>n>>m>>s>>val)
    {
        init();
        for(int i=1; i<=m; i++)
        {
            cin>>a>>b>>rab>>cab>>rba>>cba;
            addedge(a,b,rab,cab);
            addedge(b,a,rba,cba);
        }
        int sum=spfa(s,n);
        /*    bool flag=0;
          for(int i=0; i<=n; i++)
          {
              if(dis[i]>val)
              {
                  flag=1;
                  cout<<"YES"<<endl;
                  break;
              }
          }
          if(flag==0)
              cout<<"NO"<<endl;*/
        if(sum==0)
            cout<<"YES"<<endl;
        else
        {
            if(dis[s]>val)
                cout<<"YES"<<endl;
            else  cout<<"NO"<<endl;
        }
    }
    return 0;
}
