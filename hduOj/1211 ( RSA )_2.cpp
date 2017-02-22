// 1211 ( RSA )
//acm.hdu.edu.cn/showproblem.php?pid=1211


#include<iostream>
#include<cstdio>
using namespace std;

long long x,y,d;
long long gcd(long long a,long long b)
{
    if(b==0)
    {
        x=1,y=0;
        d=a;
        return a;
    }
    gcd(b,a%b);
    long long t=x;
    x=y;
    y=t-a/b*y;
    return d;
}

int main()
{
    long long p,q,e,L;
    while(cin>>p>>q>>e>>L){
    long long n=p*q,fn=(p-1)*(q-1);
    gcd(e,fn);
    long long d=x>0?(x%fn):(x%fn+fn);
    //cout<<d<<endl;
    while(L--)
    {
        long long m;
        cin>>m;
        long long M=1;
        long long dd=d;
        while(dd--)
        {
            M=M*m%n;
        }
        M%=n;
        cout<<(char)M;
    }
    cout<<endl;
    }
}
