// 2001 ( 计算两点间的距离 )
//acm.hdu.edu.cn/showproblem.php?pid=2001


#include<stdio.h>
#include<math.h>
int main()
{double X1,X2,Y1,Y2,d;
while(scanf("%lf%lf%lf%lf",&X1,&Y1,&X2,&Y2)!=EOF)
{d=sqrt(((X1-X2)*(X1-X2)+(Y1-Y2)*(Y1-Y2)));
printf("%.2lf\n",d);
}
}
