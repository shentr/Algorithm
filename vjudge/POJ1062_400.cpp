// POJ1062
//http://poj.org/problem?id=1062


#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#define INF 1000005

using namespace std;

const int maxn=105;
int m,n;
int cost[maxn][maxn];
int dis[maxn];
int r[maxn];
int next[maxn];          ///第i号物品的替代总数
bool use[maxn];
void dijk()
{
    int node;
    int sd;
    for(int i=1; i<=n; i++)
    {
        dis[i]=cost[0][i];
    }
    for(int i=1; i<=n; i++)
    {
        node=0;
        sd=INF;
        for(int j=1; j<=n; j++)
        {
            if(!use[j]&&sd>dis[j])
            {
                sd=dis[j];
                node=j;
            }
        }
        if(node==0) break;
        use[node]=true;
        for(int j=1; j<=n; j++)
        {
            if(!use[j]&&cost[node][j]<INF)
            {
                dis[j]=min(dis[j],dis[node]+cost[node][j]);
            }
        }
    }
}
int main()
{
    while(cin>>m>>n)
    {
        for(int i=1; i<=n; i++)
            dis[i]=INF;
        memset(r,0,sizeof(r));
        memset(next,0,sizeof(next));
        memset(use,0,sizeof(use));
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
            {
                if(i==j)
                    cost[i][j]=0;
                else cost[i][j]=INF;
            }
        for(int i=1; i<=n; i++)
        {
            cin>>cost[0][i]>>r[i]>>next[i];
            for(int j=1; j<=next[i]; j++)
            {
                int t,u;
                cin>>t>>u;
                cost[t][i]=u;
            }
        }
        int maxn;
        int minn=INF;
        for(int i=1; i<=n; i++)
        {
            maxn=r[i];
            for(int j=1; j<=n; j++)
            {
                if(r[j]>maxn||maxn-r[j]>m)
                {
                    use[j]=true;
                }
                else use[j]=false;
            }
            dijk();
            minn=min(minn,dis[1]);
        }
        cout<<minn<<endl;

    }
    return 0;
}
