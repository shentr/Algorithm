// 2022 ( 海选女主角 )
//acm.hdu.edu.cn/showproblem.php?pid=2022


#include<stdio.h>
#include<math.h>
int main()
{
    int m,n,i,j,s,t;
    long int a[100][100];
    while(scanf("%d%d",&m,&n)!=EOF)
    {s=t=0;
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                scanf("%ld",&a[i][j]);
                if(fabs(a[i][j])>fabs(a[s][t]))
                    {s=i;t=j;}
            }
        }
        printf("%d %d %ld\n",s+1,t+1,a[s][t]);
    }
    return 0;
}
