// 1492 ( The number of divisors(约数) about Humble Numbers )
//acm.hdu.edu.cn/showproblem.php?pid=1492


#include<iostream>
using namespace std;
typedef long long ll;

int main()
{
    ll n;
    while(cin>>n&&n)
    {
        int ans,x=0;
        while(n%2==0)
        {
            n/=2;
            x++;
        }
        ans=x+1;
        x=0;
        while(n%3==0)
        {
            n/=3;
            x++;
        }
        ans=ans*(x+1);
        x=0;
        while(n%5==0)
        {
            n/=5;
            x++;
        }
        ans=ans*(x+1);
        x=0;
        while(n%7==0)
        {
            n/=7;
            x++;
        }
        ans=ans*(x+1);
        cout<<ans<<endl;
    }
}
