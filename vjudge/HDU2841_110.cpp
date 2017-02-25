// HDU2841
//http://acm.hdu.edu.cn/showproblem.php?pid=2841


#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long LL;
const int N=1e5+10;
int ma,mi;
LL ans;

int syz[N][7];         //素因子分解结果
int cnt[N];
void init()                  //筛选法求syz
{
    memset(cnt,0,sizeof(cnt));
    for(int i=2;i<N;i++)
    {
        if(cnt[i]==0)
        {
            for(int j=i;j<N;j+=i)
            {
                syz[j][cnt[j]++]=i;
            }
        }
    }
}

void dfs(int c,int cur,int i,int j,LL ans1)      //dfs(c,1,i,0,1);
{
    if(cur==c+1)
    {
        if(c&1)
            ans-=ma/ans1;
        else
            ans+=ma/ans1;
        return;
    }
    for(;j<cnt[i];j++)
    {
        dfs(c,cur+1,i,j+1,ans1*syz[i][j]);
    }
}

int main()
{
    int t;
    cin>>t;
    init();
    LL m,n;
    while(t--)
    {
        scanf("%lld%lld",&m,&n);
        ans=m*n;
        ma=max(m,n),mi=min(m,n);
        for(int i=2;i<=mi;i++)
        {
            for(int c=1;c<=cnt[i];c++)
            {
                dfs(c,1,i,0,1);
            }
        }
        printf("%I64d\n",ans);
    }
    return 0;
}

/*
100
23 54
56 54
44 54
10 10
100000 100000
*/
