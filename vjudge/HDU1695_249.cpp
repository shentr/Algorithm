// HDU1695
//http://acm.hdu.edu.cn/showproblem.php?pid=1695


#include <iostream>
#include <string.h>
using namespace std;
const int maxn=1e5+7;
bool vis [maxn];
int prime[maxn],mu[maxn];
int cnt;
void Mu()
{
    int N=maxn;
    memset(prime,0,sizeof(prime));
    memset(mu,0,sizeof(mu));
    memset(vis,0,sizeof(vis));
    mu[1]=1;
    cnt=0;
    for(int i=2;i<N;i++)
    {
        if(!vis[i])
        {
            prime[cnt++]=i;
            mu[i]=-1;
        }
        for(int j=0;j<cnt&&i*prime[j]<N;j++)
        {
            vis[i*prime[j]]=1;
            if(i%prime[j])
                mu[i*prime[j]]=-mu[i];
            else
            {
                mu[i*prime[j]]=0;
                break;
            }
        }
    }
}
int main()
{
    //ios::sync_with_stdio(false);
    int t,a,b,c,d,k;
    Mu();
    cin>>t;
     int num=1;
    while(t--)
    {
        long long ans1=0,ans2=0;
        cin>>a>>b>>c>>d>>k;
        //cout<<"Case "<<++num<<": ";
        if(k==0)
        {
            cout<<"Case "<<num<<": "<<0<<endl;
            num++;
           // cout<<"0"<<endl;
            continue;
        }
        b=b/k;
        d=d/k;
        for(int i=1;i<=min(b,d);i++)
        ans1+=(long long)mu[i]*(b/i)*(d/i);
        for(int i=1;i<=min(b,d);i++)
        ans2+=(long long)mu[i]*(min(b,d)/i)*(min(b,d)/i);
        ans1-=ans2/2;
        cout<<"Case "<<num<<": "<<ans1<<endl;
            num++;
          // cout<<ans1<<endl;
    }
    return 0;
}
