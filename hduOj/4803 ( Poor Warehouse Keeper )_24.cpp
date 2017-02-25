// 4803 ( Poor Warehouse Keeper )
//acm.hdu.edu.cn/showproblem.php?pid=4803


#include"bits/stdc++.h"
#define fs 1e-6
using namespace std;

double a[15],x,y;
int ans,n;

int main()
{
    //ios::sync_with_stdio(false);
    while (~scanf("%lf%lf",&x,&y))
    {
        ans=(int)(x-1);
        y-=x-1+fs;
        if (y<0)
        {
            puts("-1");
            continue;
        }
        for(int i=1; i<=x; i++)
            a[i]=x/i;
        for(int i=1; i<=x; i++)
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