// ACdream1412
//http://acdream.info/problem?pid=1412


#include <bits/stdc++.h>

using namespace std;

int n,mod;
long long c[2510][2510];
long long dp[5010];

void Init()
{
    c[0][0]=1;
    c[1][0]=c[1][1]=1;
    for(int i=2; i<=n/2; i++)
    {
        c[i][0]=c[i][i]=1;
        for(int j=1; j<i; j++)
        {
            c[i][j]=(c[i-1][j-1]%mod+c[i-1][j]%mod)%mod;
        }
    }
}

long long dfs(int n)
{
    if(dp[n]) return dp[n];
    for(int i=0; i<=n/2; i++){
        if((n-2*i)%3==0){
            int t=(n-2*i)/3;
            dp[n]=(dp[n]+dfs(t+i)*c[i+t][i])%mod;
        }
    }
    return dp[n]%mod;
}

int main()
{
    ios::sync_with_stdio(false);
    while(cin>>n>>mod){
        Init();
        memset(dp,0,sizeof(dp));
        dp[1]=1;
        dp[2]=1;
        dp[3]=1;
        cout<<dfs(n)<<endl;
    }
    return 0;
}
