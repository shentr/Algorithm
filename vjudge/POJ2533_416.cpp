// POJ2533
//http://poj.org/problem?id=2533


#include <iostream>
#define INF -9999999999
#include <string.h>
#include <algorithm>
using namespace std;
long long a[50005],dp[50005];
int main()
{
    int n;
    while(cin>>n)
    {
        memset(a,0,sizeof(a));
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++)
            cin>>a[i];
            dp[1]=a[1];
            int len=1;
        for(int i=2;i<=n;i++)
        {
            if(a[i]>dp[len])
                dp[++len]=a[i];
            else
            {
               int pos=lower_bound(dp+1,dp+len+1,a[i])-dp;
                dp[pos]=a[i];
            }
        }
        cout<<len<<endl;
       // for(int i=0;i<=len;i++)
         //   cout<<dp[i]<<endl;
    }
    return 0;
}
