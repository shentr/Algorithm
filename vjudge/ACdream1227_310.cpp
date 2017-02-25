// ACdream1227
//http://acdream.info/problem?pid=1227


#include <iostream>
#include <string.h>
using namespace std;
const int maxn=405;
const int INF=0x3f3f3f3f;
int nx,ny;
int n,m,v;
int g[maxn][maxn];
int linker[maxn],lx[maxn],ly[maxn],marry[maxn],zhi[maxn];
int slack[maxn];
bool visx[maxn],visy[maxn];
bool dfs(int x)
{
    visx[x]=true;
    for(int y=1;y<=ny;y++)
    {
        if(visy[y])
            continue;
        int tmp=lx[x]+ly[y]-g[x][y];
        if(tmp==0)
        {
            visy[y]=true;
            if(linker[y]==-1||dfs(linker[y]))
            {
                linker[y]=x;
             //   marry[x]=y;
                return true;
            }
        }
        else if(slack[y]>tmp)
            slack[y]=tmp;
    }
    return false;
}
void KM()
{
    memset(linker,-1,sizeof(linker));
    memset(ly,0,sizeof(ly));
    memset(marry,0,sizeof(marry));
    for(int i=1;i<=nx;i++)
    {
        lx[i]=-INF;
        for(int j=1;j<=ny;j++)
           if(g[i][j]>lx[i])
            lx[i]=g[i][j];
    }
    for(int x=1;x<=nx;x++)
    {
        for(int i=1;i<=ny;i++)
            slack[i]=INF;
        while(true)
        {
            memset(visx,false,sizeof(visx));
            memset(visy,false,sizeof(visy));
            if(dfs(x))
                break;
            int d=INF;
            for(int i=1;i<=ny;i++)
                if(!visy[i]&&d>slack[i])
                d=slack[i];
            for(int i=1;i<=nx;i++)
                if(visx[i])
                   lx[i]-=d;
            for(int i=1;i<=ny;i++)
            {
                if(visy[i])
                    ly[i]+=d;
                else slack[i]-=d;
            }
        }
    }
    int res=0;
    for(int i=1;i<=ny;i++)
    {
        if(linker[i]!=-1)
            res+=g[linker[i]][i];
        //return res;
    }
//     for(int i=1;i<=n;i++)
//            if(linker[i]&&i<n)
//            marry[linker[i]]=i;
//        for(int i=1;i<n;i++)
//            cout<<marry[i]<<" "<<endl;
//        cout<<marry[n]<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>n)
    {
        memset(zhi,0,sizeof(zhi));
        memset(g,0,sizeof(g));
        for(int i=1;i<=n;i++)
        {
            cin>>zhi[i];
        }
        for(int i=1;i<=n;i++)
        {
            cin>>m;
            for(int j=1;j<=m;j++)
            {
                cin>>v;
                g[i][v]=zhi[i]*zhi[i];
            }
        }
        nx=ny=n;
        KM();
//          memset(ans,0,sizeof(ans));
//        for(int i=1; i<=n; i++)
//        {
//            if(g[linker[i]][i]) ans[linker[i]]=i;
//        }
//        for(int i=1; i<=n; i++)
//        {
//            if (i<n) printf("%d ",ans[i]);
//            else printf("%d\n",ans[i]);
//        }
       for(int i=1;i<=n;i++)
           if(g[linker[i]][i])
            marry[linker[i]]=i;
       for(int i=1;i<n;i++)
           cout<<marry[i]<<" "<<endl;
        cout<<marry[n]<<endl;

    }
    return 0;
}
