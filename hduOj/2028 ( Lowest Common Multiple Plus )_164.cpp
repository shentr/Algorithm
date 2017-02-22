// 2028 ( Lowest Common Multiple Plus )
//acm.hdu.edu.cn/showproblem.php?pid=2028


#include<stdio.h>
int main()
{
    int n,i,a[1000],max;
    while(scanf("%d",&n)!=EOF)
    {
        max=0;
        for(i=2;i<=n+1;i++)
        {
            scanf("%d",&a[i]);
            if(a[i]>max) max=a[i];
        }
        for(i=2;i<=n+1;i++)
        {
           if(max%a[i]!=0)
                {max++;i=1;}
        }
        printf("%d\n",max);
    }
    return 0;
}
