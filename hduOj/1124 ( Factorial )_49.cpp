// 1124 ( Factorial )
//acm.hdu.edu.cn/showproblem.php?pid=1124


#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long n;
        cin>>n;
        long long i=1;
        int sum=0;
        while(i*5<=n)
        {
            i*=5;
            sum+=n/i;
        }
        //sum-=n/i;
        cout<<sum<<endl;
    }
}
