// 1211 ( RSA )
//acm.hdu.edu.cn/showproblem.php?pid=1211


#include<iostream>
#include<cstdio>
using namespace std;

int x,y,d;
int gcd(int a,int b)
{
    if(b==0)
    {
        x=1,y=0;
        d=a;
        return a;
    }
    gcd(b,a%b);
    int t=x;
    x=y;
    y=t-a/b*y;
    return d;
}

int main()
{
    int p,q,e,L;
    while(cin>>p>>q>>e>>L){
    long long n=p*q,fn=(p-1)*(q-1);
    gcd(e,fn);
    int d=x>0?(x%fn):(x%fn+fn);
    while(L--)
    {
        int m;
        cin>>m;
        long long M=1;
        int dd=d;
        while(dd--)
        {
            M=M*m%n;
        }
        M%=n;
        printf("%c",M);
    }
    cout<<endl;
    }
}


