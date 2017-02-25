// 2031 ( 进制转换 )
//acm.hdu.edu.cn/showproblem.php?pid=2031


#include <stdio.h>
int main()
{
    int N,R,a[100],i;
    while(scanf("%d%d",&N,&R)!=EOF)
    {
        if(N<0)
        {
            printf("-");
            N=-N;
        }
        for(i=0;N;i++)
        {
            a[i]=N%R;
                N/=R;
        }
        while(i--)
        {
            if(a[i]<10)
                printf("%d",a[i]);
            else
                printf("%c",a[i]+55);
        }
        printf("\n");
    }
    return 0;
}
 

