// CodeForces416B
//http://codeforces.com/problemset/problem/416B


#include<iostream>
using namespace std;
const int N=50100;
long long t[N][10],dp[N][10];

int main()
{
    int n,m;
    cin>>m>>n;
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            cin>>t[i][j];
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            dp[i][j]=max(dp[i][j-1],dp[i-1][j])+t[i][j];
    for(int i=1;i<=m;i++)
        cout<<dp[i][n]<<' ';
}
