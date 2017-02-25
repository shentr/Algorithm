// POJ1258
//http://poj.org/problem?id=1258


#include <iostream>
#include <string.h>
using namespace std;
const int INF=0x3f3f3f3f;
const int maxn=110;
bool vis[maxn];
int lowc[maxn];
int prim(int cost[][maxn],int n)
{
    int ans=0;
    memset(vis,false,sizeof(vis));
    vis[0]=true;
    for(int i=1;i<=n;i++)
        lowc[i]=cost[0][i];
    for(int i=1;i<n;i++)
    {
        int minc=INF;
        int p=-1;
        for(int j=0;j<n;j++)
            if(!vis[j]&&minc>lowc[j])
        {
            minc=lowc[j];
            p=j;
        }
        ans+=minc;
        vis[p]=true;
        for(int j=0;j<n;j++)
            if(!vis[j]&&lowc[j]>cost[p][j])
            lowc[j]=cost[p][j];
    }
    return ans;
}
int main()
{
    int n;
    int a[maxn][maxn];
    while(cin>>n)
    {
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                a[i][j]=INF;
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                {
                    cin>>a[i][j];
                    a[i][j]=min(a[j][i],a[i][j]);
                }
        int sum=prim(a,n);
        cout<<sum<<endl;
    }
    return 0;
}
