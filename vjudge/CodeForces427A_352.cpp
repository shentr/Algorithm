// CodeForces427A
//http://codeforces.com/problemset/problem/427A


#include <iostream>

using namespace std;
int a[100005];
int main()
{
    int n;
    while(cin>>n)
    {
        int sum=0,maxn=0;
        for(int i=1; i<=n; i++)
            cin>>a[i];
        for(int i=1; i<=n; i++)
        {
            if(a[i]==-1)
                sum++;
            else sum=sum-a[i];
            maxn=max(maxn,sum);
        }
        cout<<maxn<<endl;
    }
    return 0;
}
