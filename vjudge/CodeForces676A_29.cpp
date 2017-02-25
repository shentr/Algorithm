// CodeForces676A
//http://codeforces.com/problemset/problem/676A


#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int n,a[105];
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    int maxn=1,minn=1;
    for(int i=2;i<=n;i++){
        if(a[i]>a[maxn])
            maxn=i;
        if(a[i]<a[minn])
            minn=i;
    }
    if(maxn>minn){
        if(n-maxn>minn-1)
            cout<<n-minn<<endl;
        else
            cout<<maxn-1<<endl;
    }
    else{
        if(maxn-1>n-minn)
            cout<<minn-1<<endl;
        else
            cout<<n-maxn<<endl;
    }
    return 0;
}
