// 2012 ( 素数判定 )
//acm.hdu.edu.cn/showproblem.php?pid=2012


#include<stdio.h>
#include<math.h>
int main()
{int x,y,i,j,m,flag;
while (scanf("%d %d",&x,&y)!=EOF)
{
    if (x==0&&y==0) return;
   flag=0;
    for (i=x;i<=y;i++)
    {
        m=i*i+i+41;
        for(j=2;j<=sqrt(m);j++)
            {if (m%j==0)
            flag++;}
            }
    if (flag==0)
        printf("OK\n");
    else
    printf("Sorry\n");
}

    return 0;
}
