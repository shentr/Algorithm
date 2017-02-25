// HDU1521
//http://acm.hdu.edu.cn/showproblem.php?pid=1521


#include<stdio.h>
#include<string.h>
double a[15];
void shezhi()
{
    int i;
    a[0]=a[1]=1;
    for(i=2;i<=10;i++)
        a[i]=a[i-1]*i;
}
int main()
{
    int i,j,k,n,m,num[15];
    double c1[15],c2[15];
    shezhi();
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(i=1;i<=n;i++)
            scanf("%d",&num[i]);
        for(i=0;i<=10;i++)
        {
            c1[i]=0.0;
            c2[i]=0.0;
        }
        for(i=0;i<=num[1];i++)
        {
            c1[i]=1.0/a[i];
        }
        for(i=2;i<=n;i++)
        {
            for(j=0;j<=m;j++)
            {
                for(k=0;k<=num[i]&&j+k<=m;k++)
                {
                    c2[j+k]=c2[j+k]+c1[j]/a[k];
                }
            }
            for(j=0;j<=m;j++)
            {
                c1[j]=c2[j];
                c2[j]=0;
            }
        }
        printf("%.0lf\n",c1[m]*a[m]);
    }
    return 0;
}
