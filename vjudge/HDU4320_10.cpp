// HDU4320
//http://acm.hdu.edu.cn/showproblem.php?pid=4320


#include<iostream>
#include<cstdio>
using namespace std;

long long gcd(long long a,long long b)
{
    return b==0?a:gcd(b,a%b);
}

int main()
{
    int t;
    cin>>t;
    for(int kase=1;kase<=t;kase++)
    {
        long long a,b;
        cin>>a>>b;
        long long t;
        while((t=gcd(a,b))!=1)
            a/=t;
        if(a!=1)
            printf("Case #%d: NO\n",kase);
        else
            printf("Case #%d: YES\n",kase);
    }
}
