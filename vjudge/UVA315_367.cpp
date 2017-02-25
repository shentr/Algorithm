// UVA315
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=315


#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
const int MAXN=105;
const int MAXM=10010;
struct edge
{
    int to,next;
    bool cut;
} edge[MAXM];
int head[MAXM],tot;
int low[MAXN],dfn[MAXN],Stack[MAXN];
int Index;
int top;
bool instack[MAXN];
bool cut[MAXN];
int add_block[MAXN];
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
    low[u]=dfn[u]=++Index;
    Stack[top++]=u;
    instack[u]=true;
    int son=0;
    for(int i=head[u]; i!=-1; i=edge[i].next)
    {
        v=edge[i].to;
        if(v==pre)
            continue;
        if(!dfn[v])
        {
            son++;
            tarjan(v,u);
            if(low[u]>low[v])
                low[u]=low[v];
            if(u!=pre&&low[v]>=dfn[u])
            {
                cut[u]=true;
                add_block[u]++;
            }
        }
        else if(low[u]>dfn[v])
            low[u]=dfn[v];
    }
    if(u==pre&&son>1)
        cut[u]=true;
    if(u==pre)
        add_block[u]=son-1;
    instack[u]=false;
    top--;
}

void init()
{
    tot=0;
    memset(head,-1,sizeof(head));
    memset(low,0,sizeof(low));
    memset(dfn,0,sizeof(dfn));
    memset(instack,0,sizeof(instack));
    memset(add_block,0,sizeof(add_block));
    memset(cut,0,sizeof(cut));
}
int a,b,n;
int main()
{
    while(cin>>n)
    {
        int sum=0;
        init();
        if(n==0)
            break;
        while(scanf("%d",&a)!=-1)
        {
            if(a==0)
               break;
            while(getchar()!='\n')
            {
                cin>>b;
                addedge(a,b);
                addedge(b,a);
            }
        }
        tarjan(1,1);
        for(int i=1; i<=n; i++)
            if(cut[i])
                sum++;
        cout<<sum<<endl;
    }
    return 0;
}
