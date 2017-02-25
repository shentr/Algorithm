// CodeForces733B
//http://codeforces.com/problemset/problem/733B


#include <iostream>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;
int a[100005],b[100005];
int main()
{
    ios::sync_with_stdio(false);
    int n;
    while(cin>>n)
    {
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        int l=0,r=0,ans=0,mid=0;
        int maxn=0,minn=99999999;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i]>>b[i];
            l+=a[i];
            r+=b[i];
        }
        ans=abs(l-r);
        int flag=0;
       for(int i=1;i<=n;i++)
       {
           if(abs((l-a[i]+b[i])-(r+a[i]-b[i]))>ans)
           {
               ans=abs((l-a[i]+b[i])-(r+a[i]-b[i]));
//               cout<<ans<<endl;
//              l=l-a[i]+b[i];
//              r=r+a[i]-b[i];
              flag=i;
//              l=l+a[flag]-b[flag];
//              r=r-a[flag]+b[flag];
//              cout<<l<<" "<<r<<endl;

           }
       }
       cout<<flag<<endl;
    }
    return 0;
}
