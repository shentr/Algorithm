// HDU1513
//http://acm.hdu.edu.cn/showproblem.php?pid=1513


#include <iostream>
#include <string.h>
using namespace std;
char s1[5005],s2[5005];
int dp[2][5005];
int n;
int main()
{
    while(cin>>n)
    {
        memset(dp,0,sizeof(dp));
        memset(s1,0,sizeof(s1));
        memset(s2,0,sizeof(s2));
        cin>>s1;
        for(int i=0; i<n; i++)
            s2[i]=s1[n-i-1];
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
            {
                if(s1[i-1]==s2[j-1])
                {
                    dp[i%2][j]=dp[(i-1)%2][j-1]+1;
                }
                else dp[i%2][j]=max(dp[(i-1)%2][j],dp[i%2][j-1]);
            }
            cout<<n-dp[n%2][n]<<endl;

    }
    return 0;
}
