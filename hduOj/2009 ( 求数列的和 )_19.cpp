// 2009 ( 求数列的和 )
//acm.hdu.edu.cn/showproblem.php?pid=2009


#include<stdio.h>
#include<math.h>
int main()
{int n,m,i;
double sum,a;
while(scanf("%d%d",&n,&m)!=EOF)
{
sum=0;
a=n;
for(i=0;i<m;i++)
{
sum+=a;
a=sqrt(a);
}
printf("%.2lf\n",sum);
}
return 0;
}
