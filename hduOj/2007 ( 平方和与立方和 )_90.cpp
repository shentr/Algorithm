// 2007 ( 平方和与立方和 )
//acm.hdu.edu.cn/showproblem.php?pid=2007


#include<stdio.h>
int main()
{int i,x,y,t,q,m;
while(scanf("%d%d",&x,&y)!=EOF)
{t=0;m=0;
if(x>y) {q=x;x=y;y=q;}
for(i=x;i<=y;i++)
{if(i%2==0) t=t+i*i;
if(i%2==1)  m=m+i*i*i;}
printf("%d %d\n",t,m);
}
return 0;
}
