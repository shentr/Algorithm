// 1239 ( Calling Extraterrestrial Intelligence Again )
//acm.hdu.edu.cn/showproblem.php?pid=1239


#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

bool is_prime(int x)
{
    for(int i=2;i*i<=x;i++)
    {
        if(x%i==0)
            return false;
    }
    return true;
}

int main()
{
    int m,a,b;
    while(cin>>m>>a>>b&&!(m==0&&a==0&&b==0))
    {
        int maxpq=0,maxq=sqrt(m*b/a),maxp=sqrt(m),maxi,maxj;
        //cout<<maxq<<' '<<maxp<<endl;
        for(int i=maxq;i>=0;i--)
        {
            if(!is_prime(i))
                continue;
            for(int j=maxp;j*b>=a*i;j--)
            {
                if(!is_prime(j)||i*j>m)
                continue;
                if(i*j>maxpq)
                {
                    maxpq=i*j;
                    maxi=i;
                    maxj=j;
                }
            }
        }
        cout<<maxj<<' '<<maxi<<endl;
    }
    return 0;
}
