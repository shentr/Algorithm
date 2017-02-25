// 2955 ( Robberies )
//acm.hdu.edu.cn/showproblem.php?pid=2955


#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=110;
int m[N],sum[N];
double p[N],dp[N*N];

int main()
{
    int t,n;
    double P;
    scanf("%d",&t);
    while(t--)
    {
        memset(dp,0,sizeof(dp));
        scanf("%lf%d",&P,&n);
        P=1-P;                //最大逃脱概率
        for(int i=0;i<n;i++)
        {
            scanf("%d%lf",&m[i],&p[i]);
            p[i]=1-p[i];
            sum[i]=(i==0?m[0]:sum[i-1]+m[i]);
        }
        dp[0]=1;
        for(int i=0;i<n;i++)
        {
            for(int j=sum[n-1];j>=m[i];j--)
            {
                dp[j]=max(dp[j],dp[j-m[i]]*p[i]);
            }
        }
        for(int j=sum[n-1];j>=0;j--)
        {
            if(dp[j]>P)
            {
                printf("%d\n",j);
                break;
            }
        }
    }
}
