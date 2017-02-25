// CodeForces7C
//http://codeforces.com/problemset/problem/7C


#include<iostream>
#include<cstdio>
using namespace std;
typedef long long LL;
const LL N=5e18;

LL x,y;
LL gcd(LL a,LL b)
{
    LL temp,d;
    if(b==0)
    {
        x=1,y=0;
        return a;
    }
    d=gcd(b,a%b);
    temp=x,x=y,y=temp-(a/b)*y;
    return d;
}

int main()
{
    LL a,b,c;
    cin>>a>>b>>c;
    c=-c;
    if(a<0&&b<0)
    {
        a=-a,b=-b,c=-c;
    }
    if(c==0)
    {
        cout<<0<<' '<<0<<endl;
        return 0;
    }
    if(a==0)
    {
        if(c%b==0)
            cout<<0<<' '<<c/b<<endl;
        else
            cout<<-1<<endl;
        return 0;
    }
    if(b==0)
    {
        if(c%a==0)
            cout<<0<<' '<<c/a<<endl;
        else
            cout<<-1<<endl;
        return 0;
    }
    LL g=gcd(a,b);
    if(c%g!=0)
    {
        cout<<-1<<endl;
        return 0;
    }
    x*=c/g,y*=c/g;
    //if(x<-N)
   // {
       // LL k=(-N-x)*g/b;
      //  if(b*g<0)
      //  {
      //      k--;///
      //      while(k)
       // }
      //  else
      //  {
      //      k++;///
      //  }

   //}
    cout<<x<<' '<<y<<endl;
    return 0;
}
