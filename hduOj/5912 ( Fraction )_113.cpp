// 5912 ( Fraction )
//acm.hdu.edu.cn/showproblem.php?pid=5912


#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int gcd(int a,int b)
{
    if(b==0)
        return a;
    else return gcd(b,a%b);
}

int lcm(int a,int b)
{
    return a*b/gcd(a,b);
}

int main()
{
    int T;
    int n;
    int a[20],b[20];
    int casenum=1;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(int i=0;i<n;i++)
        {
            scanf("%d",&b[i]);
        }
        int fenzi,fenmu;
        fenzi=b[n-1];
        fenmu=a[n-1];
        int tmp;
        //cout<<fenzi<<"hfdksjf1111   "<<fenmu<<endl;
        for(int i=n-2;i>=0;i--)
        {

            fenzi=fenzi+a[i]*fenmu;
            fenmu=fenmu;
            //cout<<fenzi<<"hfdksjf2222   "<<fenmu<<endl;
            tmp=fenzi;
            fenzi=b[i]*fenmu;
            fenmu=tmp;
            //cout<<fenzi<<"hfdksjf333   "<<fenmu<<endl;
        }
        int d=gcd(fenzi,fenmu);
        printf("Case #%d: ",casenum++);
        printf("%d %d\n",fenzi/d,fenmu/d);
    }
    return 0;
}
