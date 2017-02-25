// CodeForces405E
//http://codeforces.com/problemset/problem/405E


#include <iostream>
#include <queue>
#include <vector>
#include <stdio.h>
#include <string.h>
using namespace std;
const int T=1e5+5;
struct node
{
    int num,x;
}t;
vector<node>p[T];
bool flag[T];
int dfs(int now)
{
    int l=p[now].size();
    int r;
    queue<int>q;
    node k;
    for(int i=0;i<l;i++)
    {
        k=p[now][i];
        if(flag[k.num])
            continue;
        flag[k.num]=1;
        r=dfs(k.x);
        if(r)
            printf("%d %d %d\n",now,k.x,r);
        else q.push(k.x);
    }
    while(q.size()>=2)
    {
        int x1=q.front();
        q.pop();
        int x2=q.front();
        q.pop();
        printf("%d %d %d\n",x1,now,x2);
    }
    while(!q.empty())
    {
        int x3=q.front();
        return x3;
    }
    return 0;

}
int main()
{
    int n,m,a,b;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=0;i<=n;i++)
            p[i].clear();
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d",&a,&b);
            t.num=i;
            t.x=b;
            p[a].push_back(t);
            t.x=a;
            p[b].push_back(t);
        }
        if(m%2==1)
            printf("No solution\n");
        else
            {
                memset(flag,0,sizeof(flag));
                dfs(1);
            }
    }
    return 0;
}
