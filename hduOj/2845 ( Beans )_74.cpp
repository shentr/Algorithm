// 2845 ( Beans )
//acm.hdu.edu.cn/showproblem.php?pid=2845


#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int dp[2000][2000];
int a[2000][2000];

int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
            {
                scanf("%d",&a[i][j]);
                dp[i][j]=0;
            }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            dp[i][j]=max(dp[i][j-1],dp[i][j-2]+a[i][j]);
        }
        for(int k=1;k<=n;k++)
        {
            dp[k][m]=max(dp[k-1][m],dp[k-2][m]+dp[k][m]);
        }
        printf("%d\n",dp[n][m]);
    }
}
