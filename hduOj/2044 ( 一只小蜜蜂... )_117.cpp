// 2044 ( 一只小蜜蜂... )
//acm.hdu.edu.cn/showproblem.php?pid=2044


#include<stdio.h>
int main()
{
    int n,a,b,N,i;
    __int64 f[1000];
    scanf("%d",&N);
    while(N--)
    {
        scanf("%d%d",&a,&b);
        if(a>b) printf("0\n");
        else
        {n=b-a;
        f[0]=1;f[1]=1;
        for(i=2;i<=n;i++)
        {
            f[i]=f[i-1]+f[i-2];
        }
        printf("%I64d\n",f[n]);
        }
    }
}
