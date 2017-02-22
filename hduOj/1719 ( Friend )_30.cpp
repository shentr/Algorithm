// 1719 ( Friend )
//acm.hdu.edu.cn/showproblem.php?pid=1719


#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    long long n;
    while(cin>>n)
    {
        if(n==0)
        {
            cout<<"NO!"<<endl;
            continue;
        }
        n++;
        while(n%3==0)
            n/=3;
        while(n%2==0)
            n/=2;
        if(n==1)
            cout<<"YES!"<<endl;
        else
            cout<<"NO!"<<endl;
    }
}
