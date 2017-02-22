// 2049 ( 不容易系列之(4)——考新郎 )
//acm.hdu.edu.cn/showproblem.php?pid=2049


#include <stdio.h>
int main()
{
    int n,a,b,i,j;
    __int64 s[22],h[22];
    s[1]=0;
    s[2]=1;
    s[3]=2;
    for(i=4;i<21;i++)
    {
        s[i]=(i-1)*(s[i-1]+s[i-2]);
    }
    scanf("%d",&n);
    while(n--)
    {
       scanf("%d%d",&a,&b);
       h[0]=1;
           for(j=1;j<22;j++){
             h[j]=j*h[j-1];
           }
       printf("%I64d\n",h[a]/(h[a-b]*h[b])*s[b]);
    }
    return 0;
}
