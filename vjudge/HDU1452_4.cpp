// HDU1452
//http://acm.hdu.edu.cn/showproblem.php?pid=1452


#include<iostream>
using namespace std;
typedef long long ll;
//const int mod=29;
int a[]={1, 6, 16, 8, 10, 25, 7, 14, 3, 23, 17, 13, 17, 0, 27, 7, 14, 15, 17, 26, 26, 20, 17, 9, 22, 22, 23, 0};

int main()
{
    ll n;
    while(cin>>n&&n)
    {
        cout<<a[n%28]<<endl;
    }
    return 0;
}