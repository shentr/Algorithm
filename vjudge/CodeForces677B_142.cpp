// CodeForces677B
//http://codeforces.com/problemset/problem/677B


#include <iostream>
#include <queue>
#include <math.h>
#pragma comment(linker, £¢/STACK:102400000,102400000£¢)
using namespace std;
const int maxn=10000005;
int a[maxn];
int main()
{
    int n,h,k;
    while(cin>>n>>h>>k)
    {
        long long sum=0,ans=0;
        for(int i=1; i<=n; i++)
        {
            cin>>a[i];
        }
        for(int i=1;i<=n;i++)
        {
            if(a[i]+sum<=h)
            {
                sum+=a[i];
            }
            else
            {
                sum=a[i];
                ans++;

            }
            ans+=sum/k;
            sum=sum%k;
        }

       if(sum)
    ans++;
        cout<<ans<<endl;
    }
    return 0;
}
