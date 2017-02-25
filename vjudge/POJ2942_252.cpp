// POJ2942
//http://poj.org/problem?id=2942


#include <iostream>
#include <queue>
#include <string.h>
#include <stdio.h>
using namespace std;
const int maxn=1005;
const int maxm=1000005;
struct Edge
{
    int to,next;
} edge[maxm];
int head[maxn],tot;
int g[maxn][maxn];
int low[maxn],dfn[maxn],Stack[maxn],belong[maxn];
int Index,top;
int block;
bool Instack[maxn];
bool can[maxn];
bool ok[maxn];
int tmp[maxn];
int cc;
int color [maxn];
void addedge(int u,int v)
{
    edge[tot].to=v;
    edge[tot].next=head[u];
    head[u]=tot++;
}
/*bool dfs(int u,int col)
{
    queue<int> q;
    q.push(u);
    color[u]=col;
    while(!q.empty())
    {
        u=q.front();
        q.pop();
        for(int i=head[u]; i!=-1; i=edge[i].next)
        {
            int v=edge[i].to;
            if(ok[v])
                continue;
            if(color[v]==-1)
            {
                color[v]=1-color[u];
                q.push(v);
            }
            if(color[v]==color[u])
                return false;
        }
    }
    return true;
}*/
bool dfs(int u,int col)
{
    color[u]=col;
    for(int i=head[u]; i!=-1; i=edge[i].next)
    {
        int v=edge[i].to;
        if(!ok[v])
            continue;
        if(color[v]!=-1)
        {
            if(color[v]==col)
                return false;
            continue;
        }
        if(!dfs(v,!col))
            return false;
    }
    return true;

}
void tarjan(int u,int pre)
{
    int v;
    low[u]=dfn[u]=++Index;
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
            if(low[v]>=dfn[u])
            {
                block++;
                int vn;
                cc=0;
                memset(ok,false,sizeof(ok));
                do
                {
                    vn=Stack[--top];
                    belong[vn]=block;
                    Instack[vn]=false;
                    ok[vn]=true;
                    tmp[cc++]=vn;
                }
                while(v!=vn);
                ok[u]=1;
                memset(color,-1,sizeof(color));
                if(!dfs(u,0))
                {
                    can[u]=true;
                    //cout<<cc<<endl;
                    while(cc--)
                        can[tmp[cc]]=true;
                }
            }
        }
        else if(low[u]>dfn[v])
            low[u]=dfn[v];
    }
}
void init()
{
    tot=0;
    memset(head,-1,sizeof(head));
    memset(g,0,sizeof(g));
    memset(low,0,sizeof(low));
    memset(can,0,sizeof(can));
    memset(dfn,0,sizeof(dfn));
    memset(Instack,false,sizeof(Instack));
    Index=block=top=0;
}

int main()
{
    ios::sync_with_stdio(false);
    int n,m,k1,k2;
    while(cin>>n>>m)
    {
        if(n==0&&m==0)
            break;
        init();
        for(int i=1; i<=m; i++)
        {
            cin>>k1>>k2;
            g[k1][k2]=g[k2][k1]=1;
        }
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
            {
                if(i!=j&&!g[i][j])
                {
                    addedge(i,j);
                }
            }
        for(int i=1; i<=n; i++)
            if(!dfn[i])
                tarjan(i,-1);
        int ans=n;
        for(int i=1; i<=n; i++)
            if(can[i])
                ans--;
        cout<<ans<<endl;
    }
    return 0;
}
