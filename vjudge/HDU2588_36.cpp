// HDU2588
//http://acm.hdu.edu.cn/showproblem.php?pid=2588


#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long LL;
const int N=1e5;

bool vis[N];
int prime[N],cnt;
void is_prime()
{
    cnt=0;
    memset(vis,0,sizeof(vis));
    for(int i=2; i<N; i++)
    {
        if(!vis[i])
        {
            prime[cnt++]=i;
            for(int j=i+i; j<N; j+=i)
                vis[j]=1;
        }
    }
}

int e[100],p[100],cnt2=0;
void fenjie(int n)
{
    cnt2=0;
    memset(e,0,sizeof(e));
    for(int i=0; i<cnt&&prime[i]<=n; i++)
    {
        if(n%prime[i]==0)
        {
            p[cnt2]=prime[i];
            e[cnt2]++;
            n/=prime[i];
            while(n%prime[i]==0)
            {
                n/=prime[i];
                e[cnt2]++;
            }
            cnt2++;
        }
    }
}

int Euler(int n)
{
    int ans=n;
    for(int i=0; i<cnt&&prime[i]<=n; i++)
    {
        if(n%prime[i]==0)
        {
            ans=ans-ans/prime[i];
            while(n%prime[i]==0)
                n/=prime[i];
        }
    }
    if(n==1)
        return ans;
    if(n>1)
        return ans-ans/n;

}

LL dfsans[N],cnt3=0;
void dfs(int cur,LL x)
{
    if(cur==cnt2)
    {
        dfsans[cnt3++]=x;
        return;
    }
    for(int i=0;i<=e[cur];i++)
    {
        LL ans=1;
        for(int j=0;j<i;j++)
            ans*=p[cur];
        dfs(cur+1,x*ans);
    }
}


int main()
{
    int t;
    cin>>t;
    is_prime();
    while(t--)
    {
        LL n,m;
        cin>>n>>m;
        fenjie(n);
        LL ans=0;
        //for(int i=0;i<N;i++)
           // dfsans[i]=1;
        cnt3=0;
        dfs(0,1);
        for(int i=0;i<cnt3;i++)
        {
            //cout<<dfsans[i]<<endl;
            if(dfsans[i]>=m)
                ans+=Euler(n/dfsans[i]);
        }
        /*for(int i=1; i*i<=n; i++)
        {
            if(n%i==0)
            {
                if(i>=m)
                    ans+=Euler(n/i);
                if((n/i!=i)&&(n/i>=m))
                    ans+=Euler(i);
            }
        }*/
        cout<<ans<<endl;
    }
}

