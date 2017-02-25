// FZU1752
//http://acm.fzu.edu.cn/problem.php?pid=1752


#include <iostream>
#include <stdio.h>

using namespace std;

long long multi(long long a,long long b,long long m)//计算(a*b)%m,快速模
{
    long long ans=0;
    a=a%m;
    while(b)
    {
        if(b&1)
        {
            ans+=a;
            if(ans>=m)
            ans-=m;//ans=(ans+a)%m;
        }
        b>>=1;
        a<<=1;//a=(a+a)%m;
        if(a>=m)
        a=a-m;

    }
    return ans;
}

long long quick(long long a,long long b,long long m)//计算a^b对m取模,利用二进制可以使复杂度由O(b)降为O(log2 b),实现快速幂取模
{
    long long ans=1;
    a=a%m;
    while(b)
    {
        if(b&1)//判断b的现在最低一位是否为1,即现在的b是否为奇数
        {
            ans=multi(ans,a,m);
        }
        b>>=1;//b右移一位
        a=multi(a,a,m);
    }
    return ans;
}

int main()
{
    long long a,b,c,sum;
    while(scanf("%I64d%I64d%I64d",&a,&b,&c)!=EOF)
    {
        sum=quick(a,b,c);
        printf("%I64d\n",sum);
    }
    return 0;
}