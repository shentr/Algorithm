// 2014 ( 青年歌手大奖赛_评委会打分 )
//acm.hdu.edu.cn/showproblem.php?pid=2014


#include<stdio.h>
int main()
{
int n,i;
double a,max,min,average,t;
while (scanf("%d",&n)!=EOF)
{max=0;min=100;t=0;
for (i=1;i<=n;i++)
{scanf("%lf",&a);
{if (a>=max)
max=a;
if (a<=min)
min=a;}
t=t+a;
average=(t-max-min)/(n-2);
}
printf("%.2lf\n",average);
}
return 0;
}
