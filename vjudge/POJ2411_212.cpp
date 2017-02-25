// POJ2411
//http://poj.org/problem?id=2411


#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
using namespace std;

bool check(int s)//判断s有没有奇数个连续的1
{
    int ret=0;
    while(s)
    {
        if(s&1)ret++;
        else
        {
            if(ret&1)return false;
            ret=0;
        }
        s>>=1;
    }
    if(ret&1)return false;
    return true;
}
long long dp[12][2050];
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)==2)
    {
        if(n==0 && m==0)break;
        int tot=(1<<m);
        memset(dp,0,sizeof(dp));
        for(int i=0;i<tot;i++)
            if(check(i))
                dp[1][i]=1;
        for(int i=1;i<n;i++)
            for(int j=0;j<tot;j++)
                if(dp[i][j]!=0)
                {
                    for(int k=0;k<tot;k++)
                        if( (j|k)==tot-1 && check(j&k) )
                            dp[i+1][k]+=dp[i][j];
                }
        printf("%I64d\n",dp[n][tot-1]);
    }
    return 0;
}