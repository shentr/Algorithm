// 2011 ( 多项式求和 )
//acm.hdu.edu.cn/showproblem.php?pid=2011


#include<stdio.h> 
int main() 
{ 
    int n,m,i; 
    double a[1000],j;
    a[1]=1; 
    for(i=2;i<1000;i++) 
    { 
        j=1.0/i;
        if(i%2!=1) 
            a[i]=a[i-1]-j; 
        else 
            a[i]=a[i-1]+j;
    }
    scanf("%d",&n); 
    while(n--) 
    { 
        scanf("%d",&m);
        printf("%.2f\n",a[m]);
    } 
    return 0; 
}