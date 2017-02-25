// ACdream1084
//http://acdream.info/problem?pid=1084


#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 1e6+10;

typedef long long LL;

int pri[maxn],cnt;
bool vis[maxn];
int fac[1000],num;
int Count[1000];
LL sum[maxn];
void init(){
    memset(vis,0,sizeof(vis));
    cnt=0;
    for(int i=2;i<maxn;i++){
        if(!vis[i]){
            pri[cnt++]=i;
            for(int j=i+i;j<maxn;j+=i) vis[j]=1;
        }
    }
}

void getFactor(int x){
    num=0;
    memset(Count,0,sizeof(Count));
    for(int i=0;i<cnt&&pri[i]*pri[i]<=x;i++){
        if(x%pri[i]==0){
            fac[num]=pri[i];
            while(x%pri[i]==0) Count[num]++,x/=pri[i];
            num++;
        }
    }
    if(x>1) fac[num]=x,Count[num++]=1;
}

LL getNum(int n,int p){
    if(n<p) return 0;
    return getNum(n/p,p)+(LL)n/p;
}

int main()
{
    init();
    int t,n,m,k;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&n,&m,&k);
        getFactor(k);
        LL ans = 1000000000;
        //for(int i=0;i<num;i++) cout<<Count[i]<<" ";
        //cout<<endl;
        for(int i=0;i<num;i++){
            //cout<<getNum(n,fac[i])<<" "<<getNum(m,fac[i])<<endl;
            sum[i]=getNum(n,fac[i])-getNum(n-m,fac[i]);
            ans=min(sum[i]/Count[i],ans);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
