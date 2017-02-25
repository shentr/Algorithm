// UVA11383
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=11383


#include <iostream>
#include <stdio.h>
#include <string.h>
/*using namespace std;
const int N=505;
const int INF=0x3f3f3f3f;
int nx,ny;
int linker[N],lx[N],ly[N];
int g[N][N];
int slack[N];
bool visx[N],visy[N];*/
#define M 555
#define INF 0x3f3f3f3f
using namespace std;
int abs(int x)
{
    return x>0?x:-x;
}
int n,m,nx,ny;
int linker[M],lx[M],ly[M],slack[M];///lx,ly为顶标，nx,ny分别为x点集y点集的个数
int visx[M],visy[M],g[M][M];
bool dfs(int x)
{
    visx[x]=true;
    for(int y=0;y<ny;y++)
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
                return true;
            }
        }
        else if(slack[y]>tmp)
            slack[y]=tmp;
    }
    return false;
}

/*int dfs(int x)
{
    visx[x] = 1;
    for (int y = 0; y < ny; y ++)
    {
        if (visy[y]) continue;
        int t = lx[x] + ly[y] - g[x][y];
        if (t == 0)
        {
            visy[y] = 1;
            if (linker[y] == -1||dfs(linker[y]))
            {
                linker[y] = x;
                return 1;
            }
        }
        else if (slack[y] > t)  ///不在相等子图中slack 取最小的
            slack[y] = t;
    }
    return 0;
}*/
int KM()
{
    memset(linker,-1,sizeof(linker));
    memset(ly,0,sizeof(ly));
    for(int i=0;i<nx;i++)
    {
        lx[i]=-INF;
        for(int j=0;j<ny;j++)
            if(g[i][j]>lx[i])
            lx[i]=g[i][j];
    }
 for (int x = 0; x <nx; x ++)
    {
        for (int i = 0; i < ny; i ++)
            slack[i] = INF;

        while(true)
        {
            memset(visx,false,sizeof(visx));
            memset(visy,false,sizeof(visy));
            if(dfs(x))
                break;
            int d=INF;
            for(int i=0;i<ny;i++)
                if(!visy[i]&&d>slack[i])
                d=slack[i];
            for(int i=0;i<nx;i++)
                if(visx[i])
                lx[i]-=d;
            for(int i=0;i<ny;i++)
            {
                if(visy[i])
                    ly[i]+=d;
                else slack[i]-=d;
            }
        }
    }
    int res=0;
    for(int i=0;i<ny;i++)
       if(linker[i]!=-1)
        res+=g[linker[i]][i];
       return res;
}

int main()
{
        int n,ans;
    while(cin>>n)
    {
         nx=ny=n;
        for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            scanf("%d",&g[i][j]);
        }

         ans=KM();
        for(int i=0;i<nx-1;i++)
            cout<<lx[i]<<" ";
        cout<<lx[nx-1]<<endl;
        for(int i=0;i<ny-1;i++)
            cout<<ly[i]<<" ";
        cout<<ly[ny-1]<<endl;

        cout<<ans<<endl;
    }
    return 0;
}
/*int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        nx=ny=n;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            scanf("%d",&g[i][j]);
           // printf("%d ",w[i][j]);
        }
        printf("%d\n",KM());
    }
}*/

