// 2002 ( 计算球体积 )
//acm.hdu.edu.cn/showproblem.php?pid=2002


#include<stdio.h>
#define PI 3.1415927
int main()
{double V,R;
while(scanf("%lf",&R)!=EOF)
{V=PI*R*R*R*4/3;
printf("%.3lf\n",V);}
return 0;
}
