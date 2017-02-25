// POJ1734
//http://poj.org/problem?id=1734


#include <iostream>

using namespace std;
const int maxn=105;
const int INF=0x3f3f3f3f;
int dis[maxn][maxn],g[maxn][maxn];
int fa[maxn][maxn],path[maxn];
int n,m,minc,num;
void floyd()
{
    int p,tmp;
    minc=INF;
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
        {
            if(i == j || g[j][k] == INF ||
    g[k][i] == INF || dis[i][j] == INF) continue;
            tmp=dis[i][j]+g[i][k]+g[k][j];
            if(tmp<minc)
            {
                minc=tmp;
                num=0;
                p=j;
                while(p!=i)
                {
                    path[num++]=p;
                    p=fa[i][p];
                }
                path[num++]=i;
                path[num++]=k;
            }
        }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
        {
            tmp=dis[i][k]+dis[k][j];
            if(dis[i][j]>tmp)
            {
                dis[i][j]=tmp;
                fa[i][j]=fa[k][j];
            }
        }
    }
}
int main()
{
    int u,v,w;
    while(cin>>n>>m)
    {
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
        {
            g[i][j]=INF;
            dis[i][j]=INF;
            fa[i][j]=i;
        }
        while(m--)
        {
            cin>>u>>v>>w;
            w=min(g[u][v],w);
            g[u][v]=g[v][u]=dis[u][v]=dis[v][u]=w;
        }
        floyd();
      //  cout<<num<<endl;
        if(minc==INF)
            cout<<"No solution."<<endl;

        else
            {
                cout<<path[0];
                for(int i=1;i<num;i++)
                    cout<<" "<<path[i];
                cout<<endl;
            }
    }
    return 0;
}
