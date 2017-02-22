// 2025 ( 查找最大元素 )
//acm.hdu.edu.cn/showproblem.php?pid=2025


#include<stdio.h>
#include<string.h>
int main()
{
    int i,t;
    char a[101];
    while(gets(a))
    {   t=0;
        for(i=0;i<strlen(a);i++)
       {if(a[i]>=t)
           t=a[i];}
        for(i=0;i<strlen(a);i++)
           {
            putchar(a[i]);
            if (a[i]==t)
                printf("(max)");
                }
        printf("\n");
    }
    return 0;
}
