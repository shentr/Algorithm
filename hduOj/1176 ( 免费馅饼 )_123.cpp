// 1176 ( 免费馅饼 )
//acm.hdu.edu.cn/showproblem.php?pid=1176


#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int data[13][100010];
int dp[13][100010];

int max3(int a,int b,int c)
{
    a=max(a,b);
    c=max(a,c);
    return c;
}

int main()
{
    int n;
    while(scanf("%d",&n)==1&&n)
    {
        memset(data,0,sizeof(data));
        memset(dp,0,sizeof(dp));
        int allt=0;
        while(n--)
        {
            int x,t;
            scanf("%d%d",&x,&t);
            data[x][t]++;
            if(t>allt)
                allt=t;
        }
        for(int i=0;i<=10;i++)
        {
            dp[i][allt]=data[i][allt];
        }
        /*for(int j=allt-1;j>=0;j--)
        {
            dp[0][j]=max(dp[0][j+1],dp[1][j+1])+data[0][j];
            dp[10][j]=max(dp[10][j+1],dp[9][j+1])+data[10][j];
        }
        */
        for(int j=allt-1;j>=0;j--)
        {
            for(int i=10;i>=0;i--)
            {
                if(i==10)
                dp[10][j]=max(dp[10][j+1],dp[9][j+1])+data[10][j];
                if(i>0&&i<10)
                dp[i][j]=max3(dp[i-1][j+1],dp[i][j+1],dp[i+1][j+1])+data[i][j];
                if(i==0)
                    dp[0][j]=max(dp[0][j+1],dp[1][j+1])+data[0][j];
            }
        }
        printf("%d\n",dp[5][0]);
    }
}
