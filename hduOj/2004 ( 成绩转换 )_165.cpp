// 2004 ( 成绩转换 )
//acm.hdu.edu.cn/showproblem.php?pid=2004


#include<stdio.h>
int main()
{int n,i;
while(scanf("%d",&n)!=EOF)
{if(n<0||n>100)
{printf("Score is error!\n");}
else
{n=n/10;
switch(n)
{
case 10:
case 9: printf("A\n"); break;
case 8: printf("B\n"); break;
case 7: printf("C\n"); break;
case 6: printf("D\n"); break;
default: printf("E\n"); break;
}
}
}
return 0;
}
