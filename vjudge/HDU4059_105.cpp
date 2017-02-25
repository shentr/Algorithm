// HDU4059
//http://acm.hdu.edu.cn/showproblem.php?pid=4059


#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long LL;
const LL MOD=1e9+7;
const LL NN=1e8+5;
const int N=1e4+5;
const LL ni=233333335;  //30 mod MOD 的逆
LL n,syz[15],ans;
int ycnt;

LL mutisum(LL n)
{
    LL ans1=1;
    ans1=(((((((n*(n+1))%MOD)*(2*n+1))%MOD)*((3*n*n+3*n-1)%MOD))%MOD)*ni)%MOD;
    return ans1%MOD;
}

int prime[N];
bool vis[N];
int pcnt;
void is_prime()
{
    pcnt=0;
    memset(vis,0,sizeof(vis));
    for(int i=2;i<N;i++)
    {
        if(!vis[i])
        {
            prime[pcnt++]=i;
            for(int j=i+i;j<N;j+=i)
                vis[j]=1;
        }
    }
}

void fenjie(LL n1)
{
    ycnt=0;
    for(int i=0;i<pcnt&&prime[i]<=n1;i++)
    {
        if(n1%prime[i]==0)
            syz[ycnt++]=prime[i];
        while(n1%prime[i]==0)
            n1/=prime[i];
    }
    if(n1>1)
        syz[ycnt++]=n1;
}

void dfs(int c,int cur,int j,LL ans1)      //dfs(c,1,0,1);
{
    if(cur==c+1)
    {
        LL nn=(n-1)/ans1,as1=ans1%MOD;
        if(c&1)
            ans-=(((((((mutisum(nn)*as1)%MOD)*as1)%MOD)*as1)%MOD)*as1)%MOD;
        else
            ans+=(((((((mutisum(nn)*as1)%MOD)*as1)%MOD)*as1)%MOD)*as1)%MOD;
        ans%=MOD;
        return;
    }
    for(;j<ycnt;j++)
    {
        dfs(c,cur+1,j+1,ans1*syz[j]);
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    is_prime();
    while(t--)
    {
        scanf("%lld",&n);
        if(n==1)
        {
            printf("1\n");
            continue;
        }
        fenjie(n);
        ans=mutisum(n-1);
        for(int c=1;c<=ycnt;c++)
            dfs(c,1,0,1);
        if(ans<0)
            ans=(ans+MOD)%MOD;
        printf("%lld\n",ans);
    }
}
