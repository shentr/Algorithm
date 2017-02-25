// 5912 ( Fraction )
//acm.hdu.edu.cn/showproblem.php?pid=5912


#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

long long gcd(long long a,long long b)
{
    if(b==0)
        return a;
    else return gcd(b,a%b);
}

long long lcm(long long a,long long b)
{
    return a*b/gcd(a,b);
}

int main()
{
    long long T;
    long long n;
    long long a[20],b[20];
    long long casenum=1;
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld",&n);
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        for(long long i=0;i<n;i++)
        {
            scanf("%lld",&a[i]);
        }
        for(long long i=0;i<n;i++)
        {
            scanf("%lld",&b[i]);
        }
        long long fenzi,fenmu;
        fenzi=b[n-1];
        fenmu=a[n-1];
        long long tmp;
        //cout<<fenzi<<"hfdksjf1111   "<<fenmu<<endl;
        for(long long i=n-2;i>=0;i--)
        {

            fenzi=fenzi+a[i]*fenmu;
            fenmu=fenmu;
           // cout<<fenzi<<"hfdksjf2222   "<<fenmu<<endl;
            tmp=fenzi;
            fenzi=b[i]*fenmu;
            fenmu=tmp;
            //cout<<fenzi<<" "<<fenmu<<endl;
        }
        long long d=gcd(fenzi,fenmu);
        printf("Case #%lld: ",casenum++);
        printf("%lld %lld\n",fenzi/d,fenmu/d);
    }
    return 0;
}
