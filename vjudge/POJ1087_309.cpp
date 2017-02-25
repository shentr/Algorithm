// POJ1087
//http://poj.org/problem?id=1087


#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
const int oo=1e9;
const int mm=111111;
const int mn=999;
int node,src,dest,edge,k;
int ver[mm],flow[mm],next[mm];
int head[mn],work[mn],dis[mn],q[mn];
char str1[30],str2[30],str3[30],str4[30],str5[30];
char name[10005][30];
int s1[105][2],s2[105][2],s3[105][2],s4[105][2],s5[105][2];
void prepare(int _node,int _src,int _dest)
{
    node=_node,src=_src,dest=_dest;
    for(int i=0; i<node; i++)
        head[i]=-1;
        edge=0;
}
void addedge(int u,int v,int c)
{
    ver[edge]=v,flow[edge]=c,next[edge]=head[u],head[u]=edge++;
    ver[edge]=u,flow[edge]=0,next[edge]=head[v],head[v]=edge++;

}
bool Dicnic_bfs()
{
    int i,u,v,l,r=0;
    for(i=0; i<node; ++i)
        dis[i]=-1;
    dis[q[r++]=src]=0;
    for(l=0; l<r; ++l)
        for(i=head[u=q[l]]; i>=0; i=next[i])
            if(flow[i]&&dis[v=ver[i]]<0)
            {
                dis[q[r++]=v]=dis[u]+1;
                if(v==dest)
                    return 1;
            }
    return 0;
}
int Dicnic_dfs(int u,int exp)
{
    if(u==dest)
        return exp;
    for(int &i=work[u],v,tmp; i>=0; i=next[i])
        if(flow[i]&&dis[v=ver[i]]==dis[u]+1&&(tmp=Dicnic_dfs(v,min(exp,flow[i])))>0)
        {
            flow[i]-=tmp;
            flow[i^1]+=tmp;
            return tmp;
        }
    return 0;
}
int Dicnic_flow()
{
    int i,ret=0,delta;
    while(Dicnic_bfs())
    {
        for(i=0; i<node; i++)
            work[i]=head[i];
        while(delta=Dicnic_dfs(src,oo))
            ret+=delta;
    }
    return ret;
}
int change(char *str)
{
    if(k==0)
    {
        k++;
        strcpy(name[k],str);
        return k;
    }
    for(int i=1; i<=k; i++)
    {
        if(strcmp(name[i],str)==0)
            return i;
    }
    k++;
    strcpy(name[k],str);
    return k;
}
void init()
{
    memset(str1,0,sizeof(str1));
    memset(str2,0,sizeof(str2));
    memset(str3,0,sizeof(str3));
    memset(str4,0,sizeof(str4));
    memset(str5,0,sizeof(str5));
    memset(s1,0,sizeof(s1));
    memset(s2,0,sizeof(s2));
    memset(s3,0,sizeof(s3));
    memset(s4,0,sizeof(s4));
    memset(s5,0,sizeof(s5));
    memset(name,0,sizeof(name));
    k=0;

}
int main()
{
    int n,m,k1;
    while(scanf("%d",&n)!=EOF)
    {
        init();
        for(int i=1; i<=n; i++)
        {
            scanf("%s",str1);
            s1[i][0]=change(str1);
        }
        scanf("%d",&m);
       // prepare(n+m+2,0,n+m+1);
        for(int i=1; i<=m; i++)
        {
            scanf("%s",str2);
            scanf("%s",str3);
            s2[i][0]=change(str2);
            s3[i][0]=change(str3);
        }
        scanf("%d",&k1);
        for(int i=1; i<=k1; i++)
        {
            scanf("%s",str4);
            scanf("%s",str5);
            s4[i][0]=change(str4);
            s5[i][0]=change(str5);
        }
        prepare(k+2,0,k+1);
        //cout<<k<<" "<<n+m<<endl;
        for(int i=1; i<=n; i++)
        {
            addedge(src,s1[i][0],1);
        }
        for(int i=1; i<=m; i++)
        {
            addedge(s2[i][0],dest,1);
            addedge(s3[i][0],s2[i][0],1);
        }
        for(int i=1; i<=k1; i++)
        {
            addedge(s5[i][0],s4[i][0],oo);
        }
        printf("%d\n",m-Dicnic_flow());
    }
    return 0;
}
