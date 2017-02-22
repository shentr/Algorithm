// 2048 ( 神、上帝以及老天爷 )
//acm.hdu.edu.cn/showproblem.php?pid=2048


#include <stdio.h>
int main()
{
    int i,t,n;
    double a[25];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        a[1]=0;a[2]=1;
        for(i=3;i<=n;i++)
       a[i]=(i-1)*(a[i-1]+a[i-2]);
        for(i=1;i<=n;i++)
        a[n]/=i;
    printf("%.2lf%%\n",a[n]*100);
    }
    return 0;
}
