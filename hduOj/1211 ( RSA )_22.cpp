// 1211 ( RSA )
//acm.hdu.edu.cn/showproblem.php?pid=1211


#include<iostream>
#include<cstdio>
using namespace std;

int x,y,xx,yy;
int gcd(int a,int b)
{
    if(b==0)
        return a;
    int tx=x,ty=y;
    x=xx,y=yy;
    xx=tx-a/b*xx,yy=ty-a/b*yy;
    gcd(b,a%b);
}

int main()
{
    int p,q,e,L;
    while(~scanf("%d%d%d%d",&p,&q,&e,&L)){
    long long n=p*q,fn=(p-1)*(q-1);
    x=1,y=0,xx=0,yy=1;
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


