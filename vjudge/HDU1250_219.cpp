// HDU1250
//http://acm.hdu.edu.cn/showproblem.php?pid=1250


#include <iostream>
#include <stdio.h>
using namespace std;
int a[8000][255]= {{0}};
int n,k,ans,i,j,m;
int main()
{
    for( i=1; i<5; i++)a[i][1]=1;
    for( i=5; i<8000; i++)
        for(j=1; j<255; j++)
        {
            a[i][j]+=a[i-1][j]+a[i-2][j]+a[i-3][j]+a[i-4][j];
            a[i][j+1]+=a[i][j]/100000000;
            a[i][j]=a[i][j]%100000000;
    }
     while(scanf("%d",&n)!=EOF)
    {
        for(i=254; i>0; i--)
            if(a[n][i])break;
        printf("%d",a[n][i]);
        for(--i; i>0; i--)
            printf("%.8d",a[n][i]);
        printf("\n");
    }
    return 0;
}
