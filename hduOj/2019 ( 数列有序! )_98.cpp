// 2019 ( 数列有序! )
//acm.hdu.edu.cn/showproblem.php?pid=2019


#include<stdio.h>
#include<stdlib.h>

int cmd(const void *a,const void *b)
{
    return (*(int*)a-*(int*)b);
}
int main()
{
    int a[103],i,n,m;
    while(scanf("%d%d",&n,&m),(n!=0)&&(m!=0))
    {
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
            a[n]=m;
        qsort(a,n+1,sizeof(a[0]),cmd);
        for (i=0;i<=n;i++)
            {
                if(i>0)
                    printf(" ");
                printf("%d",a[i]);
            }
            printf("\n");
    }
    return 0;
}
