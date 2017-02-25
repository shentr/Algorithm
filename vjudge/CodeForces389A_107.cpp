// CodeForces389A
//http://codeforces.com/problemset/problem/389A


#include<iostream>
#include<cstdio>
using namespace std;

int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}

int main()
{
    int n;
    while(cin>>n)
    {
        int a,g;
        cin>>a;
        g=a;
        for(int i=2;i<=n;i++)
        {
            cin>>a;
            g=gcd(g,a);
        }
        cout<<n*g<<endl;
    }
}
