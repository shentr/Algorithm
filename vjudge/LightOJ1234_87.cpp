// LightOJ1234
//http://lightoj.com/login_main.php?url=volume_showproblem.php?problem=1234


#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
const double r=0.57721566490153286060651209;
double a[10000];

int main()
{
    a[1]=1;
    for (int i=2;i<10000;i++)
    {
        a[i]=a[i-1]+1.0/i;
    }
    int n;
    cin>>n;
    for (int kase=1;kase<=n;kase++)
    {
        int n;
        cin>>n;
        if (n<10000)
        {
            printf("Case %d: %.10lf\n",kase,a[n]);
        }
        else
        {
            double a=log(n)+r+1.0/(2*n);
            //double a=log(n+1)+r;
            printf("Case %d: %.10lf\n",kase,a);
        }
    }
    return 0;
}
