// HDU4292
//http://acm.hdu.edu.cn/showproblem.php?pid=4292


#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int oo=1e9;
const int mm=1000010;
const int mn=2222;
int node ,src,dest,edge;

int ver[mm],flow[mm],_next[mm];
int head[mn],work[mn],dis[mn],q[mn];
void prepare(int _node,int _src,int _dest)
{
    node=_node,src=_src,dest=_dest;
    for(int i=0; i<node; ++i)
        head[i]=-1;
    edge=0;
}
void addedge(int u,int v,int c)
{
    ver[edge]=v,flow[edge]=c,_next[edge]=head[u],head[u]=edge++;
    ver[edge]=u,flow[edge]=0,_next[edge]=head[v],head[v]=edge++;
}
bool Dicnic_bfs()
{
    int i,u,v,l,r=0;
    for(i=0; i<node; ++i)
        dis[i]=-1;
    dis[q[r++]=src]=0;
    for(l=0; l<r; ++l)
        for(i=head[u=q[l]]; i>=0; i=_next[i])
            if(flow[i]&&dis[v=ver[i]]<0)
            {
            dis[q[r++]=v]=dis[u]+1;
                if(v==dest)
                    return 1;
            }
    return 0;
}
int Dicnic_dfs(int u,int exp)
{
    if(u==dest)
        return exp;
    for(int &i=work[u],v,tmp; i>=0; i=_next[i])
        if(flow[i]&&dis[v=ver[i]]==dis[u]+1&&(tmp=Dicnic_dfs(v,min(exp,flow[i])))>0)
        {
            flow[i]-=tmp;
            flow[i^1]+=tmp;
            return tmp;
        }
    return 0;
}
int Dicnic_flow()
{
    int i,ret=0,delta;
    while(Dicnic_bfs())
    {
        for(i=0; i<node; ++i)
            work[i]=head[i];
        while(delta=Dicnic_dfs(src,oo))
            ret+=delta;
    }
    return ret;
}
int main()
{
    int n,f,d;
    while(scanf("%d%d%d",&n,&f,&d)!=EOF)
    {
        prepare(f+n*2+d+2,0,f+n*2+d+1);
        for(int i=1; i<=f; i++)
        {
            int a;
            scanf("%d",&a);
            addedge(src,i,a);
        }
        for(int i=f+2*n+1; i<=f+2*n+d; i++)
        {
            int a;
            scanf("%d",&a);
            addedge(i,dest,a);
        }
        for(int i=f+1; i<=f+n; i++)
        {
            addedge(i,i+n,1);
        }
        char s[205];
        for(int i=f+1; i<=f+n; i++)
        {
            scanf("%s",s);
            int len=strlen(s);
            for(int j=0; j<len; j++)
            {
                if(s[j]=='Y')
                    addedge(j+1,i,1);
            }
        }
        for(int i=f+n+1; i<=f+2*n; i++)
        {
            scanf("%s",s);
            int len=strlen(s);
            for(int j=0; j<len; j++)
                if(s[j]=='Y')
                    addedge(i,j+1+f+n*2,1);
        }
        printf("%d\n",Dicnic_flow());
    }
    return 0;
}
