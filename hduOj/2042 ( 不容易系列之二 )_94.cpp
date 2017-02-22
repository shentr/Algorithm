// 2042 ( 不容易系列之二 )
//acm.hdu.edu.cn/showproblem.php?pid=2042


#include<stdio.h>
#include<math.h>
int main()
{
    int n,a,m;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&a);
        m=pow(2,a)+2;
        printf("%d\n",m);
    }
    return 0;
}
