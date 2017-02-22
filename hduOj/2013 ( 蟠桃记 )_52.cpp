// 2013 ( 蟠桃记 )
//acm.hdu.edu.cn/showproblem.php?pid=2013


#include<stdio.h>
int main()
{
int n,m,i;
while (scanf("%d",&n)!=EOF)
{m=1;
for (i=2;i<=n;i++)
m=2*(m+1);
printf("%d\n",m);}
return 0;
}