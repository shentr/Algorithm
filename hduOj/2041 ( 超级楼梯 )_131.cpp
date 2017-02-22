// 2041 ( 超级楼梯 )
//acm.hdu.edu.cn/showproblem.php?pid=2041


#include <stdio.h>
int main()
{
    int i, n;
    long long int m[50] = {0, 1};
    for (i=2;i<41;i++)
        m[i]=m[i-1]+m[i-2];
    scanf("%d",&n);
    while (n-- && scanf("%d", &i))
        printf("%lld\n", m[i]);
    return 0;
}
