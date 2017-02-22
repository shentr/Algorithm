// 2015 ( 偶数求和 )
//acm.hdu.edu.cn/showproblem.php?pid=2015


#include<stdio.h>
int main()
{
    int n,m,a[100],i,j,w;
    while(~scanf("%d%d",&n,&m))
    {
        a[0]=2;
        for(i=1;i<n;i++)
            a[i]=a[i-1]+2;
        if(n%m==0)
        {
            for(i=0;i<n-m;i=i+m)
            {
                w=0;
                for(j=i;j<i+m;++j)
                    w+=a[j];
                printf("%d ",w/m);
            }
            w=0;
            for(j=i;j<i+m;j++)
                w+=a[j];
            printf("%d\n",w/m);
        }
        else
        {
            for(i=0;i<n-(n%m);i=i+m)
            {
                w=0;
                for(j=i;j<i+m;++j)
                    w+=a[j];
                printf("%d ",w/m);
            }
            w=0;
            for(j=i;j<i+n%m;j++)
                w+=a[j];
        printf("%d\n",w/(n%m));
        }
    }
    return 0;
}
