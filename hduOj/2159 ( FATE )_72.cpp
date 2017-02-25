// 2159 ( FATE )
//acm.hdu.edu.cn/showproblem.php?pid=2159


#include<iostream>
#include<cstring>
using namespace std;
int dp[110][110];

int main()
{
    int n,m,k,s;
    int a[110],b[110];
    while(cin>>n>>m>>k>>s)
    {
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=k;i++)
            cin>>a[i]>>b[i];
        for(int i=1;i<=k;i++)
        {
            for(int j=b[i];j<=m;j++)
            {
                for(int g=1;g<=s;g++)
                {
                    dp[j][g]=max(dp[j-b[i]][g-1]+a[i],dp[j][g]);
                }
            }
        }
        //cout<<dp[m][s]<<endl;
        if(dp[m][s]<n)
            cout<<-1<<endl;
        else
        {
            int mini=m;
            for(int i=0;i<=m;i++)
                for(int j=0;j<=s;j++)
                if(dp[i][j]>=n)
                {
                    mini=min(i,mini);
                }
            cout<<m-mini<<endl;
        }
    }
    return 0;
}
