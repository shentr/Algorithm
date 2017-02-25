// POJ3904
//http://poj.org/problem?id=3904


#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
typedef long long LL;
const int maxn=10005;
LL count[maxn];
LL num[maxn];
LL p[maxn];
LL prime[maxn];

void solve(LL  n)
{
    LL  tol=0;
    for(LL  i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            prime[tol++]=i;
        }
        while(n%i==0)
            n/=i;
    }
    if(n!=1)
    prime[tol++]=n;
    for(LL  i=1;i<(1<<tol);i++)
    {
        LL k=1;
        LL sum=0;
        for(LL  j=0;j<tol;j++)
        {
            if(i&(1<<j))
            {
                k*=prime[j];
                sum++;
            }
        }
        count[k]++;
        num[k]=sum;
    }

}
int main()
{
    memset(p,0,sizeof(p));
    memset(num,0,sizeof(num));
    for(LL i=4;i<maxn;i++)
        p[i]=i*(i-1)*(i-2)*(i-3)/24;
    LL  n;
    LL  m;
    while(scanf("%lld",&n)!=EOF)
    {
       memset(count,0,sizeof(count));
       for(LL  i=0;i<n;i++)
       {
           scanf("%lld",&m);
           solve(m);
       }
       LL ans=0;
       for(LL  i=0;i<maxn;i++)
       {
           if(count[i])
           {
               if(num[i]%2)
               {
                   ans+=p[count[i]];
               }
               else
               ans-=p[count[i]];
           }
       }
       cout<<p[n]-ans<<endl;
   }
}