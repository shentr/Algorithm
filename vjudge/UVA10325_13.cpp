// UVA10325
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=10325


#include<cstdio>
long long p[20];
long long gcd(long long a,long long b)
{
    return b ? gcd(b,a%b):a;
}
long long LCM(long long a,long long b)
{
     long long tmp=gcd(a,b);
     return a/tmp*b;
}
int main()
{
    int n,m;
    int i,j;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(i=0;i<m;i++)
            scanf("%lld",&p[i]);
        int sum=0;
        for(i=1;i<(1<<m);i++)
        {
            long long mult=1;
            int ones=0;long long tmp=1;
            for(j=0;j<m;j++)
            {
                if(i&(1<<j))
                {
                    mult=LCM(mult,p[j]);
                    if(mult>n) break;
                    ones++;
                }
            }
            if(mult>n) continue;
            if(ones%2) sum+=n/mult;
            else sum-=n/mult;
        }
        printf("%d\n",n-sum);
    }
  return 0;
}