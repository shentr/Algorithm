// HDU1250
//http://acm.hdu.edu.cn/showproblem.php?pid=1250


#include<stdio.h>

int n,i,j,ans[8000][255]= {{0}};

int main()
{
    for(i=1; i<5; i++)ans[i][1]=1;
    for(i=5; i<8000; i++)
        for(j=1; j<255; j++)
        {
            ans[i][j]+=ans[i-1][j]+ans[i-2][j]+ans[i-3][j]+ans[i-4][j];
            ans[i][j+1]+=ans[i][j]/100000000;
            ans[i][j]=ans[i][j]%100000000;

        }

    while(scanf("%d",&n)!=EOF)
    {
        for(i=254; i>0; i--)
            if(ans[n][i])break;
        printf("%d",ans[n][i]);
        for(--i; i>0; i--)
            printf("%.8d",ans[n][i]);
        printf("\n");
    }
    return 0;
}
