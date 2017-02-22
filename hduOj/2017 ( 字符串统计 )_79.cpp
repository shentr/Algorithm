// 2017 ( 字符串统计 )
//acm.hdu.edu.cn/showproblem.php?pid=2017


#include <stdio.h>
#include <string.h>
int main()
{int n,j,i,d;
char a[1000];
scanf("%d",&n);
getchar(); 
for (j=1;j<=n;j++)
{
d=0;
gets(a);
for( i=0;i<strlen(a);i++)
{
if(a[i]>=48 &&a[i]<=57)
{
d++;
}    
}
printf("%d\n",d);
}
return 0;
}