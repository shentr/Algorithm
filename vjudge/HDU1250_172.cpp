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
        for(j=254; j>0; j--)
            if(a[n][j]!=0)
            {
                k=j;
                cout<<a[n][j];
                break;

            }
        for( m=k-1; m>0; m--)
            printf("%.8d",a[n][m]);
            cout<<endl;


    }
    return 0;
}
