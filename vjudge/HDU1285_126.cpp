// HDU1285
//http://acm.hdu.edu.cn/showproblem.php?pid=1285


#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
const int maxn=1505;

struct cmp
{
    bool operator ()(int x,int y)
    {
        return x>y;
    }
};

int indegree[maxn];
int n,m,seq[maxn];
vector<int>vec[maxn];

int topo()
{
    priority_queue<int,vector<int>,cmp>q;
    int indeg[maxn];
    for(int i=1; i<=n; i++)
    {
        indeg[i]=indegree[i];
        if(indeg[i]==0)
            q.push(i);
    }
    int k=0;
    bool res=false;
    while(!q.empty())
    {
        if(q.size()!=1)res=true;
        int u=q.top();
        q.pop();
        seq[k++]=u;
        for(int i=0; i<vec[u].size(); i++)
        {
            int v=vec[u][i];
            indeg[v]--;
            if(indeg[v]==0)
                q.push(v);
        }
    }
    if(k<n)return -1;
    if(res)return 0;
    return 1;
}

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=0;i<=n;i++)
        {
            vec[i].clear();
            indegree[i]=0;
        }
        for(int i=0;i<m;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            vec[u].push_back(v);
            indegree[v]++;
        }
        for(int i=1;i<=n;i++)
        {
            sort(vec[i].begin(),vec[i].end());
        }
        topo();
        for(int i=0;i<n;i++)
        {
            printf(i==n-1?"%d\n":"%d ",seq[i]);
        }
    }
    return 0;
}
