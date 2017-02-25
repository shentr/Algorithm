// POJ2229
//http://poj.org/problem?id=2229


#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
long long dp[1000005];
int n;
int main()
{
    memset(dp,0,sizeof(dp));
    dp[1]=1;
    dp[2]=2;
    for(int i=3;i<=1000000;i++)
    {
        if(i%2==1)
        dp[i]=dp[i-1]%1000000000;
        else if(i%2==0)
            dp[i]=((dp[i-2]%1000000000)+(dp[i/2]%1000000000))%1000000000;
    }
    while(scanf("%d",&n)!=EOF)
    {
        printf("%lld\n",dp[n]%1000000000);
    }
    return 0;
}
