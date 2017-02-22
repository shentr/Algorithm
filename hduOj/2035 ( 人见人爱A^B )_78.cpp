// 2035 ( 人见人爱A^B )
//acm.hdu.edu.cn/showproblem.php?pid=2035


#include <stdio.h>
int main()
{
    int a,b,i,sum;
    while (scanf("%d%d",&a,&b))
    {
         if(a==0||b==0)   break;
        sum=a;
        for (i = 1 ; i < b ; i++)
            sum = (sum * a) % 1000;
         printf("%d\n", sum % 1000);
    }
    return 0;
}
