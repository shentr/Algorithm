// HDU5078
//http://acm.hdu.edu.cn/showproblem.php?pid=5078


#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;
const int maxn=1005;
double t[maxn],x[maxn],y[maxn];
int main()
{
    int T,n;
    //cin>>T;
    scanf("%d",&T);
    while(T--)
    {
        memset(t,0,sizeof(t));
        memset(x,0,sizeof(x));
        memset(y,0,sizeof(y));
        double sum=-1.0;
        //cin>>n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
           //cin>>t[i]>>x[i]>>y[i];
           scanf("%lf%lf%lf",&t[i],&x[i],&y[i]);
        }

        for(int i=2;i<=n;i++)
        {
              // cout<<1.0*sqrt((x[i]-x[i-1])*(x[i]-x[i-1])+(y[i]-y[i-1])*(y[i]-y[i-1]))/(t[i]-t[i-1])<<endl;
            sum=max(sum,sqrt((x[i]-x[i-1])*(x[i]-x[i-1])+(y[i]-y[i-1])*(y[i]-y[i-1]))/(t[i]-t[i-1]));
        }
        printf("%.10lf\n",sum);
    }
    return 0;
}
