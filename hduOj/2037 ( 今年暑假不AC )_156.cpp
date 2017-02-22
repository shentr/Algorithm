// 2037 ( 今年暑假不AC )
//acm.hdu.edu.cn/showproblem.php?pid=2037


#include<stdio.h>
int main()
{
    int n,i,j,sum,a[100],b[100],d,t,max;
    while(scanf("%d",&n)&&n!=0)
    {
     for(i=0;i<n;i++)
      scanf("%d %d",&a[i],&b[i]);
     for(i=0;i<n;i++)
        for(j=i+1;j<n;j++)
         if(b[i]>b[j])
          {t=b[i];b[i]=b[j];b[j]=t;d=a[i];a[i]=a[j];a[j]=d;}
        max=0;sum=0;
        for(i=0;i<n;i++)
            if(a[i]>=max)
            {
                sum++;
                max=b[i];
            }
            printf("%d\n",sum);
    }
    return 0;
}
