// FZU1752
//http://acm.fzu.edu.cn/problem.php?pid=1752


#include<cstdio>

typedef unsigned long long ll;

ll quick_multi(ll a,ll b,ll c)
{
    ll ans=0,t=a%c;
    while(b)
    {
        if(b&1)
            if((ans+=t)>=c)
            ans-=c;
        if((t<<=1)>=c)
            t-=c;
        //ans=(ans+a)%c;
        //a=(a+a)%c;
        b>>=1;
    }
    return ans;
}

int main()
{
    ll a,b,c,ns;
    while(scanf("%I64u%I64u%I64u",&a,&b,&c)!=EOF)
    {
        ns=1;
       // a=a%c;
    while(b)
    {
        if(b&1)
        ns=quick_multi(ns,a,c);
        a=quick_multi(a,a,c);
        b>>=1;
    }
        printf("%I64u\n",ns);
    }
    return 0;
}
