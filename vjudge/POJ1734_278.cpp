// POJ1734
//http://poj.org/problem?id=1734


#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

//const int INF=10000000;这里设成0x3f3f3f3f就错了，我也不知道为啥，可能是20000点，100000条边，会加炸

const int INF=10000000;
const int maxn=105;
int n,m,cnt,ans,minc;
int dis[maxn][maxn],g[maxn][maxn],res[maxn][maxn];
int path[maxn];
void init()
{
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
        {
            res[i][j]=i;
            if(i==j)
                dis[i][j]=dis[j][i]=g[i][j]=g[j][i]=0;
            else
                dis[i][j]=dis[j][i]=g[i][j]=g[j][i]=INF;
        }
}
void solve()
{
    int p,tmp;
    minc=INF;
    for(int k=1; k<=n; k++)
    {
        for(int i=1; i<k; i++)
            for(int j=i+1; j<k; j++)
            {
                if(minc>dis[i][j]+g[i][k]+g[k][j])
                {
                    minc=dis[i][j]+g[i][k]+g[k][j];
                    cnt=0;
                    p=j;
                    while(p!=i)
                    {
                        path[cnt++]=p;
                        p=res[i][p];
                    }
                    path[cnt++]=i;
                    path[cnt++]=k;
                }
            }
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
            {
                if(dis[i][j]>dis[i][k]+dis[k][j])
                {
                    dis[i][j]=dis[i][k]+dis[k][j];
                    res[i][j]=res[k][j];
                }
            }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    int u,v,w;
    while(cin>>n>>m)
    {
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
            {
                g[i][j]=INF;
                dis[i][j]=INF;
                res[i][j]=i;
            }
        for(int i=1; i<=m; i++)
        {
            cin>>u>>v>>w;
            if(w<g[u][v])
            {
                dis[u][v]=dis[v][u]=g[u][v]=g[v][u]=w;
            }

        }
        solve();
        if(minc==INF)
            cout<<"No solution."<<endl;
        else
        {
            cout<<path[0];
            for(int i=1; i<cnt; i++)
                cout<<" "<<path[i];
            cout<<endl;
        }
    }
    return 0;
}
