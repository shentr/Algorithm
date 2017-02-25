// Gym100703A
//undefined100703A


#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
const int maxn=1005;
const int INF=0x3f3f3f3f;
bool vis[maxn];
int lowc[maxn];
int pre[maxn];
int Max[maxn][maxn];
bool used[maxn][maxn];
char s[maxn][50];
int g[maxn][maxn];
void prim(int cost[][maxn],int n)
{
    int ans=0;
    memset(vis,false,sizeof(vis));
    memset(Max,0,sizeof(Max));
    memset(used,false,sizeof(used));
    vis[0]=true;
    pre[0]=-1;
    for(int i=1; i<n; i++)
    {
        lowc[i]=cost[0][i];
        pre[i]=0;
    }
    lowc[0]=0;
    for(int i=1; i<n; i++)
    {
        int minc=INF;
        int p=-1;
        for(int j=0; j<n; j++)
            if(!vis[j]&&minc>lowc[j])
            {
                minc=lowc[j];
                p=j;
            }
        //if(minc==INF)
        //   return -1;
        ans+=minc;
        vis[p]=true;
        used[p][pre[p]]=used[pre[p]][p]=true;
        for(int j=0; j<n; j++)
        {
            if(vis[j]&&j!=p)
               {
                   Max[j][p]=Max[p][j]=max(Max[j][pre[p]],lowc[p]);
                 //  cout<<Max[j][p]<<endl;
               }
            if(!vis[j]&&lowc[j]>cost[p][j])
            {
                lowc[j]=cost[p][j];
                pre[j]=p;
            }
        }
    }

}

int main()
{
    ios::sync_with_stdio(false);
    int n,m;
    while(cin>>n>>m)
    {
        // cin>>s[]
        int sum=0,ans=0;
        memset(s,0,sizeof(s));
        memset(g,0,sizeof(g));
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                cin>>s[i][j];
            }
        }
        for(int i=0; i<n; i++)
        {
            for(int k=i+1; k<n; k++)
            {
                for(int j=0; j<m; j++)
                {
                    int tmp=abs((s[i][j]-'a')-(s[k][j]-'a'));
                    ans=max(ans,tmp);
                }
                g[i][k]=g[k][i]=ans;
                ans=0;
            }
        }
       /* for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            cout<<g[i][j]<<" ";
            cout<<endl;
        }*/
        prim(g,n);
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(i==j)
                    continue;
                sum=max(sum,Max[i][j]);
               // cout<<Max[i][j]<<endl;
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
