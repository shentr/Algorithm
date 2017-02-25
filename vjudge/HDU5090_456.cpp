// HDU5090
//http://acm.hdu.edu.cn/showproblem.php?pid=5090


#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

const int maxn=105;
int un,vn;
int g[maxn][maxn];
int a[maxn];
int linker[maxn*maxn];
bool used[maxn*maxn];
bool dfs(int u)
{
    for(int v=1; v<=vn; v++)
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
    for(int u=1; u<=un; u++)
    {
        memset(used,false,sizeof(used));
        if(dfs(u))
            res++;
    }
    return res;
}
int cmp(const int &x,const int &y)
{
    return x<y;
}
int main()
{
    int T,n,k;
    cin>>T;
    while(T--)
    {
        memset(g,0,sizeof(g));
        memset(a,0,sizeof(a));
        cin>>n>>k;
        for(int i=1; i<=n; i++)
            cin>>a[i];
        sort(a+1,a+n+1,cmp);
        for(int i=1; i<=n; i++)
        {
            while(a[i]<=n)
            {
                g[a[i]][i]=1;
               // cout<<a[i]<<" "<<i<<endl;
                a[i]=a[i]+k;
            }
        }
        vn=n,un=n;
        int ans=hungry();
        //cout<<ans<<endl;
        if(ans==n)
            cout<<"Jerry"<<endl;
        else cout<<"Tom"<<endl;
//        for(int i=1;i<=n;i++)
//            cout<<linker[i]<<" ";
//        cout<<endl;
    }
    return 0;
}
