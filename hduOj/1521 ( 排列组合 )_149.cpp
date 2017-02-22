// 1521 ( 排列组合 )
//acm.hdu.edu.cn/showproblem.php?pid=1521


#include<stdio.h>
#include<string.h>
double c1[1000],c2[1000];
int num[100];
double jc(int x)
{
 int i;
 double sum=1.0;
 for(i=1;i<=x;i++)
  sum=sum*i;
 return sum;
}
int main()
{
 int i,j,k,n,m;
 while(scanf("%d %d",&n,&m)!=EOF)
 {
         for(i=1;i<=n;i++)
    scanf("%d",&num[i]);
   memset(c1,0,sizeof(c1));
   memset(c2,0,sizeof(c2));
   for(i=0;i<=num[1];i++)//注意每种物品可以看做是重量为1的砝码
           c1[i]=1.0/jc(i);
   for(i=2;i<=n;i++)
   {
    for(j=0;j<=m;j++)
    {
     for(k=0;k+j<=m&&k<=num[i]*1;k++)//val[i]都是1 所以直接k++
      c2[j+k]+=c1[j]/jc(k);
    }
    for(k=0;k<=m;k++)
    {

     c1[k]=c2[k];
     c2[k]=0;
    }
   }
   printf("%.0lf\n",c1[m]*jc(m));//要乘

 }
}
