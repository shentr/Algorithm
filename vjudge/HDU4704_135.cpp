// HDU4704
//http://acm.hdu.edu.cn/showproblem.php?pid=4704


#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long LL;
const int mod=1e9+7,N=1e5+5;
char a[N];

LL quick_mod(LL a,LL p)
{
    LL ans=1;
    while(p)
    {
        if(p&1)
            ans=ans*a%mod;
        a=a*a%mod;
        p>>=1;
    }
    return ans;
}

int main()
{
    while(~scanf("%s",a))
    {
        int len=strlen(a);
        LL ans=0;
        for(int i=0;i<len;i++)
        {
            ans=(ans*10+a[i]-'0')%(mod-1);
        }
        ans=(ans-1+mod-1)%(mod-1);
        printf("%lld\n",quick_mod(2,ans));
    }
    return 0;
}
