// CodeForces412B
//http://codeforces.com/problemset/problem/412B


#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int main()
{
    int a[105];
    int n,m;
    while(cin>>n>>m)
    {
        memset(a,0,sizeof(a));
        for(int i=0;i<n;i++)
            cin>>a[i];
        sort(a,a+n);
        cout<<a[n-m]<<endl;
    }
    return 0;
}
