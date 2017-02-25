// LightOJ1031
//http://lightoj.com/login_main.php?url=volume_showproblem.php?problem=1031


#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
int dp[105][105];
int sum[105];
int T,n,a;
int main()
{
    cin>>T;
    int kb=1;
    while(T--)
    {

        cin>>n;
        memset(dp,0,sizeof(dp));
        memset(sum,0,sizeof(sum));
        for(int i=1;i<=n;i++)
        {
            cin>>a;
            sum[i]=sum[i-1]+a;
            dp[i][i]=a;
        }

        for(int l=1;l<=n;l++)
        {
            for(int i=1;i+l-1<=n;i++)
            {
                int j=i+l-1;
                dp[i][j]=sum[j]-sum[i-1];
                if(i!=j)
                    for(int k=i;k<j;k++)
                {
                    dp[i][j]=max(dp[i][j],max((sum[k]-sum[i-1]-dp[k+1][j]),(sum[j]-sum[k]-dp[i][k])));
                }
            }
        }
          printf("Case %d: %d\n",kb++,dp[1][n]);
    }
    return 0;
}
