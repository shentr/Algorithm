// 2046 ( 骨牌铺方格 )
//acm.hdu.edu.cn/showproblem.php?pid=2046


#include <stdio.h>
int main()
{
    int n,i;
    __int64 a[51];
    while (scanf("%d",&n)!=EOF)
        {
            a[1]=1;a[2]=2;a[3]=3;
            for (i=3;i<51;i++)
            a[i]=a[i-1]+a[i-2];
            printf("%I64d\n", a[n]);
        }
    return 0;
}
