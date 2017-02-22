// 1754 ( I Hate It )
//acm.hdu.edu.cn/showproblem.php?pid=1754


#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=200005;
int grt[maxn<<2];

void build(int l,int r,int rt)
{
    if(l==r)
    {
        scanf("%d",&grt[rt]);
        return ;
    }
    int m=(l+r)>>1;
    build(l,m,rt<<1);
    build(m+1,r,rt<<1|1);
    grt[rt]=max(grt[rt<<1],grt[rt<<1|1]);
}

void update(int p,int cg,int l,int r,int rt)
{
    if(l==r)
    {
        grt[rt]=cg;
        return ;
    }
    int m=(l+r)>>1;
    if(p<=m)
        update(p,cg,l,m,rt<<1);
    else
        update(p,cg,m+1,r,rt<<1|1);
    grt[rt]=max(grt[rt<<1],grt[rt<<1|1]);
}

int query(int a,int b,int l,int r,int rt)
{
    if(a<=l&&b>=r)
        return grt[rt];
    int ans=-1;
    int m=(l+r)>>1;
    if(a<=m)
        ans=max(ans,query(a,b,l,m,rt<<1));
    if(b>m)
        ans=max(ans,query(a,b,m+1,r,rt<<1|1));
    return ans;
}

int main()
{
    int n,m;
    char oprt[10];
    int a,b;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(grt,0,sizeof(grt));
        build(1,n,1);
        for(int i=0;i<m;i++)
        {
            scanf("%s%d%d",&oprt,&a,&b);
            if(oprt[0]=='U')
                update(a,b,1,n,1);
            if(oprt[0]=='Q')
                printf("%d\n",query(a,b,1,n,1));
        }
    }
    return 0;
}
