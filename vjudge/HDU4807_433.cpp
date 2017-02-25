// HDU4807
//http://acm.hdu.edu.cn/showproblem.php?pid=4807


#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
const int maxm=66666;//边的最大数量，为原图的两倍 
const int maxn=5555;
const int oo=1e9;
int src,dest,node,edge,num,num2;
int ver[maxm],cost[maxm],flow[maxm],_next[maxm],t[maxm];//node节点数，src源点，dest汇点，edge边数
int head[maxn],dis[maxn],p[maxn],q[maxn];
//head链表头，p记录可行流上节点对应的反向边，dis计算距离  ,q在模拟队列
//int h[55][55];
struct sa
{
    int time,flow;
} s[maxm];
bool vis[maxn]= {0};
void prepare(int _node,int _src,int _dest)
{
    node=_node,src=_src,dest=_dest;
    for(int i=0; i<node; ++i)
        head[i]=-1;
    edge=0;
    num=0;
    num2=1;
}
void addedge(int u,int v,int f,int c)//ver表示边的指向，flow是边的容量，cost是边的费用，_next是链表的下一条边
{
    ver[edge]=v,flow[edge]=f,cost[edge]=c,_next[edge]=head[u],head[u]=edge++;
    ver[edge]=u,flow[edge]=0,cost[edge]=-c,_next[edge]=head[v],head[v]=edge++;

}
bool spfa()/**spfa 求最短路，并用 p 记录最短路上的边*/
{
    int i,u,v,l,r=0,tmp;
    for(i=0; i<=node; ++i)
    {
        dis[i]=oo;
         vis[i]=0;
         p[i]=-1;
    }
    dis[q[r++]=src]=0;
    for(l=0; l!=r; (++l==maxn)?l=0:l)
        for(i=head[u=q[l]],vis[u]=0; i>=0; i=_next[i])
            if(flow[i]&&dis[v=ver[i]]>(tmp=dis[u]+cost[i]))//u->v容量未饱和，且能够松弛
            {
                dis[v]=tmp;
                p[v]=i^1;
                if(vis[v])
                    continue;
                vis[q[r++]=v]=1;
                if(r==maxn)
                    r=0;
            }
    return p[dest]>-1;
}
int spfaflow()/**源点到汇点的一条最短路即可行流，不断的找这样的可行流*/
{
    int i,delta,ret=0;
    while(spfa())
    {

        for(i=p[dest],delta=oo; i>=0; i=p[ver[i]])
            if(flow[i^1]<delta)
                delta=flow[i^1];//可分配最大流 为增广链上的最小容量边的容量
        for(i=p[dest]; i>=0; i=p[ver[i]])
        {
            flow[i]+=delta;//反向弧容量加上可分配最大流
            flow[i^1]-=delta;//正向弧容量减去可分配最大流
        }
        s[++num].time=dis[dest];

        s[num].flow=delta;
        ret+=delta*dis[dest];
    }
    return ret;
}
int main()
{
    long long n,m,k,x,y,z;
    while(cin>>n>>m>>k)
    {
        prepare(n,0,n-1);
        for(int i=1; i<=m; i++)
        {
            cin>>x>>y>>z;
            addedge(x,y,z,1);
        }
        long long sum=spfaflow();
        /* cout<<"time="<<endl;
         for(int i=1;i<=num;i++)
         {
             cout<<s[i].time<<" ";
         }
         cout<<endl;
         cout<<"person ="<<endl;
         for(int i=1;i<=num;i++)
         {
             cout<<s[i].flow<<" ";
         }
         cout<<endl;*/
        if(k==0)
        {
            cout<<"0"<<endl;
            continue;
        }
        if(sum==0)
        {
            cout<<"No solution"<<endl;
            continue;
        }
        else
        {
            long long l=0;
            long long r=1e9;
            //cout<<k<<" "<<s[num].time<<endl;
            long long mid=0;
            bool flag=0;
            while(l<=r)
            {
                long long ans=0;
                mid=(l+r)/2;
                for(int i=1; i<=num; i++)
                {
                    if(s[i].time<=mid)
                        ans+=(mid-s[i].time+1)*s[i].flow;
                }
                if(ans>=k)
                {
                    flag=1;
                    r=mid-1;
                }
                else l=mid+1;
            }
            if(flag==0)
            {
                cout<<"No solution"<<endl;
            }
            else
                cout<<l<<endl;
        }
        // for(int i=1;i<=num;i++)
        // cout<<s[i].time<<" "<<s[i].flow<<endl;




    }
    return 0;
}
