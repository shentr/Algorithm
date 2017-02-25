// CodeForces7C
//http://codeforces.com/problemset/problem/7C


#include<iostream>
using namespace std;

typedef long long LL;

LL gcd(LL a,LL b)
{
    return b==0?a:gcd(b,a%b);
}

void extend_Euclid(LL a, LL b, LL &x, LL &y)
{
    if(b==0)
    {
        x=1;
        y=0;
        return;
    }
    extend_Euclid(b, a % b, x, y);
    LL temp=x;
    x=y;
    y=temp-(a/b)*y;
}

int  main()
{
    LL a,b,c;
    while(cin>>a>>b>>c)
    {
        c=-c;
        if(a==0&b==0)
        {
            cout<<"-1"<<endl;
            continue;
        }
        LL d=gcd(a,b);
        if(c%d)
        {
            cout<<"-1"<<endl;
            continue;
        }
        a/=d;
        b/=d;
        c/=d;
        LL x,y;
        extend_Euclid(a,b,x,y);
        x*=c;
        y*=c;
        if(x>=-5*1e18&&x<=5*1e18&&y>=-5*1e18&&y<=5*1e18)
        cout<<x<<" "<<y<<endl;
        else
        cout<<"-1"<<endl;
    }
}


