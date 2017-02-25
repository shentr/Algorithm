// 2000 ( ASCII码排序 )
//acm.hdu.edu.cn/showproblem.php?pid=2000


#include<stdio.h>
int main()
{char a,b,c,t;
while(scanf("%c%c%c",&a,&b,&c)!=EOF)
{getchar();
if(a>b)
{t=a;a=b;b=t;}
if(b>c)
{t=b;b=c;c=t;}
if(a>b)
{t=a;a=b;b=t;}
printf("%c %c %c\n",a,b,c);
}
return 0;
}