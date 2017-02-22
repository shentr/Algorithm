// 2602 ( Bone Collector )
//acm.hdu.edu.cn/showproblem.php?pid=2602


#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=1e3+10;
long long va[N],vo[N],dp[N];

int main()
{
    int t;
    cin>>t;
    int v,n;
    while(t--)
    {
        memset(dp,0,sizeof(dp));
        cin>>n>>v;
        for(int i=1;i<=n;i++)
            cin>>va[i];
        for(int i=1;i<=n;i++)
            cin>>vo[i];
        for(int i=1;i<=n;i++)
            for(int j=v;j-vo[i]>=0;j--)
                dp[j]=max(dp[j],dp[j-vo[i]]+va[i]);
            cout<<dp[v]<<endl;
    }
}
