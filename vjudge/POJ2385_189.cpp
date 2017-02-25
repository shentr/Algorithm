// POJ2385
//http://poj.org/problem?id=2385


#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    int t,w;
    int dp[1005][40],s[1005];
    while(cin>>t>>w)
    {
        memset(s,0,sizeof(s));
        for(int i=1;i<=t;i++)
        {
            cin>>s[i];
        }
        for(int i=1;i<=t;i++)
        {
            dp[i][0]=dp[i-1][0];
            if(s[i]==1)
                dp[i][0]++;
            //else break;
        }
        for(int i=1;i<=t;i++)
            for(int j=1;j<=w;j++)
        {
            if(j>i)
                break;
            dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]);
            if(s[i]==j%2+1)
                dp[i][j]++;
        }
        //if(w==0)
        cout<<dp[t][w]<<endl;
       // else cout<<dp[t][w]+1<<endl;
    }
    return 0;
}
