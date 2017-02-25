// CodeForces417B
//http://codeforces.com/problemset/problem/417B


#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a[100005];

int main()
{
    int n;
    while(cin>>n)
    {
        memset(a,-1,sizeof(a));
        int flag=0;
        for(int i=0;i<n;i++)
        {
            int x,k;
            cin>>x>>k;
            if(a[k]<x-1)
                flag=1;
            a[k]=max(a[k],x);
        }
        if(flag)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
    }
}
