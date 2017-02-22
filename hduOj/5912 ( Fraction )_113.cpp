// 5912 ( Fraction )
//acm.hdu.edu.cn/showproblem.php?pid=5912


#include <iostream>
#include <string.h>
using namespace std;
int T;
long long a[20],b[20];
int n;
long long gcd(long long x,long long y)
{
    return y?gcd(y,x%y):x;
}
int main()
{
    ios::sync_with_stdio(false);
    int cases=1;
    cin>>T;
    while(T--)
    {
        cin>>n;
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        for(int i=1;i<=n;i++)
            cin>>a[i];
        for(int i=1;i<=n;i++)
            cin>>b[i];
            long long nn=n;
        long long fz=b[nn];
        long long fm=a[nn];
        for(int i=nn-1;i>=1;i--)
        {
            long long fz2=b[i]*fm;
            long long  fm2=fm*a[i]+fz;
           // cout<<fz2<<" "<<fm2<<endl;
            long long chu=gcd(fz2,fm2);
           // cout<<chu<<endl;
            if(chu!=0)
            {
                fz=fz2/chu;
               // cout<<fz<<" "<<fz2<<" "<<chu<<endl;
                fm=fm2/chu;
                // cout<<fm<<" "<<fm2<<" "<<chu<<endl;
            }
        }
        long long g=gcd(fz,fm);
        fz=fz/g,fm=fm/g;
        cout<<"Case #"<<cases++<<": ";
        cout<<fz<<" "<<fm<<endl;
    }
    return 0;
}