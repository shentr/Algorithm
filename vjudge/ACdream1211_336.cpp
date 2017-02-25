// ACdream1211
//http://acdream.info/problem?pid=1211


#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;
const int oo=1e9;
const int mm=800005;
const int mn=205;
int node,src,dest,edge;
int ver[mm],flow[mm],next[mm];
int head[mn],work[mn],dis[mn],q[mn];
void prepare(int _node,int _src,int _dest)
{
    node=_node,src=_src,dest=_dest;
    for(int i=0;i<node;++i)
        head[i]=-1;
    edge=0;
}
void addedge(int u,int v,int c)
{
    ver[edge]=v,flow[edge]=c,next[edge]=head[u],head[u]=edge++;
    ver[edge]=u,flow[edge]=0,next[edge]=head[v],head[v]=edge++;

}
bool Dicnic_bfs()
{
   int i,u,v,l,r=0;
   for(i=0;i<node;++i)
    dis[i]=-1;
   dis[q[r++]=src]=0;
   for(l=0;l<r;++l)
    for(i=head[u=q[l]];i>=0;i=next[i])
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
    for(int &i=work[u],v,tmp;i>=0;i=next[i])
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
        for(i=0;i<node;++i)
            work[i]=head[i];
        while(delta=Dicnic_dfs(src,oo))
            ret+=delta;
    }
    return ret;
}
int n,m;
 vector<int> _edge,_low;
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        int flow2=0;
        prepare(n+2,0,n+1);
        _edge.clear();
        _low.clear();
        for(int i=0; i<m; i++)
        {
            int u,v,low,high;
            scanf("%d%d%d%d",&u,&v,&low,&high);
            flow2+=low;
            addedge(0,v,low);
            addedge(u,n+1,low);
            _edge.push_back(edge);
            _low.push_back(low);
            addedge(u,v,high-low);
        }
        int flow1=Dicnic_flow();
        if(flow1!=flow2)
            printf("NO\n");
            //for(int i=0;i<=2*n;i++)
                //cout<<flow[i]<<endl;
        //
        else
            {
                printf("YES\n");
                int _size=_edge.size();
                for(int i=0;i<_size;i++)
                {
                    printf("%d\n",flow[_edge[i]^1]+_low[i]);
                }
            }
    }
    return 0;
}
