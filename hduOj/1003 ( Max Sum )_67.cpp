// 1003 ( Max Sum )
//acm.hdu.edu.cn/showproblem.php?pid=1003


#include<iostream>
#include<cstdio>
using namespace std;
int data[100100];
int dp[100100];
int main()
{
    int tase;
    while(cin>>tase)
    for(int t=1;t<=tase;t++)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>data[i];
        }
        dp[1]=data[1];
        for(int i=2;i<=n;i++)
        {
            if(dp[i-1]+data[i]>=data[i])
                dp[i]=dp[i-1]+data[i];
            else
                dp[i]=data[i];
        }
        int maxn=-9999,maxi;
        for(int i=1;i<=n;i++)
        {
            if(dp[i]>maxn)
            {
                maxn=dp[i];
                maxi=i;
            }
        }
        int mini;
        for(int i=1;i<=maxi;i++)
        {
            int sum=0;
            for(int j=i;j<=maxi;j++)
            {
                sum=sum+data[j];
            }
            if(sum==maxn)
            {
                mini=i;
                break;
            }
        }
        printf("Case %d:\n%d %d %d\n",t,maxn,mini,maxi);
        if(t!=tase)
            cout<<endl;
    }
}
