// POJ2485
//http://poj.org/problem?id=2485


#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
const int maxn=1005;
const int INF=0x3f3f3f3f;
bool vis[maxn];
bool used[maxn][maxn];
int pre[maxn];
int lowc[maxn];
int Max[maxn][maxn];
int mapp[maxn][maxn];
int prim(int cost[][maxn],int n)
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
//        if(minc==INF)
//            return -1;
        ans+=minc;
        vis[p]=true;
        used[p][pre[p]]=used[pre[p]][p]=true;
        for(int j=0; j<n; j++)
        {
            if(vis[j]&&j!=p)
                Max[j][p]=Max[p][j]=max(Max[j][pre[p]],lowc[p]);
            if(!vis[j]&&lowc[j]>cost[p][j])
            {
                lowc[j]=cost[p][j];
                pre[j]=p;
            }
        }

    }
    int sumn=0;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            sumn=max(sumn,Max[i][j]);
    return sumn;
}
int main()
{
    //freopen("cin.txt","r",stdin);
    //freopen("cout.txt","w",stdout);
    int T,n,s;
    ios::sync_with_stdio(false);
    while(cin>>T)
    {
        while(T--)
        {
            cin>>n;
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<n; j++)
                {
                    if(i==j)
                        mapp[i][j]=0;
                    else mapp[i][j]=INF;
                }
            }
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<n; j++)
                {
                    cin>>s;
                    mapp[i][j]=min(mapp[i][j],s);
                }
            }
            int sum=prim(mapp,n);
            cout<<sum<<endl;
        }
    }
    return 0;
}
