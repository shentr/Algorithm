// CodeForces414B
//http://codeforces.com/problemset/problem/414B


#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int mod=1e9+7;
const int maxn=2000+5;
long long dp[maxn][maxn];

int main()
{
    int n,k;
    while(cin>>n>>k)
    {
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++)
            dp[i][1]=1;
        for(int j=1;j<=n;j++)
          for(int jj=j;jj<=n;jj+=j)
            for(int i=2;i<=k;i++)
              dp[jj][i]=(dp[jj][i]+dp[j][i-1])%mod;
        long long ans=0;
        for(int i=1;i<=n;i++)
           ans=(ans+dp[i][k])%mod;
        cout<<ans<<endl;
    }
}
