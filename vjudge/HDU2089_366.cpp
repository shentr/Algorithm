// HDU2089
//http://acm.hdu.edu.cn/showproblem.php?pid=2089


#include <iostream>
#include <string.h>
using namespace std;
int dp[20][20];
int digit[20];
//dp[i][0]表示不含不吉利的数字
//dp[i][1]表示首位为2，不含不吉利的数字
//dp[i][2]表示含不吉利的数字
void init()//打表
{
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;//这块预处理一下
    for(int i=1;i<=6; i++)
    {
        dp[i][0]=dp[i-1][0]*9-dp[i-1][1];//把吉利的前面加上除了4以为的任何一个数再减去以2为首位的前面加6的情况
        dp[i][1]=dp[i-1][0];//把i-1位吉利的前面加上2，个数不变
        dp[i][2]=dp[i-1][0]+dp[i-1][1]+dp[i-1][2]*10;//把之前不吉利的前面加恩以一个数字都一样所以*10，然后加上当前位是4的，和当前位是6的，前一位是2的
    }
}
int solve(int x)
{
    memset(digit,0,sizeof(digit));
    int tmp=x;
    int cnt=0,sum=0;
    bool flag=0;
    while(tmp)
    {
        digit[++cnt]=tmp%10;
        tmp/=10;
    }
    for(int i=cnt; i>0; i--)
    {
        sum+=dp[i-1][2]*digit[i];//上来先把i-1位不吉利的找到，然后*当前位的数字，因为有0，所以不需要减1
        if(flag)
            sum+=digit[i]*dp[i-1][0];//如果标记过，那么后面的全都是不吉利的，上面已经把本来就不吉利的算过了，现在把本来吉利的加上就行了
            else
            {
                if(digit[i]>4)//如果当前位大于4，那么证明4xx肯定存在，所以直接加上以4为首的，原来吉利的
                    sum+=dp[i-1][0];
                if(digit[i]>6)//这个如果大于6，就把下一位有2的本来吉利的加上
                    sum+=dp[i-1][1];
                if(digit[i+1]==6&&digit[i]>2)//如果上一位等于6，这一位大于2，那么就把当前这轮的62的加上
                {
                     sum+=dp[i][1];
                }
            }
            if(digit[i]==4||(digit[i+1]==6&&digit[i]==2))//当前位是4或者上一位是6，当前位是4的，标记一下
                flag=1;
    }
    return x-sum;


}
int main()
{
    int n,m;
     init();
    while(cin>>n>>m)
    {
        if(n==0&&m==0)
            break;

       // cout<<solve(m)<<" "<<solve(n-1)<<endl;
        cout<<solve(m+1)-solve(n)<<endl;
    }

    return 0;
}
