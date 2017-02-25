// POJ1742
//http://poj.org/problem?id=1742


#include <iostream>
#include <string.h>
using namespace std;
int a[100005],c[1005],use[100005];
bool dp[100005];
int main()
{
    int n,m;
   while(cin>>n>>m)
   {

       memset(dp,false,sizeof(dp));
       if(n==0&&m==0)
        break;
       long long sum=0;
       for(int i=1;i<=n;i++)
        cin>>a[i];
       for(int i=1;i<=n;i++)
        cin>>c[i];
        dp[0]=1;
       for(int i=1;i<=n;i++)
       {
            memset(use,0,sizeof(use));
           for(int j=a[i];j<=m;j++)
       {
           if(!dp[j]&&dp[j-a[i]]&&use[j-a[i]]<c[i])
           {
               dp[j]=true;
               use[j]=use[j-a[i]]+1;
               sum++;
           }
       }
       }
       cout<<sum<<endl;

   }
    return 0;
}
