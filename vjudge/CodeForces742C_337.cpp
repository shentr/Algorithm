// CodeForces742C
//http://codeforces.com/problemset/problem/742C


#include <iostream>
#include <string.h>
using namespace std;
const int MAXN= 20010;
const int MAXM = 50010;
struct Edge
{
    int to,next;
}edge[MAXM];
int head[MAXN],tot;
int low[MAXN],dfn[MAXN],Stack[MAXN],belong[MAXN];
int index ,top;
int scc;
bool instack[MAXN];
long long num[MAXN];
long long sum[MAXN],in[MAXN],out[MAXN];
void addedge(int u,int v)
{
    edge[tot].to=v;
    edge[tot].next =head[u];
    head[u]=tot++;
}
void tarjan(int u)
{
    int v;
    low[u]=dfn[u]=index++;
    Stack[top++]=u;
    instack[u]=true;
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        v=edge[i].to;
        if(!dfn[v])
        {
            tarjan(v);
            if(low[u]>low[v])
                low[u]=low[v];
        }
        else if(instack[v]&&low[u]>dfn[v])
            low[u]=dfn[v];
    }
    if(low[u]==dfn[u])
    {
        scc++;
        do
        {
            v=Stack[--top];
            instack[v]=false;
            belong[v]=scc;
            num[scc]++;
        }
        while(v!=u);
    }
}
void solve(int N)
{
    memset(dfn,0,sizeof(dfn));
    memset(instack,false,sizeof(instack));
    memset(num,0,sizeof(num));
    index = scc =top =0;
    for(int i=1;i<=N;i++)
    {
        if(!dfn[i])
            tarjan(i);
    }
}
void init()
{
    tot=0;
    memset(head,-1,sizeof(head));
    memset(sum,0,sizeof(sum));
    memset(in,0,sizeof(in));
    memset(out,0,sizeof(out));
}
long long gcd(long long a,long long b)
{
    if(a==0)
        return b;
    else
        return gcd(b%a,a);
}
long long gb(long long a,long long b)
{
    return a/gcd(a,b)*b;
}
int main()
{
    int n;
    ios::sync_with_stdio(false);
    while(cin>>n)
    {
        init();
        for(int i=1;i<=n;i++)
        {
            cin>>sum[i];
            addedge(i,sum[i]);
            in[i]++;
            out[sum[i]]++;
        }
        bool flag =1;
        for(int i=1;i<=n;i++)
        {
           if(in[i]!=out[i])
           {
               flag=0;
           }
        }
        if(!flag)
        {
            cout<<-1<<endl;
            continue;
        }
       solve(n);
       long long ans=1;
       for(int i=1;i<=scc;i++)
       {
           if(num[i]%2==0)
           {
               ans=gb(ans,num[i]/2);
           }
           else ans=gb(ans,num[i]);
       }
       cout<<ans<<endl;

    }
    return 0;
}
