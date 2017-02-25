// 1395 ( 2^x mod n = 1 )
//acm.hdu.edu.cn/showproblem.php?pid=1395


#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;

int main()
{
    ll n;
    while(cin>>n)
    {
        if(n%2==0||n==1)
        {
            cout<<"2^? mod "<<n<<" = 1"<<endl;
            continue;
        }
        ll ji=1;
        for(int x=1;;x++)
        {
            ji*=2;
            ji%=n;
            if(ji==1)
            {
                cout<<"2^"<<x<<" mod "<<n<<" = 1"<<endl;
                break;
            }
        }
    }
}
