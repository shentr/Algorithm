// HDU5137
//http://acm.hdu.edu.cn/showproblem.php?pid=5137


#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;
const int inf=1000000000;
int e[35][35],e2[35][35];
bool book[35];
int dis[35],s[35];
int n,u,m,t1,t2,t3;
int cmp(int a,int b)
{
    return a>b;
}
void sd(int x)
{
    for(int i=1; i<=n; i++)
        e[i][x]=e[x][i]=inf;
}
int dijk(int n,decltype(e) q)
{
    //memset(dis,0,sizeof(dis));

    for(int i=1; i<=n-1; i++)
    {
        int minn=inf;
        //minn=inf;
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
            if(q[u][v]<inf)
            {
                if(dis[v]>dis[u]+q[u][v])
                    dis[v]=dis[u]+q[u][v];
            }
        }
    }
    return dis[n];
}
int main()
{
    while(cin>>n>>m)
    {
        int minn=inf,t=0;
        if(n==0&&m==0)
            break;
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
            {
                if(i==j)
                {
                    e[i][j]=e[j][i]=0;
                    e2[i][j]=e2[j][i]=0;
                }
                else
                {
                    e[i][j]=e[j][i]=inf;
                    e2[i][j]=e2[j][i]=inf;
                }
            }
        for(int i=1; i<=m; i++)
        {
            cin>>t1>>t2>>t3;
            e[t1][t2]=e[t2][t1]=min(t3,e[t1][t2]);
            e2[t1][t2]=e[t1][t2];
            e2[t2][t1]=e[t2][t1];
        }
        for(int k=2; k<n; k++)
        {
            for(int i=1; i<=n; i++)
                for(int j=1; j<=n; j++)
                    e[i][j]=e2[i][j];
            sd(k);
            //memset(dis,0,sizeof(dis));
            for(int i=1; i<=n; i++)
                dis[i]=inf;
            for(int i=1; i<=n; i++)
                dis[i]=e[1][i];
            for(int i=1; i<=n; i++)
                book[i]=0;
            book[1]=1;
            s[t++]=dijk(n,e);
        }
        sort(s,s+n-2,cmp);
        //for(int i=1; i<=n; i++)
        //    cout<<s[i]<<" ";
        //cout<<endl;
        if(s[0]==inf)
            cout<<"Inf"<<endl;
        else cout<<s[0]<<endl;


    }
    return 0;
}
