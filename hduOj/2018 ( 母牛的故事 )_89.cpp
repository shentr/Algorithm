// 2018 ( 母牛的故事 )
//acm.hdu.edu.cn/showproblem.php?pid=2018


#include<stdio.h>
int main()
{
    int a[10000],n,i;
    while(scanf("%d",&n)!=EOF)
        {if(n==0)
        break;
         if (n<=3)
           a[n]=n;
        if(n>3)
       {
           for(i=4;i<=n;i++)
          {
              a[1]=1;a[2]=2;a[3]=3;
              a[i]=a[i-1]+a[i-3];
           }
        }
         printf("%d\n",a[n]);
        }
        return 0;
}

