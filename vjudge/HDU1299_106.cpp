// HDU1299
//http://acm.hdu.edu.cn/showproblem.php?pid=1299


#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 1e7+10;

typedef long long LL;

int p[maxn/10],cnt;
bool vis[maxn];
int fac[1000],tot;

void init(){
    cnt=0;
    memset(vis,0,sizeof(vis));
    for(int i=2;i<maxn;i++){
        if(!vis[i]){
            p[cnt++]=i;
            for(int j=i+i;j<maxn;j+=i) vis[j]=1;
        }
    }
}

LL get(LL x){
    tot=0;
    memset(fac,0,sizeof(fac));
    for(int i=0;i<cnt&&p[i]*p[i]<=x;i++){
        if(x%p[i]==0){
            while(x%p[i]==0) fac[tot]++,x/=p[i];
            tot++;
        }
    }
    if(x>1) fac[tot++]=1;
    LL ans = 1;
    for(int i=0;i<tot;i++) ans=ans*(2*fac[i]+1);
    return ans ;
}

int main()
{
    init();
    int t,cas=1;
    scanf("%d",&t);
    while(t--){
        LL n;
        scanf("%I64d",&n);
        printf("Scenario #%d:\n%I64d\n\n",cas++,(get(n)+1)/2);
    }
    return 0;
}