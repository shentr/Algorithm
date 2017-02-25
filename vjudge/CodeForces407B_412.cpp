// CodeForces407B
//http://codeforces.com/problemset/problem/407B


#include <iostream>
#define MOD 1000000007
using namespace std;
long long a[1005],dp[1005];
int main()
{
    int n;
  while(cin>>n)
  {
      for(int i=1;i<=n;i++)
        cin>>a[i];
      dp[1]=0;
      for(int i=1;i<=n+1;i++)
      {
          dp[i+1]=(dp[i]+1+dp[i]-(dp[a[i]]-1)+MOD)%MOD;
      }
      cout<<dp[n+1]<<endl;
  }
    return 0;
}
