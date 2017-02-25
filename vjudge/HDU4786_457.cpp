// HDU4786
//http://acm.hdu.edu.cn/showproblem.php?pid=4786


#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
const int INF=0x3f3f3f3f;
const int MAXN=100005;
const int MAXM=100005*2;
int pa[MAXN];
long long a[30];
int n,m,T,tot=0;
struct node
{
    int u,v,w;
}edge[MAXM];
void addedge(int u,int v,int w)
{
    edge[tot].u=u;
    edge[tot].v=v;
    edge[tot++].w=w;
}
bool cmp(node a,node b)
{
    return a.w<b.w;
}
bool cmp2(node a,node b)
{
    return a.w>b.w;
}
void make_set()
{
    for(int i=1;i<=n;i++)
        pa[i]=i;
}
int Find(int x)
{
    if(x!=pa[x])
       return pa[x]=Find(pa[x]);
       return pa[x];
}
int Kruskal1()
{
    make_set();
    sort(edge,edge+tot,cmp);
    int cnt=0;
    int ans=0;
    for(int i=0;i<tot;i++)
    {
        int u=edge[i].u;
        int v=edge[i].v;
        int w=edge[i].w;
        int t1=Find(u);
        int t2=Find(v);
        if(t1!=t2)
        {
            ans+=w;
            pa[t1]=t2;
            cnt++;
        }
        if(cnt==n-1)
          break;
    }
    if(cnt<n-1)
        return -1;
    else
     return  ans;
}
int Kruskal2()
{
    make_set();
    sort(edge,edge+tot,cmp2);
    int cnt=0;
    int ans=0;
    for(int i=0;i<tot;i++)
    {
        int u=edge[i].u;
        int v=edge[i].v;
        int w=edge[i].w;
        int t1=Find(u);
        int t2=Find(v);
        if(t1!=t2)
        {
            ans+=w;
            pa[t1]=t2;
            cnt++;
        }
        if(cnt==n-1)
          break;
    }
    if(cnt<n-1)
        return -1;
    else
     return  ans;
}
void init()
{
    tot=0;
    memset(a,0,sizeof(a));
    memset(edge,0,sizeof(edge));
    a[1]=1;
    a[2]=2;
    for(int i=3; i<=29; i++)
        a[i]=a[i-1]+a[i-2];
}

int main()
{
    ios::sync_with_stdio(false);
    int u,v,c;
    int cases=0;
     cin>>T;
     while(T--)
     {
         init();
         cin>>n>>m;
         for(int i=1;i<=m;i++)
         {
             cin>>u>>v>>c;
             addedge(u,v,c);
             addedge(v,u,c);
         }
         int sum1=Kruskal1();
         //memset(pa,0,sizeof(pa));
         int sum2=Kruskal2();
         //cout<<sum1<<" "<<sum2<<endl;
         cout<<"Case #"<<++cases<<": ";
         if(sum1==-1||sum2==-1)
         {
             cout<<"No"<<endl;
             continue;
         }
         bool flag=0;
         for(int i=1;i<=29;i++)
         {
             if(a[i]>=sum1&&a[i]<=sum2)
             {
                 flag=1;
             }
         }
         if(!flag)
            cout<<"No"<<endl;
            else   cout<<"Yes"<<endl;
     }
    return 0;
}