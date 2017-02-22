// 1019 ( Least Common Multiple )
//acm.hdu.edu.cn/showproblem.php?pid=1019


#include<iostream>
using namespace std;
typedef long long ll;

ll gcd(ll a,ll b)
{
    return b==0?a:gcd(b,a%b);
}

ll lgm(ll a,ll b)
{
    return a/gcd(a,b)*b;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,a;
        ll ans=1;
        cin>>n;
        while(n--)
        {
            cin>>a;
            ans=lgm(ans,a);
        }
        cout<<ans<<endl;
    }
}
