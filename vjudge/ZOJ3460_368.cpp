// ZOJ3460
//http://acm.zju.edu.cn/onlinejudge/showProblem.do?problemCode=3460


#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>
using namespace std;
const int maxn=55;
int m,n;
int g[maxn*maxn][maxn];
int linker[maxn*maxn];
bool used [maxn*maxn];
double d[maxn*maxn][maxn];
struct node
{
    int x,y;
}target[maxn],tower[maxn];
double change(node a,node b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double a[2505][55];
bool dfs(int u)
{
    int v;
    for(int v=0; v<m; v++)
    {
        if(g[u][v]&&!used[v])
        {
            used[v]=true;
            if(linker[v]==-1||dfs(linker[v]))
            {
                linker[v]=u;
                return true;
            }
        }
    }
    return false;
}

int hungary()
{
    int res=0;
    int u;
    memset(linker,-1,sizeof(linker));
    for(u=0; u<n*m; u++)
    {
        memset(used,0,sizeof(used));
        if(dfs(u))res++;
    }
    return res;
}
void init()
{
    memset(target,0,sizeof(target));
    memset(tower,0,sizeof(tower));
    memset(d,0,sizeof(d));
    memset(g,0,sizeof(g));
}


    double t1,t2,v;
int main()
{
   //int n,m;
    while(~scanf("%d%d%lf%lf%lf",&n,&m,&t1,&t2,&v))
    {
        t1/=60.0;
        for(int i=0; i<m; i++)
        {
            scanf("%d%d",&target[i].x,&target[i].y);
        }
        for(int i=0; i<n; i++)
        {
            scanf("%d%d",&tower[i].x,&tower[i].y);
        }
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                for(int k=0; k<m; k++)
                {
                    d[m*j+i][k]=(i+1)*t1+i*t2+change(tower[j],target[k])/v;

                }
            }
        }
        double l=0.0,r=200000000000.0,mid;
        while(r-l>1e-9)
        {
            mid=(l+r)/2.0;
            memset(g,0,sizeof(g));
            for(int i=0; i<m*n; i++)
            {
                for(int j=0; j<m; j++)
                {
                    if(d[i][j]<=mid)
                        g[i][j]=1;
                }
            }
            if(hungary()==m)
            {
                r=mid;

            }
            else
                l=mid;
        }
        printf("%.6lf\n",mid);
    }

    return 0;
}
