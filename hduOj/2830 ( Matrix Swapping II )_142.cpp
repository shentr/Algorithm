// 2830 ( Matrix Swapping II )
//acm.hdu.edu.cn/showproblem.php?pid=2830


#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=1005;
int dp[N][N];

int main()
{
    int n,m;
    bool a[N][N];
    while(cin>>n>>m)
    {
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
            scanf("%1d",&a[i][j]);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
            {
                if(a[i][j]==1)
                    dp[i][j]=dp[i-1][j]+1;
            }
        int ans=-N;
        for(int i=1;i<=n;i++)
        {
            int maxm=-N;
            for(int j=1;j<=m;j++)
                maxm=max(maxm,dp[i][j]);
            for(int ii=1;ii<=maxm;ii++)
            {
                int cnt=0;
                for(int j=1;j<=m;j++)
                {
                    if(dp[i][j]>=ii)
                    cnt++;
                }
                ans=max(ans,ii*cnt);
            }
        }
        cout<<ans<<endl;
    }
}
