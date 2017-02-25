// 2005 ( 第几天？ )
//acm.hdu.edu.cn/showproblem.php?pid=2005


#include<stdio.h>
int main()
{int n,year,mon,day;
while(scanf("%d/%d/%d",&year,&mon,&day)!=EOF)
{switch(mon)
{case 1: n=day;break;
case 2: n=31+day;break;
case 3: n=59+day;break;
case 4: n=90+day;break;
case 5: n=120+day;break;
case 6: n=151+day;break;
case 7: n=181+day;break;
case 8: n=212+day;break;
case 9: n=243+day;break;
case 10: n=273+day;break;
case 11: n=304+day;break;
case 12: n=334+day;break;
}
if((year%4==0&&year%100!=0)||(year%400==0))
   {if(mon>2)
   printf ("%d\n",n+1);
    else
    printf("%d\n",n);}
else
printf("%d\n",n);
}
return 0;
}