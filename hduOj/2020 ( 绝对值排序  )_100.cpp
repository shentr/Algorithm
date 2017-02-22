// 2020 ( 绝对值排序  )
//acm.hdu.edu.cn/showproblem.php?pid=2020


#include<stdio.h>
#include<math.h>
int main()
{
    int n,a[100],i,j,t;
    while(scanf("%d",&n)!=EOF&&n!=0)
    {
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(i=0;i<n;i++)
        {
            for(j=i;j<n;j++)
            {
                if(fabs(a[j])>fabs(a[i]))
                {
                    t=a[i];a[i]=a[j];a[j]=t;
                }
            }
            if(i) printf(" ");
         printf("%d",a[i]);
        }
        printf("\n");
    }
    return 0;
}

