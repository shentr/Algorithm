// HDU4786
//http://acm.hdu.edu.cn/showproblem.php?pid=4786


#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
using namespace std;
const int maxn=100005;
int n,m,tol;
int pa[maxn<<1];
int data[35];
struct node
{
    int from;
    int to;
    int w;
} edge[maxn*2];
void add(int u0,int v0,int w0)
{
    edge[tol].from=u0;
    edge[tol].to=v0;
    edge[tol++].w=w0;
}
bool cmp1(node a,node b)
{
    return a.w<b.w;
}
bool cmp2(node a,node b)
{
    return a.w>b.w;
}
void make_set()
{
    for(int x=1; x<=n; x++)
        pa[x]=x;
}
int find(int x)
{
    if(x!=pa[x])
        return pa[x]=find(pa[x]);
    return pa[x];
}
int kruskal1()
{
    int ans=0,cnt=1;
    make_set();
    sort(edge+1,edge+tol+1,cmp1);
    for(int i=1; i<=tol; i++)
    {
        int x=find(edge[i].from);
        int y=find(edge[i].to);
        if(x!=y)
        {
            pa[y]=x;
            ans+=edge[i].w;
            cnt++;
        }
        if(cnt==n)
            break;
    }
    if(cnt<n)
        return -1;
    else return ans;
}
int kruskal2()
{
    int ans=0,cnt=1 ;
    make_set();
    sort(edge+1,edge+tol+1,cmp2);
    for(int i=1; i<=tol; i++)
    {
        int x=find(edge[i].from);
        int y=find(edge[i].to);
        if(x!=y)
        {
            pa[y]=x;
            ans+=edge[i].w;
            cnt++;
        }
        if(cnt==n)
            break;
    }
    if(cnt<n) return -1;
    else return ans;
}
int main()
{
    int T,u2=0,v2=0,w2=0;
    int case2=1;
    //cin>>T;
    scanf("%d",&T);
    while(T--)
    {
        tol=1;
        memset(data,0,sizeof(data));
        memset(edge,0,sizeof(edge));
        memset(pa,0,sizeof(pa));
        bool flag=0;
        int sum1=0,sum2=0;
         //cin>>n>>m;
         scanf("%d%d",&n,&m);
        for(int i=1; i<=m; i++)
        {
            //cin>>u2>>v2>>w2;
            scanf("%d%d%d",&u2,&v2,&w2);
            add(u2,v2,w2);
            add(v2,u2,w2);
        }
       //cout<<-2<<endl;
        printf("Case #%d: ",case2++);
        sum1=kruskal1();
        memset(pa,0,sizeof(pa));
        sum2=kruskal2();
        if(sum1==-1||sum2==-1)
        {
            printf("No\n");
            continue;
            //break;
        }
        data[1]=1;
        data[2]=2;
        for(int i=3; i<=23; i++)
            data[i]=data[i-1]+data[i-2];
        for(int i=1; i<=23; i++)
        {
            if(data[i]>=sum1&&data[i]<=sum2)
            {
                flag=1;
                break;
            }
        }
        //printf("Case #%d: ",case2++);

       //bool flag=1;
        if(flag)
            printf("Yes\n");
            else
            {
                printf("No\n");
            }
            //cout<<sum1<<" "<<sum2<<endl;
            //for(int i=1;i<=50;i++)
              //  cout<<data[i]<<endl;
              //  for(int i=0;i<tol;i++)
        //cout<<edge[i].from<<" "<<edge[i].to<<" "<<edge[i].w<<endl;
    }


    return 0;
}
