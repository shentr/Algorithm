// 2016 ( 数据的交换输出 )
//acm.hdu.edu.cn/showproblem.php?pid=2016


#include<stdio.h>
int main()
{
    int a[10000],i,n,min=0,c=0,t=0;
    while(scanf("%d",&n)!=EOF)
    {
        min=0;
        c=0;
        t=0;
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        min=a[1];
        for(i=2;i<=n;i++)
        {
            if(min>a[i])
            {
                min=a[i];
                c=i;
            }
        }
        a[c]=min;
        t=a[1];
        a[1]=a[c];
        a[c]=t;
        for(i=1;i<=n;i++)
        {
            if(i==n)
                printf("%d\n",a[i]);
            else
                printf("%d ",a[i]);
        }
    }
    return 0;
}