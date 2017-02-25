// 5912 ( Fraction )
//acm.hdu.edu.cn/showproblem.php?pid=5912


#include <iostream>
#include <string.h>
using namespace std;
long long T;
long long a[20],b[20];
long long n;

long long gcd(long long a,long long b)
{
    return b==0?a:gcd(b,a%b);
}

int main()
{
    ios::sync_with_stdio(false);
    long long cases=1;
    cin>>T;
    while(T--)
    {
        cin>>n;
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        for(long long i=1;i<=n;i++)
            cin>>a[i];
        for(long long i=1;i<=n;i++)
            cin>>b[i];
        long long fz=b[n],fm=a[n],fz2,fm2;
        for(long long i=n-1;i>=1;i--)
        {
            fz2=b[i]*fm;
            fm2=fm*a[i]+fz;
            //cout<<fz2<<" "<<fm2<<endl;
            //long long chu=gcd(fz2,fm2);
           // cout<<chu<<endl;
            //fz=fz2/chu;
            fz=fz2,fm=fm2;
               // cout<<fz<<" "<<fz2<<" "<<chu<<endl;
            //fm=fm2/chu;
                //cout<<fm<<" "<<fm2<<" "<<chu<<endl;
        }
        long long g=gcd(fz,fm);
        fz=fz/g,fm=fm/g;
        cout<<"Case #"<<cases++<<": ";
        cout<<fz<<" "<<fm<<endl;
    }
    return 0;
}

/*
1
8
8 8 8 8 8 8 8 8
8 8 8 8 8 8 8 8
64 72
72 80
80 89
712 792
792 881
7048 7840
7840 8721
Case #1: 7840 8721

1
8
8 8 8 8 8 8 8 8
8 8 8 8 8 8 8 8
64 72
576 640
5120 5696
45568 50688
405504 451072
3608576 4014080
32112640 35721216
Case #1: 32112640 35721216
*/
