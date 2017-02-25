// HDU4411
//http://acm.hdu.edu.cn/showproblem.php?pid=4411


#include <iostream>
#include <stdio.h>
using namespace std;
const int oo=1e9;
const int maxm=1111111;
const int maxn=220;
const int ff=100000;
/*int node,src,dest,edge;
int head[maxn],p[maxn],dis[maxn],q[maxn],vis[maxn];
struct edgenode
{
    int to;
    int flow;
    int cost;
    int next;
} edges[maxm];
void prepare(int _node,int _src,int _dest);
void addedge(int u,int v,int f,int c);
bool spfa();
inline int min(int a,int b)
{
    return a<b?a:b;
}
inline void prepare(int _node,int _src,int _dest )
{
    node=_node;
    src=_src;
    dest=_dest;
    for(int i=0; i<node; i++)
    {
        head[i]=-1;
        vis[i]=false;
    }
    edge=0;
}
void addedge(int u,int v,int f,int c)
{
    edges[edge].flow=f;
    edges[edge].cost=c;
    edges[edge].to=v;
    edges[edge].next=head[u];
    head[u]=edge++;
    edges[edge].flow=0;
    edges[edge].cost=-c;
    edges[edge].to=u;
    edges[edge].next=head[v];
    head[v]=edge++;

}
bool spfa()
{
    int i,u,v,l,r=0,tmp;
    for(i=0; i<node; i++)
        dis[i]=oo;
    dis[q[r++]=src]=0;
    p[src]=p[dest]=-1;
    for(l=0; l!=r;((++l>=maxn)?l=0:1))
    {
        for(i=head[u=q[l]],vis[u]=false;i!=-1; i=edges[i].next)
        {
            if(edges[i].flow&&dis[v=edges[i].to]>(tmp==dis[u]+edges[i].cost))

        {
            dis[v]=tmp;
            p[v]=i^1;
                if(vis[v])
                    continue;
                vis[q[r++]=v]=true;
                if(r>=maxn)
                    r=0;
            }
        }
    }
    return p[dest]>=0;
}
int spfaflow()
{
    int i,ret=0,delta;
    while(spfa())
    {
        for(i=p[dest],delta=oo; i>=0; i=p[edges[i].to])
        {
            delta=min(delta,edges[i^1].flow);

        }
        for(int i=p[dest]; i>=0; i=p[edges[i].to])
    {
        edges[i].flow+=delta;
            edges[i^1].flow-=delta;
        }
        ret+=delta*dis[dest];
    }
    return ret;
}*/
int node,src,dest,edge;
int head[maxn],p[maxn],dis[maxn],q[maxn],vis[maxn];

struct edgenode
{
    int to;
    int flow;
    int cost;
    int next;
} edges[maxm];

void prepare(int _node,int _src,int _dest);
void addedge(int u,int v,int f,int c);
bool spfa();

inline int min(int a,int b)
{
    return a<b?a:b;
}

inline void prepare(int _node,int _src,int _dest)
{
    node=_node;
    src=_src;
    dest=_dest;
    for (int i=0; i<node; i++)
    {
        head[i]=-1;
        vis[i]=false;
    }
    edge=0;
}

void addedge(int u,int v,int f,int c)
{
    edges[edge].flow=f;
    edges[edge].cost=c;
    edges[edge].to=v;
    edges[edge].next=head[u];
    head[u]=edge++;
    edges[edge].flow=0;
    edges[edge].cost=-c;
    edges[edge].to=u;
    edges[edge].next=head[v];
    head[v]=edge++;
}

bool spfa()
{
    int i,u,v,l,r=0,tmp;
    for (i=0; i<node; i++) dis[i]=oo;
    dis[q[r++]=src]=0;
    p[src]=p[dest]=-1;
    for (l=0; l!=r; ((++l>=maxn)?l=0:1))
    {
        for (i=head[u=q[l]],vis[u]=false; i!=-1; i=edges[i].next)
        {
            if (edges[i].flow&&dis[v=edges[i].to]>(tmp=dis[u]+edges[i].cost))
            {
                dis[v]=tmp;
                p[v]=i^1;
                if (vis[v]) continue;
                vis[q[r++]=v]=true;
                if (r>=maxn) r=0;
            }
        }
    }
    return p[dest]>=0;
}

int spfaflow()
{
    int i,ret=0,delta;
    while (spfa())
    {
        for (i=p[dest],delta=oo; i>=0; i=p[edges[i].to])
        {
            delta=min(delta,edges[i^1].flow);
        }
        for (int i=p[dest]; i>=0; i=p[edges[i].to])
        {
            edges[i].flow+=delta;
            edges[i^1].flow-=delta;
        }
        ret+=delta*dis[dest];
    }
    return ret;
}

int a[maxn][maxn];
int main()
{
    int n,m,k;
     while(~scanf("%d%d%d",&n,&m,&k) && (n || m || k))
    {
        //init();
       int  s=n*2+1;
       int  t=s+1;
        prepare(n*2+3,s,t);
        for(int i=0; i<=n; i++)
          for(int j=0; j<=n; j++)
         //for(int i=0; i<m; i++)
            //for(int j=0; j<m; j++)
            if (i!=j) a[i][j]=oo;
            else a[i][j]=0;
        //while(m--)
        for(int i=0; i<m; i++)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            a[u][v]=a[v][u]=min(w,a[u][v]);
        }
        for(int l=0;l<=n;l++)//Floyd求最短路
           for(int i=0;i<=n;i++)
               for(int j=0;j<=n;j++)
                   if(a[i][l]<oo && a[l][j]<oo && a[i][l]+a[l][j]<a[i][j])
                      a[i][j]=a[i][l]+a[l][j];
        addedge(s,0,k,0);//源点与0点，容量为k，费用为0
        addedge(0,t,k,0);//汇点与0点，容量为k，费用为0
            /*for(int i=1;i<=n;i++)
                for(int j=i+1;j<=n;j++)
            {
                addedge(i+n,j,1,a[i][j]);
            }
            for(int i=1;i<=n;i++)
            {
                addedge(0,i,1,a[0][i]);
                addedge(i,i+n,1,-ff);
                addedge(i+n,t,1,a[0][i]);
            }
            printf("%d\n",spfaflow()+n*ff);
            */
             for(int i=1; i<=n; i++)
        {
            for(int j=i+1; j<=n; j++)
            {
                addedge(i+n,j,1,a[i][j]);//先到i点再到j点
            }
            addedge(0,i,1,a[0][i]);//0点到i点，容量为1，费用为最短路
            addedge(i,i+n,1,-ff);//拆点,cost值设为适当小的值，以免导致s->0->t
            addedge(i+n,t,1,a[0][i]);//i点到0点，容量为1，费用为最短路
        }
        printf("%d\n",spfaflow()+ff*n);


                }
    return 0;
}
