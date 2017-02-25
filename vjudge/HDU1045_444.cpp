// HDU1045
//http://acm.hdu.edu.cn/showproblem.php?pid=1045


#include <iostream>
#include <string.h>
using namespace std;
const int maxn=510;
int un,vn;
int g[maxn][maxn];
int linker[maxn*maxn];
bool used[maxn*maxn];
int l[maxn][maxn],h[maxn][maxn];
char s[maxn][maxn];
bool dfs(int u)
{
    for(int v=0;v<vn;v++)
        if(g[u][v]&&!used[v])
    {
        used[v]=true;
        if(linker[v]==-1||dfs(linker[v]))
        {
            linker[v]=u;
            return true;
        }
    }
    return false;
}
int hungry()
{
    int res=0;
    memset(linker,-1,sizeof(linker));
    for(int u=0;u<un;u++)
    {
        memset(used,false,sizeof(used));
        if(dfs(u))
            res++;
    }
    return res;
}
void init()
{
    memset(g,0,sizeof(g));
    memset(s,0,sizeof(s));
    memset(h,0,sizeof(h));
    memset(l,0,sizeof(l));
    vn=0,un=0;
}
int main()
{
    int n;
   while(cin>>n)
   {
       init();
       if(n==0)
       break;
       for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        cin>>s[i][j];
       for(int i=0;i<n;i++)
       {
           for(int j=0;j<n;j++)
           {
               if(s[i][j]=='.')
                h[i][j]=un;
               else if(s[i][j]=='X')
                un++;
           }
           un++;
       }
       for(int i=0;i<n;i++)
       {
           for(int j=0;j<n;j++)
           {
               if(s[j][i]=='.')
                l[j][i]=vn;
               else if(s[j][i]=='X')
                vn++;
           }
           vn++;
       }
       for(int i=0;i<n;i++)
       {
           for(int j=0;j<n;j++)
           {
               if(s[i][j]=='.')
                g[h[i][j]][l[i][j]]=1;
           }
       }
       int ans=hungry();
       cout<<ans<<endl;
   }
    return 0;
}
