// POJ3071
//http://poj.org/problem?id=3071


#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=200;
double dp[10][N],p[N][N];
int mi2[8]={1,2,4,8,16,32,64,128};    //mi2[i]2的i次幂

 int main()
 {
     int n;
     while(cin>>n&&n!=-1)
     {
         memset(dp,0,sizeof(dp));
         int x=mi2[n];
         for(int i=0;i<x;i++)
            for(int j=0;j<x;j++)
                scanf("%lf",&p[i][j]);
         for(int j=0;j<x;j++)       //第一次，i-1<0,所以拿出来考虑
         {
             int i=0;
            int jj=j/mi2[i+1];
            for(int k=jj*mi2[i+1];k/mi2[i+1]<=jj;k++)
            {
                if(k/mi2[i]==j/mi2[i]) continue;
                dp[i][j]+=p[j][k];                  //dp[i-1][j]=1;
            }
         }
         for(int i=1;i<n;i++)
         {
             for(int j=0;j<x;j++)
             {
                 int jj=j/mi2[i+1];
                 for(int k=jj*mi2[i+1];k/mi2[i+1]<=jj;k++)
                 {
                     if(k/mi2[i]==j/mi2[i]) continue;
                     dp[i][j]+=dp[i-1][j]*p[j][k]*dp[i-1][k];
                 }
             }
         }
         double maxdp=-1.0;
         int maxj;
         for(int j=0;j<x;j++)
         {
            //cout<<dp[n-1][j]<<"   ";
            if(dp[n-1][j]>maxdp)
            {
                maxdp=dp[n-1][j];
                maxj=j;
            }
         }
         cout<<maxj+1<<endl;
     }
 }



