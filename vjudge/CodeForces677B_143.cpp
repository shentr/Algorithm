// CodeForces677B
//http://codeforces.com/problemset/problem/677B


#include <iostream>
#include <queue>
#include <math.h>
#pragma comment(linker, £¢/STACK:102400000,102400000£¢)
using namespace std;
const int maxn=1000000005;
int a;
queue<int>q;
int main()
{
    int n,h,k;
    while(cin>>n>>h>>k)
    {
        while(!q.empty())
            q.pop();
        long long top=0,sum=0,ans=0;
        for(int i=1; i<=n; i++)
        {
            cin>>a;
            q.push(a);
        }

        while(!q.empty())
        {
            top=q.front();
            q.pop();
            if(top+sum<=h)
            {
                sum+=top;
            }
            else
            {
                sum=top;
                ans++;

            }
            ans+=sum/k;
            sum=sum%k;
        }

        ans+=sum/k;
        if(sum%k>0)
            ans++;
        cout<<ans<<endl;
    }
    return 0;
}
