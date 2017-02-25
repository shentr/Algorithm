// CodeForces743B
//http://codeforces.com/problemset/problem/743B


#include <iostream>
#include <math.h>
using namespace std;
long long n,k;
long long Pow(long long x,long long y)
{
    long long m=1;
    while(y)
    {
        if(y&1)
        {
            m=m*x;
            y--;
        }
        x*=x;
        y/=2;
    }
    return m;
}
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>n>>k)
    {
        //cout<<n<<k<<endl;
        if(k%2==1)
        {
            cout<<1<<endl;
            continue;
        }
        else
        {
            for(long long i=2; i<=50; i++)
            {
                if(((k-Pow(2,i-1))%Pow(2,i))==0)
                {
                  //  cout<<k<<" "<<Pow(2,i-1)<<" "<<Pow(2,i)<<endl;
                    cout<<i<<endl;
                    break;
                }
            }
        }
      //  cout<<Pow(n,k)<<endl;
    }
    return 0;
}
