// 2571 ( 命运 )
//acm.hdu.edu.cn/showproblem.php?pid=2571


#include<iostream>
using namespace std;
int data[30][2000];
int dp[30][2000];
int main()
{
    int c;
    cin>>c;
    while(c--)
    {
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            cin>>data[i][j];
        }
        for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            dp[1][1]=data[1][1];
            dp[1][j]=dp[1][j-1];
            for(int t=1;t<j;t++)
            {
                if(j%t==0)
                {
                    dp[1][j]=max(dp[1][j],dp[1][t]);
                }
            }
            dp[1][j]+=data[1][j];
            dp[i][1]=dp[i-1][1]+data[i][1];

            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            for(int t=1;t<j;t++)
            {
                if(j%t==0)
                {
                    dp[i][j]=max(dp[i][j],dp[i][t]);
                }
            }
            dp[i][j]+=data[i][j];
        }
        cout<<dp[n][m]<<endl;
    }
    return 0;
}
