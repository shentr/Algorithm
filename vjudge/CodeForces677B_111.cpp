// CodeForces677B
//http://codeforces.com/problemset/problem/677B


#include"bits/stdc++.h"
using namespace std;
typedef long long ll;

int main()
{
    ll n,h,ans=0,hh=0,x,k;
    cin>>n>>h>>k;
    for(ll i=0; i<n; i++)
    {
        cin>>x;
        if (hh + x <= h)
            hh += x;
        else
        {
            ans++;
            hh = x;
        }
        ans += hh/k;
        hh %= k;
    }
    ans += hh/k;
    hh %= k;
    if(hh>0)
        ans++;
    cout<<ans<<endl;
    return 0;
}
