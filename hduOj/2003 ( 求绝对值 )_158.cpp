// 2003 ( 求绝对值 )
//acm.hdu.edu.cn/showproblem.php?pid=2003


#include<stdio.h>
int main()
{double a;
while(scanf("%lf",&a)!=EOF)
{if (a>0)
printf("%.2lf\n",a);
else
printf("%.2lf\n",-a);}
return 0;
}
