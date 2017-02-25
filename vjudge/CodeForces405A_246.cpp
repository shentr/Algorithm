// CodeForces405A
//http://codeforces.com/problemset/problem/405A


#include <iostream>
#include <algorithm>
using namespace std;
int a[105];
int n;
int main()
{
    while(cin>>n)

    {
        for(int i=0;i<n;i++)
            cin>>a[i];
        sort(a,a+n);
        for(int i=0;i<n-1;i++)
            cout<<a[i]<<" ";
        cout<<a[n-1]<<endl;
    }
    return 0;
}
