// CodeForces686B
//http://codeforces.com/problemset/problem/686B


#include <iostream>
#include <string.h>
using namespace std;
long long a[20005];
int n;
int main()
{
    while(cin>>n)
    {
        memset(a,0,sizeof(a));
        for(int i=1;i<=n;i++)
            cin>>a[i];
        for(int i=1;i<n;i++)
            for(int j=1;j<=n;j++)
        {
            if(a[j-1]>a[j])
            {
                long long t=a[j-1];
                a[j-1]=a[j];
                a[j]=t;
                cout<<j-1<<" "<<j<<endl;
            }
        }
    }
    return 0;
}
