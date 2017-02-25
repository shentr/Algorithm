// HDU4971
//http://acm.hdu.edu.cn/showproblem.php?pid=4971


#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
const int oo=1e9;
const int mm=111111;
const int mn=1005;
int node,src,dest,edge;
int ver[mm],flow[mm],_next[mm];
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
    ver[edge]=v,flow[edge]=c,_next[edge]=head[u],head[u]=edge++;
    ver[edge]=u,flow[edge]=0,_next[edge]=head[v],head[v]=edge++;
}
bool Dicnic_bfs()
{
    int i,u,v,l,r=0;
    for(i=0;i<node;++i)
        dis[i]=-1;
    dis[q[r++]=src]=0;
    for(l=0;l<r;++l)
        for(i=head[u=q[l]];i>=0;i=_next[i])
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
    for(int &i=work[u],v,tmp;i>=0;i=_next[i])
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
int main()
{
    int T;
    //cin>>T;
    scanf("%d",&T);
    int x,y,z,n,m,k,t=1;
    while(T--)
    {
        scanf("%d%d",&n,&m);
        prepare(n+m+2,0,n+m+1);
        int sum=0,ans=0;
        for(int i=1;i<=n;i++)
            {
                scanf("%d",&x);
                addedge(src,i,x);
                sum+=x;
            }
            for(int i=n+1;i<=n+m;i++)
            {
                scanf("%d",&y);
                addedge(i,dest,y);
            }
            for(int i=1;i<=n;i++)
            {
                scanf("%d",&k);
                while(k--)
                {
                    scanf("%d",&z);
                    addedge(i,n+z+1,oo);
                }
            }
            for(int i=1;i<=m;i++)
                for(int j=1;j<=m;j++)
            {
                scanf("%d",&x);
                if(x)
                    addedge(n+i,n+j,oo);
            }

            ans=Dicnic_flow();
            //cout<<-1<<endl;
            //cout<<ans<<endl;
            printf("Case #%d: %d\n",t++,sum-ans);
    }
    return 0;
}
