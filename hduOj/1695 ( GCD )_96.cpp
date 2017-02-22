// 1695 ( GCD )
//acm.hdu.edu.cn/showproblem.php?pid=1695


#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=100000+10;
int u[N],prime[N];
bool vis[N];

void init()
{
    memset(vis,0,sizeof(vis));
    u[1] = 1;
    int cnt = 0;
    for(int i=2; i<N; i++)
    {
        if(!vis[i])
        {
            prime[cnt++] = i;
            u[i] = -1;
        }
        for(int j=0; j<cnt&&i*prime[j]<N; j++)
        {
            vis[i*prime[j]] = 1;
            if(i%prime[j]) u[i*prime[j]] = -u[i];
            else
            {
                u[i*prime[j]] = 0;
                break;
            }
        }
    }
}
int main()
{
    init();
    int t;
    cin>>t;
    int a,b,c,d,k;
    for(int kase=1;kase<=t;kase++)
    {
        scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
        if(k==0)
        {
            printf("Case %d: 0\n",kase);
            continue;
        }
        long long ans=0;
        int ma=max(b,d),mi=min(b,d);
        for(int i=k;i<=mi;i+=k)
        {
            ans+=(long long)u[i/k]*((ma/i)*2-(mi/i)+1)*(mi/i)/2;
        }
        printf("Case %d: %I64d\n",kase,ans);
    }
    return 0;
}
