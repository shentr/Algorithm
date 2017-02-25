// 2008 ( 数值统计 )
//acm.hdu.edu.cn/showproblem.php?pid=2008


#include<stdio.h>
int main()
{int n,i,r,s,t;
double m;
while(scanf("%d",&n))
{if(n!=0)
{r=0;s=0;t=0;
for(i=1;i<=n;i++)
{scanf("%lf",&m);
if (m<0) r++;
else if (m==0) s++;
else t++;
}
printf("%d %d %d\n",r,s,t);
}
else return 0;
}
return 0;
}
