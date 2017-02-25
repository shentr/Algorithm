// HDU3555
//http://acm.hdu.edu.cn/showproblem.php?pid=3555


#include <iostream>
#include <string.h>
long long dp[20][5];
int digit[20];
using namespace std;
void prepare()
{
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    for(int i=1;i<=18;i++)
        {
            dp[i][0]=dp[i-1][0]*10-dp[i-1][1];
            dp[i][1]=dp[i-1][0];
            dp[i][2]=dp[i-1][2]*10+dp[i-1][1];
        }
}
long long solve(long long x)
{
    memset(digit,0,sizeof(digit));
    long long tmp=x;
    long long sum=0;
    int cnt=0;
    bool flag=0;
    while(tmp)
    {
        digit[++cnt]=tmp%10;
        tmp/=10;
    }
    for(int i=cnt;i>=0;i--)
    {
        sum+=dp[i-1][2]*digit[i];
        if(flag)
            sum+=digit[i]*dp[i-1][0];
            else
            {
                if(digit[i]>4)
                    sum+=dp[i-1][1];
                if(digit[i+1]==4&&digit[i]==9)
                    flag=1;
            }
    }
    return sum;
}
int main()
{
    ios::sync_with_stdio(false);
    int T;
    long long n;
    prepare();
    cin>>T;
    while(T--)
    {
        cin>>n;
        cout<<solve(n+1)<<endl;
    }
    return 0;
}
