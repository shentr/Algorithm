// 2830 ( Matrix Swapping II )
//acm.hdu.edu.cn/showproblem.php?pid=2830


#include"stdio.h"
#include"string.h"
#include"stdlib.h"
#define N 1011
char map[N][N];
int dp[N][N];
int cmp(const void *a,const void *b)
{
    return *(int *)b-*(int *)a;
}
int main()
{
    int n,m;
    int i,l;
    int temp;
    int ans;
    while(scanf("%d%d",&n,&m)!=-1)
    {
        for(i=0;i<n;i++)    scanf("%s",map[i]);

        for(l=0;l<m;l++)    dp[0][l]=map[0][l]-'0';
        for(l=0;l<m;l++)
        for(i=1;i<n;i++)    
        {
            if(map[i][l]=='0')    dp[i][l]=0;
            else                dp[i][l]=dp[i-1][l]+1;
        }

        ans=0;
        for(i=0;i<n;i++)
        {
            qsort(dp[i],m,sizeof(dp[i][0]),cmp);
            for(l=0;l<m;l++)
            {
                temp=dp[i][l]*(l+1);
                ans=ans>temp?ans:temp;
            }
        }

        printf("%d\n",ans);
    }
    return 0;
}