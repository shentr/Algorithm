// HDU3555
//http://acm.hdu.edu.cn/showproblem.php?pid=3555


#include <iostream>
#include <string.h>
//dp[i][j]表示位数是i，状态为j
//pos表示当前的位数
//status中0表示不含49，1表示上一位是4，2表示含49
//limit表示当前位是否受限制
using namespace std;
int digit[30];
long long dp[30][3];
int prepare(long long x)
{
     memset(digit,0,sizeof(digit));
    int cnt=0;
    while(x)
    {
        digit[++cnt]=x%10;
        x/=10;
    }
    //digit[cnt+1]=0;
    return cnt;
}
long long solve(int pos,int status,int limit)
{
    if(pos<=0)
        return status==2;
    if(!limit&&dp[pos][status]!=-1)
        return dp[pos][status];
   long long ans=0;
    int num=limit?digit[pos]:9;
    for(int i=0;i<=num; i++)
    {
        int nstatus=status;
        if(status==0&&i==4)
            nstatus=1;
        else if(status==1&&i!=4&&i!=9)
            nstatus=0;
        else if(status==1&&i==9)
            nstatus=2;
            ans+=solve(pos-1,nstatus,limit&&i==num);
    }
    if(!limit)
         dp[pos][status]=ans;
    return ans;
}
int main()
{
    int T;
    long long n;
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--)
    {
        memset(dp,-1,sizeof(dp));
        cin>>n;
        int len=prepare(n);
       long long sum=solve(len,0,1);
       cout<<sum<<endl;
    }
    return 0;
}
