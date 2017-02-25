// 1787 ( GCD Again )
//acm.hdu.edu.cn/showproblem.php?pid=1787


#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=1e4+5;
int prime[N],cnt;
bool vis[N];

void is_prime()
{
    cnt=0;
    memset(vis,0,sizeof(vis));
    for(int i=2;i<N;i++)
    {
        if(!vis[i])
        {
            prime[cnt++]=i;
            for(int j=i+i;j<N;j+=i)
            {
                vis[j]=1;
            }
        }
    }
}

int Euler(int n)
{
    is_prime();
    int ans=n;
    for(int i=0;i<cnt&&prime[i]<=n;i++)
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

int main()
{
    int n;
    while(cin>>n&&n)
    {
        cout<<n-Euler(n)-1<<endl;
    }
}
