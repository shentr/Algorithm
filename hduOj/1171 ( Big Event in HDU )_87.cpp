// 1171 ( Big Event in HDU )
//acm.hdu.edu.cn/showproblem.php?pid=1171


#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
const ll N=50*10000+10;
ll a[N],dp[N];

int main()
{
    ll n,value,number;
    while(cin>>n&&n>0)
    {
        ll j=0,sum=0,average;
        memset(dp,0,sizeof(dp));
        for(ll i=1;i<=n;i++)
        {
            cin>>value>>number;
            for(ll k=1;k<=number;k++)
            {
                a[j++]=value;
                sum+=value;
            }
        }
        average=sum/2;
        for(ll i=0;i<j;i++)
        {
            for(ll k=average;k>=a[i];k--)
            {
                dp[k]=max(dp[k-a[i]]+a[i],dp[k]);
            }
        }
        cout<<sum-dp[average]<<" "<<dp[average]<<endl;
    }
}
