// POJ1276
//http://poj.org/problem?id=1276


#include <iostream>
#include <string.h>
using namespace std;
int v[1005],price[1005],num[1005];
long long dp[100005];
void Zero_Pack(int value,int vv,int w)
{
    for(int i=w;i>=vv;i--)
        dp[i]=max(dp[i],dp[i-vv]+value);
}
void Complete_Pack(int value,int vv,int w)
{
    for(int i=vv;i<=w;i++)
        dp[i]=max(dp[i],dp[i-vv]+value);
}
long long Pack(int v[],int price[],int num[],int n,int w)
{
    for(int i=1;i<=n;i++)
    {
        if(num[i]*v[i]>w)
        {
            Complete_Pack(price[i],v[i],w);
        }
        else
        {
            int k=1;
            while(k<num[i])
            {
                Zero_Pack(k*price[i],k*v[i],w);
                num[i]-=k;
                k=k<<1;
            }
            Zero_Pack(num[i]*price[i],num[i]*v[i],w);
        }
    }
    return dp[w];
}
void init()
{
    memset(dp,0,sizeof(dp));
    memset(price,0,sizeof(price));
    memset(num,0,sizeof(num));
    memset(v,0,sizeof(v));
}
int main()
{
    ios::sync_with_stdio(false);
    int w,n;
    while(cin>>w>>n)
    {
        init();
        for(int i=1;i<=n;i++)
        {
            cin>>num[i]>>price[i];
            v[i]=price[i];
        }
      long long ans=Pack(v,price,num,n,w);
      cout<<ans<<endl;
    }
    return 0;
}
