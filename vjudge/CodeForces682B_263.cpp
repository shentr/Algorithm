// CodeForces682B
//http://codeforces.com/problemset/problem/682B


#include"iostream"
#include"cstdio"
#include"algorithm"
using namespace std;
const int maxn = 1e5+7;
int n,a[maxn];

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+1+n);
    int ha=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]>ha)
            ha++;
    }
    ha++;
    cout<<ha<<endl;
}
