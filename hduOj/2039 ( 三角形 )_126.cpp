// 2039 ( 三角形 )
//acm.hdu.edu.cn/showproblem.php?pid=2039


#include<stdio.h>
int main()
{
    int m;
    float a,b,c;
    scanf("%d",&m);
    while(m--)
    {
        scanf("%f%f%f",&a,&b,&c);
        if(a+b>c&&a+c>b&&b+c>a)
            printf("YES\n");
        else printf("NO\n");
    }return 0;
}
