// POJ3268
//http://poj.org/problem?id=3268


#include <iostream>
#define INF 99999999
using namespace std;
int n,m,x,t1,t2,t3,u,u2;
long long e[1005][1005],e2[1005][1005],dis[1005],dis2[1005];
bool book[1005],book2[1005];
int main()
{
    while(cin>>n>>m>>x)
    {

        long long minn;
        long long minn2;
        long long sum=-INF;
        //cout<<-2<<endl;
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
            {

                if(i==j)
                {
                    e[i][j]=0;
                    e2[i][j]=0;
                }
                    else
                    {
                        e[i][j]=INF;
                        e2[i][j]=INF;
                    }
                    //cout<<-3<<endl;
                }

                for(int i=1; i<=m; i++)
                {
                    //cout<<-1<<endl;
                    cin>>t1>>t2>>t3;
                    e[t1][t2]=t3;
                    e2[t2][t1]=t3;
                }
                for(int i=1; i<=n; i++)
                {
                    dis[i]=e[x][i];
                    dis2[i]=e2[x][i];
                }
                for(int i=1; i<=n; i++)
                {
                    book[i]=0;
                    book2[i]=0;
                }
                book[x]=1;
                book2[x]=1;
                for(int i=1; i<=n-1; i++)
                {
                    minn=INF;
                    for(int j=1; j<=n; j++)
                    {
                        if(book[j]==0&&dis[j]<minn)
                        {
                            minn=dis[j];
                            u=j;
                        }
                    }
                    book[u]=1;
                    for(int v=1; v<=n; v++)
                    {
                        if(e[u][v]<INF)
                        {
                            if(dis[v]>dis[u]+e[u][v])
                                dis[v]=dis[u]+e[u][v];
                        }
                    }
                }
                for(int i=1; i<=n-1; i++)
                {
                    minn2=INF;
                    for(int j=1; j<=n; j++)
                    {
                        if(book2[j]==0&&dis2[j]<minn2)
                        {
                            minn2=dis2[j];
                            u=j;
                        }
                    }
                    book2[u]=1;
                    for(int v=1; v<=n; v++)
                    {
                        if(e2[u][v]<INF)
                        {
                            if(dis2[v]>dis2[u]+e2[u][v])
                                dis2[v]=dis2[u]+e2[u][v];
                        }
                    }
                }
                for(int i=1; i<=n; i++)
                {
                    if(dis[i]+dis2[i]>sum)
                        sum=dis[i]+dis2[i];
                    //cout<<dis[i]+dis2[i]<<" "<<dis[i]<<" "<<dis2[i]<<endl;
                }
                cout<<sum<<endl;
            }
        return 0;
    }
