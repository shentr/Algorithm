// POJ1276
//http://poj.org/problem?id=1276


#include <iostream>
#include <string.h>
using namespace std;
long long cash,n;
long long c[1005],w[1005],num[1005],dp[100005],use[100005];

int main()
{
    while(cin>>cash>>n)
    {
        memset(dp,0,sizeof(dp));
        memset(num,0,sizeof(num));
        memset(c,0,sizeof(c));
        memset(w,0,sizeof(w));
        long long sum=0;

        for(int i=1; i<=n; i++)
        {
            cin>>num[i]>>w[i];
            c[i]=w[i];
        }
        if(cash==0||n==0)
        {
            cout<<0<<endl;
            //break;
            continue;
        }
        for(int i=1; i<=n; i++)
        {
            memset(use,0,sizeof(use));
            for(int j=w[i]; j<=cash; j++)

            {
                if(dp[j]<cash&&dp[j]<dp[j-c[i]]+w[i]&&use[j-c[i]]<num[i])
                {
                    use[j]=use[j-c[i]]+1;
                    dp[j]=dp[j-c[i]]+w[i];
                    sum=max(sum,dp[j]);
                }
            }
        }
        cout<<sum<<endl;


    }
    return 0;
}