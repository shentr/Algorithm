// 1506 ( Largest Rectangle in a Histogram )
//acm.hdu.edu.cn/showproblem.php?pid=1506


#include<stdio.h>
#include<string.h>
__int64 a[100005],dp[100005],l[100005],r[100005];
int main()
{
   __int64 n,i,t,max;
   while(scanf("%I64d",&n)!=EOF&&n)
   {
      max=-1;
      for(i=1;i<=n;i++)
         scanf("%I64d",&a[i]);
      l[1]=1;r[n]=n;
      for(i=2;i<=n;i++)//求每个点左边连续比它大的最左边的下标，保存在l[]数组里
      {
          t=i;
          while(t>1&&a[i]<=a[t-1]) 
              t=l[t-1];
          l[i]=t;
      }
      for(i=n-1;i>=1;i--)//求每个点右边连续比它大的最右边的下标，保存在r[]数组里
      {
          t=i;
          while(t<n&&a[i]<=a[t+1])
              t=r[t+1];
          r[i]=t;
      }
      for(i=1;i<=n;i++)
          if((r[i]-l[i]+1)*a[i]>max)
              max=(r[i]-l[i]+1)*a[i];
      printf("%I64d\n",max);
   }
   return 0;
}