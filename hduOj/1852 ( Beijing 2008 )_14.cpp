// 1852 ( Beijing 2008 )
//acm.hdu.edu.cn/showproblem.php?pid=1852


#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;

LL quick_mod(LL a,LL b,int k)
{
    LL ans=1;
    while(b>0)
    {
        if(b&1)
        {
            ans=ans*a%k;
        }
        a=a*a%k;
        b>>=1;
    }
    return ans;
}

int main()
{
    int n,k;
    while(cin>>n>>k&&(n||k))
    {
        LL m,m1;
        m=((quick_mod(8,n,k)*2-1)%k);
        m=(m>=0?m:m+k);
        m1=(quick_mod(251,n+1,250*k)-1)/250;
        m1=(m1>=0?m1:m1+k);
        m=m*m1%k;
        cout<<quick_mod(2008,m,k)<<endl;
        //cout<<m;
    }
}
