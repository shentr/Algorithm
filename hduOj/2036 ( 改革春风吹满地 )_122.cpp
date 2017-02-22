// 2036 ( 改革春风吹满地 )
//acm.hdu.edu.cn/showproblem.php?pid=2036


#include<stdio.h>
int main()
{
    int n,i,p,a[100],b[100];
    double c;
    while (scanf("%d",&n),n!= 0)
    {
        i=0;p=n;c=0;
        while(n--)
        {scanf("%d%d",&a[i],&b[i]);i++;}
        for (i=0;i<p-1;i++)
            c=c+0.5*(a[i]*b[i+1]-a[i+1]*b[i]);
        c=c+0.5*(a[p-1]*b[0]-a[0]*b[p-1]);
        printf("%.1f\n",c);
    }
return 0;
}
