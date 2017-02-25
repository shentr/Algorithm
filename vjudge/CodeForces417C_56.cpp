// CodeForces417C
//http://codeforces.com/problemset/problem/417C


#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
    int n,k,t;
    while(cin>>n>>k)
    {
        t=n*(n-1)/2;
        if(k>t/n)
        {
            cout<<"-1"<<endl;
            continue;
        }
        cout<<n*k<<endl;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=k;j++)
            printf("%d %d\n",i,(i+j-1)%n+1);
    }
}
