// SPOJNGM2
//http://www.spoj.com/problems/NGM2


#include<iostream>
#include<cstdio>
using namespace std;
long long gcd(long long a,long long b)
{
    return b==0?a:gcd(b,a%b);
}

long long lcm(long long a,long long b)
{
    return a/gcd(a,b)*b;
}

int main()
{
    long long n,m,a[20],ans;
    while(cin>>n>>m)
    {
        ans=0;
        for(int i=0;i<m;i++)
        {
            cin>>a[i];
        }
        for(int i=1;i<(1<<m);i++)
        {
            long long L=1,flag=0;
            for(int j=0;j<m;j++)
            {
                if((1<<j)&i)
                {
                    L=lcm(L,a[j]);
                    if(L>n)
                        break;
                    flag++;
                }
            }
            if(flag&1)
                ans+=n/L;
            else
                ans-=n/L;
        }
        cout<<n-ans<<endl;
    }
    return 0;
}
