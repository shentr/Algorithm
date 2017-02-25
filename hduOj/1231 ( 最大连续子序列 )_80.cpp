// 1231 ( 最大连续子序列 )
//acm.hdu.edu.cn/showproblem.php?pid=1231


#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
const int N=10010;
const int INF=999999;
int a[N],dp[N];

int main()
{
    int t;
    while(~scanf("%d",&t)&&t)
    {
        int ans=-INF,maxi,mini;
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=t;i++)
        {
            scanf("%d",&a[i]);
            dp[i]=max(dp[i-1]+a[i],a[i]);
        }
        for(int i=1;i<=t;i++)
        {
            if(dp[i]>ans)
            {
                ans=dp[i];
                maxi=i;
            }
        }
        if(ans<0)
        {
            printf("0 %d %d\n",a[1],a[t]);
            continue;
        }
        int m=ans;
        for(int i=maxi;i>=1;i--)
        {
            m-=a[i];
            if(m==0)
                mini=i;
        }
        printf("%d %d %d\n",ans,a[mini],a[maxi]);
    }
}
