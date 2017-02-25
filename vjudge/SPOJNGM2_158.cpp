// SPOJNGM2
//http://www.spoj.com/problems/NGM2


#include <iostream>
#include <string.h>
#include <stdio.h>
#define LL long long
using namespace std;
LL a[20];
LL gcd(LL a,LL b) //求a和b的最大公约数
{
    return b ? gcd(b,a%b) : a;
}
LL lcm(LL a,LL b)
{
    return a/gcd(a,b)*b;
}
int main()
{
    int m;
    LL n,ans;

    while(cin>>n>>m)
    {
        ans=0;
        for(int i=0; i<m; i++)
            cin>>a[i];
        for(int i=1; i<(1<<m); i++)
        {   LL l=1,flag=0;
            for(int j=0; j<m; j++)
            {
                if((1<<j)&i)
                {
                    l=lcm(l,a[j]);
                    if(l>n)
                        break;
                    flag++;
                }
            }
            if(flag&1)
                ans+=n/l;
            else ans-=n/l;
        }
        cout<<n-ans<<endl;
    }
    return 0;
}
