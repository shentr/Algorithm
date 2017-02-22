// 4803 ( Poor Warehouse Keeper )
//acm.hdu.edu.cn/showproblem.php?pid=4803


#include <cstdio>
#include <cmath>
#define eps 1e-5
using namespace std;

double a[15],x,y;
int ans,n;

int main()
{
    while (scanf("%lf%lf",&x,&y)!=EOF)
    {
        ans=(int)(x-1);
        y-=x-1+eps;
        if (y<0)
        {
            printf("-1\n");
            continue;
        }
        for (int i=1; i<=x; i++) a[i]=x/i;
        for (int i=1; i<=x; i++)
        {
            n=(int)(y/a[i]);
            ans+=n;
            y-=n*a[i];
            if (y<1) break;
        }
        printf("%d\n",ans);
    }
    return 0;
}
