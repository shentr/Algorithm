// 1171 ( Big Event in HDU )
//acm.hdu.edu.cn/showproblem.php?pid=1171


#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=50*1000+10;
int a[N],dp[N];

int main()
{
    int n,value,number;
    while(cin>>n&&n>0)
    {
        int j=0,sum=0,average;
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++)
        {
            cin>>value>>number;
            for(int k=1;k<=number;k++)
            {
                a[j++]=value;
                sum+=value;
            }
        }
        average=sum/2;
        for(int i=0;i<j;i++)
        {
            for(int k=average;k>=a[i];k--)
            {
                dp[k]=max(dp[k-a[i]]+a[i],dp[k]);
            }
        }
        cout<<sum-dp[average]<<" "<<dp[average]<<endl;
    }
}
