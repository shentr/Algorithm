// 2047 ( 阿牛的EOF牛肉串 )
//acm.hdu.edu.cn/showproblem.php?pid=2047


#include<stdio.h>
int main()
{
    int n,i;
    __int64 a[43];
    while(scanf("%d",&n)!=EOF)
    {
        a[1]=3;a[2]=8;a[3]=22;
        for(i=4;i<41;i++)
        a[i]=a[i-2]*6+a[i-3]*4;
        printf("%I64d\n",a[n]);
    }
}
