// 2030 ( 汉字统计 )
//acm.hdu.edu.cn/showproblem.php?pid=2030


#include<stdio.h>
#include<string.h>
int main()
{
    int n,d,i;
    char a[10000];
    scanf("%d%*c",&n);
    while(n--)
    {
        d=0;
        gets(a);
        for(i=0;i<strlen(a);i++)
            if(a[i]<0)  d++;
        printf("%d\n",d/2);
    }return 0;
}
