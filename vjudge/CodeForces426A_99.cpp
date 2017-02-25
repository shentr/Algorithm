// CodeForces426A
//http://codeforces.com/problemset/problem/426A


#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    int n,s;
    while(cin>>n>>s)
    {
        int a[105];
        int m=-1000,sum=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            if(m<a[i])
            {
                m=a[i];
            }
            sum+=a[i];
        }
        if(sum-m<=s)
        {
           cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
