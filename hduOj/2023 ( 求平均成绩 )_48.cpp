// 2023 ( 求平均成绩 )
//acm.hdu.edu.cn/showproblem.php?pid=2023


#include <stdio.h>
#include <string.h>
int main()
{int n,m,i,j,t,d,s[50],c[5],sc[50][5];
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(s,0,sizeof(s));
        memset(c,0,sizeof(c));
        memset(sc,0,sizeof(sc));
        for (i=0;i<n;i++)
        {
            for (j=0;j<m;j++)
            {
                scanf("%d",&sc[i][j]);
                c[j]+=sc[i][j];
                s[i]+=sc[i][j];
            }
        }
        for (i=0;i<n;i++)
            printf("%.2lf%c",s[i]*1.0/m,i<n-1?' ':'\n');
        for (i=0;i<m;i++)
            printf("%.2lf%c",c[i]*1.0/n,i<m-1?' ':'\n');
        for (t=i=0;i<n;i++)
        {
            for (d=1,j=0;j<m;j++)
            {
                if(sc[i][j]<1.0*c[j]/n)
                {
                    d=0;
                    break;
                }
            }
            if (d) t++;
        }
        printf("%d\n\n",t);
    }
    return 0;
}



