// CodeForces412B
//http://codeforces.com/problemset/problem/412B


#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int n,k,a[105];
    while(cin>>n>>k)
    {
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        sort(a,a+n);
        cout<<a[n-k]<<endl;
    }
}
