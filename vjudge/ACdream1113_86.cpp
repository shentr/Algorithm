// ACdream1113
//http://acdream.info/problem?pid=1113


#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=1e5+5;
double dp[N];

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        memset(dp,0,sizeof(dp));
        for(int i=n-1;i>=0;i--)
        {
            for(int j=1;j<=6;j++)
                if(i+j<=n)
                    dp[i]+=dp[i+j]/6.0;
            dp[i]+=1.0;
            if(i==n-1) dp[i]*=6.0;
            if(i==n-2) dp[i]*=3.0;
            if(i==n-3) dp[i]*=2.0;
            if(i==n-4) dp[i]*=(3.0/2);
            if(i==n-5) dp[i]*=(6.0/5);
        }
        printf("%.2lf\n",dp[0]);
    }
    return 0;
}
