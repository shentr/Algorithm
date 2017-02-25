// HDU4635
//http://acm.hdu.edu.cn/showproblem.php?pid=4635


#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <stack>
using namespace std;
const int maxn=200005;
vector <int>G[maxn];
int pre[maxn],lowlink[maxn],sccno[maxn],dfs_clock,scc_cnt;
stack<int>S;
void dfs(int u)
{
    pre[u]=lowlink[u]=++dfs_clock;
    S.push(u);
    for(int i=0; i<G[u].size(); i++)
    {
        int v=G[u][i];
        if(!pre[v])
        {
            dfs(v);
            lowlink[u]=min(lowlink[u],lowlink[v]);

        }
        else if(!sccno[v])
        {
            lowlink[u]=min(lowlink[u],pre[v]);
        }
    }
    if(lowlink[u]==pre[u])
    {
        scc_cnt++;
        for(;;)
        {
            int x=S.top();
            S.pop();
            sccno[x]=scc_cnt;
            if(x==u)
                break;
        }
    }
}
void find_scc(int n)
{
    dfs_clock=scc_cnt=0;
    memset(sccno,0,sizeof(sccno));
    memset(pre,0,sizeof(pre));
    for(int i=0; i<n; i++)if(!pre[i])dfs(i);
}

int in0[maxn],out0[maxn];
int main()
{
    int T,n,m,cas=1;
    int num[maxn];
    scanf("%d",&T);
    while(T--)
    {
        memset(in0,0,sizeof(in0));
        memset(out0,0,sizeof(out0));
        memset(num,0,sizeof(num));
        scanf("%d%d",&n,&m);
        for(int i=0; i<n; i++)
            G[i].clear();
        for(int i=0; i<m; i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            u--;
            v--;
            G[u].push_back(v);
        }
        find_scc(n);
        for(int i=1; i<=scc_cnt; i++)
            in0[i]=out0[i]=1;
        for(int u=0; u<n; u++)
        {
            for(int i=0; i<G[u].size(); i++)
            {
                int v=G[u][i];
                if(sccno[u]!=sccno[v])
                    in0[sccno[v]]=out0[sccno[u]]=0;
            }
            num[sccno[u]]++;
        }
        int maxnum=maxn;
        for(int  i=1; i<=scc_cnt; i++)
        {
            if(in0[i]==1||out0[i]==1)
            {
                if(num[i]<maxnum)
                    maxnum=num[i];
            }
        }
        //cout<<maxnum<<endl;
        long long ans=n*(n-1)-m-(n-maxnum)*maxnum;
        if(scc_cnt!=1) printf("Case %d: %lld\n",cas++,ans);
        else printf("Case %d: -1\n",cas++);


    }
    return 0;
}
