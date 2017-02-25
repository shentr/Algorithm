// CodeForces424C
//http://codeforces.com/problemset/problem/424C


#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std ;
typedef long long ll;
ll a[1000010] ;
ll m ;

int main()
{
    int n;
    a[0]=0;
    a[1]=1;
    for(int i=2;i<1000010;i++)
        a[i]=a[i-1]^i;
    while(cin>>n)
    {
        ll yh=0 ;
        for(int i=1;i<=n;i++)
        {
            scanf("%I64d",&m);
            yh = yh ^ m ;
        }
        for(int i=2;i<=n;i++)
        {
            int md=n%i;
            int d=n/i ;
            if(d%2)
            {
                yh^=a[i-1] ;
                if(md!=0)
                yh^=a[md] ;
            }
            else
            {
                if(md!=0)
                    yh^=a[md] ;
            }
        }
        cout<<yh<<endl;
    }
    return 0 ;
}
