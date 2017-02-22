// 2034 ( 人见人爱A-B )
//acm.hdu.edu.cn/showproblem.php?pid=2034


#include<stdio.h>
int main()
{
 int a[105],b[105],n,t,c,m,i,j,k,d;
 while(scanf("%d%d",&n,&m))
 { if(m==0&&n==0) return 0;
  t=0;d=1;
  for(i=0;i<n;i++)
   scanf("%d",&a[i]);
  for(i=0;i<n;i++)
   for(k=0;k<n-i-1;k++)
   {
    if(a[k]>a[k+1])
    {c=a[k];a[k]=a[k+1];a[k+1]=c;}
   }
  for(i=0;i<m;i++)
   scanf("%d",&b[i]);
  for(i=0;i<n;i++)
   for(j=0;j<m;j++)
   {
    if(a[i]==b[j])
    {a[i]=0;t++;}
   }
  if(t==n) printf("NULL\n");
  else
  {
   for(i=0;i<n;i++)
   {
   if(a[i]==0) continue;
   else {printf("%d ",a[i]);d=0;}
   }
   if(d)printf("0 ");
      printf("\n");
  }
 }
 return 0;
}
