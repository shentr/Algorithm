// 2010 ( 水仙花数 )
//acm.hdu.edu.cn/showproblem.php?pid=2010


#include<stdio.h>
int main()
{
    int i,j,n,m,a,b,c;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        for(i=m,j=0;i<=n;i++)
        {
            a=i/100;b=i/10%10;c=i%10;
            if(a*a*a+b*b*b+c*c*c==i)
            {
              if(j>0) printf(" %d",i);
              else printf("%d",i);
              j++;
            }
        }
        if(j==0) printf("no");
        printf("\n");
    }
}
