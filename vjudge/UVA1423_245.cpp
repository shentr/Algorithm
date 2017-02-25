// UVA1423
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1423


#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
bool vis[205];
int head[205],degree[205];
int cnt,num,n,t;
int a[205],sum[205];
string s;
struct edgenode
{
    int to,next;
} edge[205];
void init()
{
    cnt=0;
    memset(vis,false,sizeof(vis));
    memset(head,-1,sizeof(head));
    memset(degree,0,sizeof(degree));
    for(int i=0;i<=n;i++)
        sum[i]=10;
}
void add(int u,int v)
{
    //vis[u]=1;
   // vis[v]=1;
    degree[v]++;
    edge[cnt].to=v;
    edge[cnt].next=head[u];
    head[u]=cnt++;
}
void topu(int n)
{
    //cout<<-1<<endl;
    queue<int>q;
    num=0;
    for(int i=1;i<=n;i++)
    {
        if(!degree[i]&&!vis[i])
            //q[num++]=i;
            {
                q.push(i);
                vis[i]=1;
            }
    }
    //for(int i=0;i<num;i++)
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int k=head[u];k!=-1;k=edge[k].next)
        {
            degree[edge[k].to]--;
            sum[edge[k].to]=sum[u]-1;
            if(!degree[edge[k].to])
                //q[num++]=edge[k].to;
                {
                    q.push(edge[k].to);
                    vis[edge[k].to]=1;
                }
        }
    }
    //for(int i=1;i<n;i++)
      //  cout<<sum[i]<<" ";
      // cout<<sum[n]<<endl;
    //cout<<-1<<endl;
}
int main()
{
    cin>>t;
    while(t--)
    {
        init();
        memset(a,0,sizeof(a));
        cin>>n;
        cin>>s;
        int k=0;
        for(int i=1;i<=n;i++)
            for(int j=i;j<=n;j++)
        {
            if(s[k]=='+')
                add(j,i-1);
            else if(s[k]=='-')
                add(i-1,j);
                k++;
        }
        topu(n);
        for(int i=1;i<=n;i++)
            a[i]=sum[i]-sum[i-1];
       for(int i=1;i<n;i++)
        cout<<a[i]<<" ";
       cout<<a[n]<<endl;
       /*for(int i=1;i<n;i++)
        cout<<sum[i]<<" ";
       cout<<sum[n]<<endl;*/


    }
    return 0;
}