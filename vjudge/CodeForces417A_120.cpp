// CodeForces417A
//http://codeforces.com/problemset/problem/417A


#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a[200010];

int main()
{
    int c,d,n,m,k;
    while(cin>>c>>d>>n>>m>>k)
    {
        int v=n*m-k;
        if(v<=0)
        {
            cout<<0<<endl;
            continue;
        }
        if(c/n>=d)
        {
            cout<<v*d<<endl;
            continue;
        }
        int t=v/n;
        int mor=v-t*n,les=mor*d;
        if(les<c)
            cout<<c*t+les<<endl;
        else
            cout<<c*t+c<<endl;
    }
}
