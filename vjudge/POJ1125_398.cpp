// POJ1125
//http://poj.org/problem?id=1125


#include <iostream>
#include <string.h>
using namespace std;
const int INF=0x3f3f3f3f;

int dis[205][205];
int sum[205];
int n;
void prepare()
{
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
        {
            if(i==j)
                dis[i][j]=0;
            else dis[i][j]=INF;
        }
}
int main()
{
    int m,x,w;
    while(cin>>n)
    {
        memset(sum,0,sizeof(sum));
        memset(dis,0,sizeof(dis));
        memset(dis,0,sizeof(dis));
        if(n==0)
            break;
        prepare();
        for(int i=1; i<=n; i++)
        {
            cin>>m;
            for(int j=1; j<=m; j++)
            {
                cin>>x>>w;
                dis[i][x]=w;
            }
        }
        for(int k=1; k<=n; k++)
            for(int i=1; i<=n; i++)
                for(int j=1; j<=n; j++)
                    dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
//        for(int i=1; i<=n; i++)
//        {
//            for(int j=1; j<=n; j++)
//                cout<<dis[i][j]<<" ";
//            cout<<endl;
//        }
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                //if(dis[i][j]!=INF)
                    sum[i]=max(dis[i][j],sum[i]);
            }
        }
//         for(int i=1; i<=n; i++)
//          cout<<sum[i]<<" ";
//          cout<<endl;
        int ans=INF,flag=0;
        for(int i=1; i<=n; i++)
        {
            if(ans>sum[i])
             {
                 ans=sum[i];
            flag=i;
             }
            //ans=min(ans,sum[i]);
        }
        if(ans==INF)
            cout<<"disjoint"<<endl;
        else cout<<flag<<" "<<ans<<endl;

    }
    return 0;
}
