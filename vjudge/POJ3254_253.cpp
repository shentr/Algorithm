// POJ3254
//http://poj.org/problem?id=3254


#include <iostream>
#include <cstring>
#include <cstdio>
#define mod 100000000
using namespace std;
int n,m,top=0;
int s[600],cur[20],dp[20][600];
 bool OK(int x)
{
    if(x&(x<<1))
        return false;
    return true;
}
void init()
{
    top=0;
    int total=1<<n;
    for(int i=0; i<total; i++)
    {
        if(OK(i))
            s[++top]=i;
    }
}
 bool fit(int x,int q)
{
    if(x&cur[q])
        return false;
    return true;
}
int main()
{
    while(scanf("%d%d",&m,&n)!=EOF)
    //while(cin>>m>>n)
    {
           init();
        //memset(s,0,sizeof(s));
        memset(dp,0,sizeof(dp));

        for(int i=1; i<=m; i++)
        {
            cur[i]=0;
            //memset(cur,0,sizeof(cur));
            int num;
            for(int j=1; j<=n; j++)
            {
                //cin>>num;
                scanf("%d",&num);
                if(num==0)
                {
                    cur[i]+=(1<<(n-j));
                }
            }
        }
        for(int i=1; i<=top; i++)
        {
            if(fit(s[i],1))
                dp[1][i]=1;
        }
        for(int i=2; i<=m; i++) //从第i行到第m行
        {
            for(int k=1; k<=top; k++)
            {
                if(!fit(s[k],i))
                    continue;
                for(int j=1; j<=top; j++)
                {
                    if(!fit(s[j],i-1))
                        continue;
                    if(s[k]&s[j])
                        continue;
                    dp[i][k]=(dp[i][k]+dp[i-1][j])%mod;
                }
            }
        }
        int ans=0;
        for(int i=1; i<=top; i++)
        {
            ans=(ans+dp[m][i])%mod;
            //cout<<ans<<endl;
        }
        //cout<<ans<<endl;
        printf("%d\n",ans);
    }
    return 0;
}
