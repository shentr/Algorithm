// UVA10325
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=10325


#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long LL;
LL a[20],m;
LL n,ans;

LL lcm(LL a,LL b)
{
    return a/__gcd(a,b)*b;
}

void dfs(int c,int cur,int i,LL ans1)      //dfs(c,1,i,0,1);
{
    if(cur==c+1)
    {
        if(c&1)
            ans-=n/ans1;
        else
            ans+=n/ans1;
        return;
    }
    for(;i<m;i++)
    {
        dfs(c,cur+1,i+1,lcm(ans1,a[i]));
    }
}

int main()
{
    while(cin>>n>>m)
    {
        for(int i=0;i<m;i++)
            scanf("%lld",&a[i]);
        ans=n;
        for(int c=1;c<=m;c++)
            dfs(c,1,0,1);
        printf("%lld\n",ans);
    }
}
