// 2045 ( 不容易系列之(3)—— LELE的RPG难题 )
//acm.hdu.edu.cn/showproblem.php?pid=2045


#include<stdio.h>

int main()
{
    int n,i;
    __int64 a[53];
    while(scanf("%d",&n)!=EOF)
    {
        a[1]=3;a[2]=6;a[3]=6;
        for(i=4;i<=n;i++)
            a[i]=a[i-1]+a[i-2]*2;
        printf("%I64d\n",a[n]);
    }
    return 0;
}
