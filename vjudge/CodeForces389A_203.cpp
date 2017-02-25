// CodeForces389A
//http://codeforces.com/problemset/problem/389A


#include <iostream>

using namespace std;
int a[105];
int s,n;
int gcd(int a,int b)
{
    int c;
    if(a>b)
    {
        c=a;
        a=b;
        b=c;
    }
    if(a==0)
        return b;
    else if(b==0)
        return a;
    else return gcd(a,b%a);
}
int main()
{
    while(cin>>n)
    {
        for(int i=1;i<=n;i++)
        cin>>a[i];
        s=gcd(a[1],a[2]);
        for(int i=3;i<=n;i++)
        {
            s=gcd(s,a[i]);
        }
        cout<<n*s<<endl;

    }
    return 0;
}
