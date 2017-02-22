// 2008 ( 数值统计 )
//acm.hdu.edu.cn/showproblem.php?pid=2008


#include<stdio.h>
int main()
{int n,r,s,t;
double a;
while(scanf("%d",&n)&&n)
{r=0;s=0;t=0;
while(n--)
{
scanf("%lf",&a);
if(a<0)
r++;
else
if(a==0)
s++;
else
t++;
}
printf("%d %d %d\n",r,s,t);
}
return 0;
}
