// 1124 ( Factorial )
//acm.hdu.edu.cn/showproblem.php?pid=1124


#include<iostream>
using namespace std;

int main()
{
    int t;

    cin>>t;
    while(t--)
    {
        int n,tmp=0;

        cin>>n;
        while(n)
        {
            tmp+=n/5;
            n/=5;
        }

        cout<<tmp<<endl;
    }

    return 0;
}
