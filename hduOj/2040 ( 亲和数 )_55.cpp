// 2040 ( 亲和数 )
//acm.hdu.edu.cn/showproblem.php?pid=2040


#include<stdio.h>
int main()
{
    int m,a,b,i,j,k1,k2,q1,q2;
    scanf("%d",&m);
    while(m--)
    {
        k1=k2=0;
        scanf("%d%d",&a,&b);
        for(i=1;i<a;i++)
        {
            q1=a%i;
            if(q1==0) k1=i+k1;
        }
        for(i=1;i<b;i++)
        {
            q2=b%i;
            if(q2==0) k2=i+k2;
        }
        if(k1==b&&k2==a) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
