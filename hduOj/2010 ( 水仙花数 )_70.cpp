// 2010 ( 水仙花数 )
//acm.hdu.edu.cn/showproblem.php?pid=2010


#include<stdio.h>
#include<math.h>
int main()
{
    int a[10]={153,370,371,407},c,d,i,j[10],n,m; 
    while(~scanf("%d%d",&n,&m))
    {
        if(n>m)
        n^=m^=n^=m;
        d=0;
        for(i=0;i<4;i++)
            if(a[i]<=m&&a[i]>=n)
            {
                j[d]=i;
                d++;
            }
        if(d)
        {
            for(i=0;i<d-1;i++)
                printf("%d ",a[j[i]]);
            printf("%d\n",a[j[i]]); }
        else
            printf("no\n");
     }
     return 0;
 }
