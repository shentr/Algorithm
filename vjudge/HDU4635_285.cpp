// HDU4635
//http://acm.hdu.edu.cn/showproblem.php?pid=4635


#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <queue>
#include <map>
using namespace std ;
const int INF=0xfffffff ;
struct node 
{
    int s,t,nxt ;
}e[4000005] ;
int n,m,idx,ans,tp,cnt,num[100005],IN[100005],OUT[100005],dfn[100005],vis[100005],low[100005],head[100005],st[100005],belong[100005] ;
void add(int s,int t)
{
    e[cnt].s=s ;
    e[cnt].t=t ;
    e[cnt].nxt=head[s] ;
    head[s]=cnt++ ;
}
void tarjan(int u)
{
    dfn[u]=low[u]=++idx ;
    vis[u]=1 ;
    st[++tp]=u ;
    int v ;
    for(int i=head[u] ;i!=-1 ;i=e[i].nxt)
    {
        v=e[i].t ;
        if(!dfn[v])
        {
            tarjan(v) ;
            low[u]=min(low[u],low[v]) ;
        }
        else if(vis[v])
            low[u]=min(low[u],dfn[v]) ;
    }
    if(dfn[u]==low[u])
    {
        ans++ ;
        while(1)
        {
            v=st[tp--] ;
            vis[v]=0 ;
            belong[v]=ans ;
            num[ans]++ ;
            if(v==u)break ;
        }
    }
}
void sc()
{
    memset(vis,0,sizeof(vis)) ;
    memset(dfn,0,sizeof(dfn)) ;
    memset(num,0,sizeof(num)) ;
    idx=tp=ans=0 ;
    for(int i=1 ;i<=n ;i++)
        if(!dfn[i])
            tarjan(i) ;
}
int main()
{
    int T ;
    scanf("%d",&T) ;
    for(int cas=1 ;cas<=T ;cas++)
    {
        cnt=0 ;
        memset(head,-1,sizeof(head)) ;
        scanf("%d%d",&n,&m) ;
        for(int i=0 ;i<m ;i++)
        {
            int s,t ;
            scanf("%d%d",&s,&t) ;
            add(s,t) ;
        }
        sc() ;
        if(ans==1)
        {
            printf("Case %d: -1\n",cas) ;
            continue ;
        }
        memset(IN,0,sizeof(IN)) ;
        memset(OUT,0,sizeof(OUT)) ;
        for(int u=1 ;u<=n ;u++)
        {
            for(int i=head[u] ;i!=-1 ;i=e[i].nxt)
            {
                int tt=e[i].t ;
                if(belong[tt]==belong[u])continue ;
                IN[belong[tt]]++ ;
                OUT[belong[u]]++ ;
            }
        }
        int ret=-1 ;
        for(int i=1 ;i<=ans ;i++)
        {
            if(!IN[i] || !OUT[i])
                ret=max(ret,n*(n-1)-m-num[i]*(n-num[i])) ;
        }
        printf("Case %d: %d\n",cas,ret) ;
    }
    return 0 ;
}