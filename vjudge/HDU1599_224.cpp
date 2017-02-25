// HDU1599
//http://acm.hdu.edu.cn/showproblem.php?pid=1599


#include <iostream>
#define inf 99999999
using namespace std;
int map[105][105],dis[105][105];
int main()
{
    int n,m,a,b,c;
    while(cin>>n>>m)
    {
        int ans=inf;
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                map[i][j]=inf;
        while(m--)
        {
            cin>>a>>b>>c;
            if(map[a][b]>c)
            {
                map[a][b]=c;
                map[b][a]=c;
            }
        }
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                dis[i][j]=map[i][j];
        for(int k=1; k<=n; k++)
        {
            for(int i=1; i<k; i++)
            {
                for(int j=i+1; j<k; j++)
                {
                    if(ans>dis[i][j]+map[i][k]+map[k][j])
                        ans=dis[i][j]+map[i][k]+map[k][j];
                }
            }
            for(int i=1; i<=n; i++)
            {
                for(int j=1; j<=n; j++)
                {
                    if(dis[i][j]>dis[i][k]+dis[k][j])
                    {
                        dis[i][j]=dis[i][k]+dis[k][j];
                    }
                }
            }
        }
        if(ans==inf)
            cout<<"It's impossible."<<endl;
        else cout<<ans<<endl;
    }

    return 0;
}
