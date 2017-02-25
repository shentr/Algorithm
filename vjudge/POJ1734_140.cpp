// POJ1734
//http://poj.org/problem?id=1734


#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
const int MAXN=105;
const int INF=10000000;

int dis[MAXN][MAXN],g[MAXN][MAXN];
int res[MAXN][MAXN],path[MAXN];

int n,m,cnt,minc,ans;
/*const int INF=0x3f3f3f3f;
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
}*/
void solve()
{
    int i,j,k,p,tmp;
     minc=INF;
    for(k=1; k<=n; k++)
    {
        for( i=1; i<k; i++)
            for( j=i+1; j<k; j++)
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
       for( i=1;i<=n;i++)
          for( j=1;j<=n;j++)
          {
             tmp=dis[i][k]+dis[k][j];
             if(dis[i][j]>tmp)
             {
                 dis[i][j]=tmp;
                 res[i][j]=res[k][j];
             }
          }
    }
}
/*void solve()
{
     int i,j,k,p,tmp;
     minc=INF;
     for(k=1;k<=n;k++)
     {
         for(i=1;i<k;i++)
          for(j=i+1;j<k;j++)
          {
              tmp=dis[i][j]+g[i][k]+g[k][j];
              if(tmp<minc) //找到更优解
              {
                  minc=tmp;
                  cnt=0;
                  p=j;
                  while(p!=i) //逆向寻找前驱结点直到找到最前面的i,i->…->j
                  {
                        path[cnt++]=p;
                        p=res[i][p];//res[i][j]保存的不是k,而是res[k][j].
                  }
                  path[cnt++]=i;
                  path[cnt++]=k;
              }
          }
         for(i=1;i<=n;i++)
          for(j=1;j<=n;j++)
          {
             tmp=dis[i][k]+dis[k][j];
             if(dis[i][j]>tmp)
             {
                 dis[i][j]=tmp;
                 res[i][j]=res[k][j];
             }
          }
     }
}*/
/*int main()
{
    ios::sync_with_stdio(reslse);
    int u,v,w;
    //while(scanf("%d%d",&n,&m)!=EOF)
    while(cin>>n>>m)
    {
          init();
          for(int i=1; i<=m; i++)
        {
            cin>>u>>v>>w;
            if(w<dis[u][v])
            {
                dis[u][v]=dis[v][u]=g[u][v]=g[v][u]=w;
            }

        }
           solve();
        if(ans==INF)
            cout<<"No solution."<<endl;
        else
        {
            cout<<path[1];
            for(int i=2; i<=cnt; i++)
                cout<<" "<<path[i];
            cout<<endl;
        }
    }
    return 0;
}*/
int main()
{
    int i,j,u,v,w;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
          for(i=1;i<=n;i++)
           for(j=1;j<=n;j++)
           {
               g[i][j]=INF;
               dis[i][j]=INF;
               res[i][j]=i;
           }
          while(m--)
          {
               scanf("%d%d%d",&u,&v,&w);
               w=min(g[u][v],w);          //处理重边
               g[u][v]=g[v][u]=dis[u][v]=dis[v][u]=w;
          }
          solve();
          if(minc==INF)
               printf("No solution.\n");
          else
          {
               printf("%d",path[0]);
               for(i=1;i<cnt;i++)
                   printf(" %d",path[i]);
               printf("\n");
          }
    }
   // system("pause");
    return 0;
}
