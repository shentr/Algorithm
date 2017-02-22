// 2006 ( 求奇数的乘积 )
//acm.hdu.edu.cn/showproblem.php?pid=2006


#include <stdio.h>
int main()
{int a,t,i,n;
while (scanf("%d",&n)!=EOF)
{t=1;
for(i=1;i<=n;i++)
{scanf("%d",&a);
if(a%2==1)
t*=a;
}
printf("%d\n",t); 
 }
return 0;
}