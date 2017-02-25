// HDU5651
//http://acm.hdu.edu.cn/showproblem.php?pid=5651


#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long LL;
const LL MOD=1e9+7;
int cnt[260];
char ch[1005];

LL jiecheng(int n)
{
    if(n==0)
        return 1;
    LL ans=1;
    for(int i=1;i<=n;i++)
        ans=ans*i%MOD;
    return ans;
}

LL x,y;
LL gcd(LL a,LL b)
{
    LL t,d;
    if(b==0)
    {
         x=1,y=0;
         return a;
    }
     d=gcd(b,a%b);
     t=x, x=y, y=t-(a/b)*y;
     return d;
 }

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        memset(cnt,0,sizeof(cnt));
        scanf("%s",ch);
        int len=strlen(ch);
        for(int i=0;i<len;i++)
        {
            cnt[ch[i]-' ']++;
        }
        int count=0;
        for(int i=0;i<260;i++)
        {
            if(cnt[i]&1)
                count++;
            cnt[i]/=2;
        }
        if(count>1)
        {
            cout<<0<<endl;
            continue;
        }
        LL ans=jiecheng(len/2)%MOD;
        for(int i=0;i<260;i++)
        {
            if(cnt[i]>0)
            {
                gcd(jiecheng(cnt[i]),MOD);
                if(x<0)
                    x+=MOD;
                ans=ans*x%MOD;
            }
        }
        cout<<ans<<endl;
    }
}
