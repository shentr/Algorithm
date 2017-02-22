// 2050 ( 折线分割平面 )
//acm.hdu.edu.cn/showproblem.php?pid=2050


#include<stdio.h>
int main()
{
    int C,n;
    scanf("%d",&C);
    while(C--)
    {
        scanf("%d",&n);
        printf("%d\n",n*n*2-n+1);
    }return 0;
}
