// CodeForces407B
//http://codeforces.com/problemset/problem/407B


#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const long long mod=1e9+7;
const int N=1e3+5;

int main()
{
    int n,p[N];
    while(cin>>n)
    {
        for(int i=0;i<n;i++)
            cin>>p[i];
        long long a[1005];
        a[0]=0;
        for(int i=1;i<=n;i++)
        {
            int m=2*a[i-1]-a[p[i-1]-1]+2;
            if(m>0)
            a[i]=m%mod;
            else
                a[i]=(m+mod)%mod;
        }
        cout<<a[n]%mod<<endl;
    }
}
