// ACdream1112
//http://acdream.info/problem?pid=1112


#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long LL;
const int N=5e6+5;
const int NN=1e4;

bool vis[N];
int prime[NN],cnt;
void is_prime()
{
    cnt=0;
    memset(vis,0,sizeof(vis));
    for(int i=2;i*i<N;i++)
    {
        if(vis[i]==0)
        {
            prime[cnt++]=i;
            for(int j=i+i;j<NN;j+=i)
            {
                vis[j]=1;
            }
        }
    }
}

int prime_num(int n)
{
    int count=0;
    for(int i=0;i<cnt&&prime[i]*prime[i]<=n;i++)
    {
        while(n%prime[i]==0)
        {
            n/=prime[i];
            count++;
        }
    }
    if(n>1)
        count++;
    return count;
}

int sg[N],hs[N];
void Init_SG()
{
    memset(sg,0,sizeof(sg));
    for(int i=1;i<20;i++)
    {
        memset(hs,0,sizeof(hs));
        for(int j=0;j<i;j++)
        {
            hs[sg[j]]=1;
        }
        for(int j=1;j<=i/2;j++)
        {
            hs[sg[j]^sg[i-j]]=1;
        }
        for(int j=0;j<=N;j++)
        {
            if(hs[j]==0)
            {
                sg[i]=j;
                break;
            }
        }
    }
}

/*void test()
{
    Init_SG();
    for(int i=0;i<=6300;i++)
        if(sg[i]==7)
        cout<<i<<' '<<sg[i]<<endl;
}
*/

int pnum[N];
bool pvis[N];
int main()
{
    //test();
    is_prime();
    Init_SG();
    memset(pvis,0,sizeof(pvis));
    int n;
    while(~scanf("%d",&n))
    {
        int a,ans=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a);
            if(!pvis[a])
            {
                pnum[a]=prime_num(a);
                pvis[a]=1;
            }
            ans^=sg[pnum[a]];
        }
        if(ans==0)
            printf("Bob\n");
        else
            printf("Alice\n");
    }
}
