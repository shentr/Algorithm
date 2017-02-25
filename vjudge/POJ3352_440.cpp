// POJ3352
//http://poj.org/problem?id=3352


#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <map>
using namespace std;
const int MAXN=5010;
const int MAXM=20010;
struct Edge
{
    int to,next;
    bool cut;
} edge[MAXM];
int head[MAXN],tot;
int low[MAXN],dfn[MAXN],Stack[MAXN],belong[MAXN];
int Index,top;
int block;
bool Instack[MAXN];
int bridge;
void addedge(int u,int v)
{
    edge[tot].to=v;
    edge[tot].next=head[u];
    edge[tot].cut=false;
    head[u]=tot++;
}
void tarjan(int u,int pre)
{
    int v;
    low[u]=dfn[u]=Index++;
    Stack[top++]=u;
    Instack[u]=true;
    for(int i=head[u]; i!=-1; i=edge[i].next)
    {
        v=edge[i].to;
        if(v==pre)
            continue;
        if(!dfn[v])
        {
            tarjan(v,u);
            if(low[u]>low[v])
                low[u]=low[v];
            if(low[v]>dfn[u])
            {
                bridge++;
                edge[i].cut=true;
                edge[i^1].cut=true;
            }
        }
        else if(Instack[v]&&low[u]>dfn[v])
            low[u]=dfn[v];

    }
    if(low[u]==dfn[u])
    {
        block++;
        do
        {
            v=Stack[--top];
            Instack[v]=false;
            belong[v]=block;
        }while(v!=u);
    }
}
void init()
{
    tot=0;
    memset(head,-1,sizeof(head));
}
int du[MAXN];
void solve(int n)
{
    memset(dfn,0,sizeof(dfn));
    memset(Instack,0,sizeof(Instack));
    Index=top=block=0;
    tarjan(1,0);
    int ans=0;
    memset(du,0,sizeof(du));
    for(int i=1;i<=n;i++)
        for(int j=head[i];j!=-1;j=edge[j].next)
        if(edge[j].cut)
        du[belong[i]]++;
    for(int i=1;i<=block;i++)
        if(du[i]==1)
        ans++;
    printf("%d\n",(ans+1)/2);
}
int main()
{
    int u,v,n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        init();
        while(m--)
        {
            scanf("%d%d",&u,&v);
            addedge(u,v);
            addedge(v,u);
        }
        solve(n);
    }
    return 0;
}
