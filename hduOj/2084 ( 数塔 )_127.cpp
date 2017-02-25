// 2084 ( 数塔 )
//acm.hdu.edu.cn/showproblem.php?pid=2084


#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a[105][105],dp[105][105];

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++)
            for(int j=1;j<=i;j++)
                cin>>a[i][j];
        for(int i=n;i>=1;i--)
            for(int j=n;j>=1;j--)
        {
            dp[i][j]=max(dp[i+1][j],dp[i+1][j+1])+a[i][j];
        }
        cout<<dp[1][1]<<endl;
    }
}
