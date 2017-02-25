// CodeForces390B
//http://codeforces.com/problemset/problem/390B


#include <iostream>
#include <string.h>
using namespace std;
long long a[1000007],b[1000007];
int main()
{
    long long n;
    while(cin>>n)
    {
        long long sum=0;
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        for(int i=1;i<=n;i++)
        {
            cin>>b[i];
        }
        for(int i=1;i<=n;i++)
        {
            if(2*a[i]<b[i]||b[i]==1)
                sum--;
                else sum+=(b[i]/2)*(b[i]-b[i]/2);
        }
        cout<<sum<<endl;
    }
    return 0;
}
