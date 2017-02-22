// 1087 ( Super Jumping! Jumping! Jumping! )
//acm.hdu.edu.cn/showproblem.php?pid=1087


#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=1010;

long long a[N],dp[N];
int main()
{
    long long n,maxa;
    while(cin>>n&&n)
    {
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            dp[i]=a[i];
        }
        for(int i=0;i<n;i++)
        {
            maxa=0;
            for(int j=0;j<i;j++)
                if(a[j]<a[i])
                {
                    maxa=max(maxa,dp[j]);
                }
            dp[i]=a[i]+maxa;
        }
        long long ans=0;
        for(int i=0;i<n;i++)
            ans=max(ans,dp[i]);
            cout<<ans<<endl;
    }
}
