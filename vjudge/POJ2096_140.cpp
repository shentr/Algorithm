// POJ2096
//http://poj.org/problem?id=2096


#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
const int MAXN=1010;
double dp[MAXN][MAXN];

int main()
{
    int n,s;
    while(scanf("%d%d",&n,&s)!=EOF)
    {
        dp[n][s]=0;
        for(int i=n;i>=0;i--)
          for(int j=s;j>=0;j--)
          {
              if(i==n&&j==s)continue;
              dp[i][j]=(i*(s-j)*dp[i][j+1]+(n-i)*j*dp[i+1][j]+(n-i)*(s-j)*dp[i+1][j+1]+n*s)/(n*s-i*j);
          }
        printf("%.4lf\n",dp[0][0]);
    }
    return 0;
}