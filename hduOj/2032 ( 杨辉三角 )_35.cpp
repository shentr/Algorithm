// 2032 ( 杨辉三角 )
//acm.hdu.edu.cn/showproblem.php?pid=2032


#include <stdio.h>
int main()
{
    int n,i,j;
    int a[32][32]={{1}};
    while(scanf("%d",&n)!=EOF)
    {
    for(i=1;i<=n;i++)
        for(j=1;j<=i;j++)
        {
            a[i][j]=a[i-1][j]+a[i-1][j-1];
            if(i!=j)
                printf("%d ",a[i][j]);
            else
                printf("%d\n",1);
        }
        printf("\n");
    }
    return 0;
}
