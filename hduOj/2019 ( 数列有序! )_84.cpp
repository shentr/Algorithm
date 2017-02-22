// 2019 ( 数列有序! )
//acm.hdu.edu.cn/showproblem.php?pid=2019


#include<stdio.h>
void main()
{
    int n,m,a[101],i;
    while(scanf("%d%d",&n,&m)!=EOF && (n||m)){
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        for(i=0;i<n;i++)
            if(m>a[i])
                printf("%d ",a[i]);
            else    break;
        printf("%d",m);
        for(;i<n;i++)
            printf(" %d",a[i]);
        puts("");
    }
}