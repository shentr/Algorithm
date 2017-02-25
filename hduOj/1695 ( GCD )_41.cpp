// 1695 ( GCD )
//acm.hdu.edu.cn/showproblem.php?pid=1695


#include<iostream>
#include<cstdio>
#include<cstring>
//#include<fstream>
using namespace std;
const int N=100000+10;
int u[N],prime[N];
bool vis[N];

void init()
{
    memset(u,0,sizeof(u));
    memset(vis,0,sizeof(vis));
    int cnt=0;
    u[1]=1;
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
    for(int i=2;i<N;i++)
    {
        int ii=i,count=0,flag=0;
        for(int j=0;prime[j]<=ii&&j<cnt;j++)
        {
            if(ii%prime[j]==0)
            {
                count++;
                ii/=prime[j];
            }
            if(ii%prime[j]==0)
            {
                flag=1;
                break;
            }
        }
        if(!flag)
        {
            u[i]=(count%2==0?1:-1);
        }
    }
}

int main()
{
    //ofstream fout("F://output.txt");
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
//fout<<ans<<endl;
    }
    return 0;
}
