// 1788 ( Chinese remainder theorem again )
//acm.hdu.edu.cn/showproblem.php?pid=1788


#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
    long long n,a,m,g;
    while(cin>>n>>a&&(n||a))
    {
        cin>>g;
        for(int i=1;i<n;i++)
        {
            cin>>m;
            g=g/__gcd(g,m)*m;
        }
        cout<<g-a<<endl;
    }
}
