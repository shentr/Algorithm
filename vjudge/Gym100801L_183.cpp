// Gym100801L
//undefined100801L


#include"bits/stdc++.h"
using namespace std;
int a[1005][1005];
int n,m;
int sum(int x,int y,int z)
{
    int he=0;
    for(int i=y;i<=z;i++)
    he=max(he,a[x][i]);
    return he;
}
int sum2(int x,int y,int z)
{
    int he2=0;
    for(int i=y;i<=z;i++)
        he2=max(a[i][x],he2);
    return he2;
}
int main()
{
    ifstream fin("lucky.in");
    ofstream fout("lucky.out");
    while(fin>>n>>m)
    {
        int ans=0;
        memset(a,0,sizeof(a));
        for(int i=1; i<=n; i++)
            for(int j=1; j<=m; j++)
            {
                fin>>a[i][j];
            }
        for(int i=1; i<=n; i++)
            for(int j=1; j<=m; j++)
            {
                if(a[i][j]>sum(i,0,j-1))
                {
                    ans++;
                }
                if(a[i][j]>sum(i,j+1,m+1))
                    ans++;
                if(a[i][j]>sum2(j,0,i-1))
                    ans++;
                if(a[i][j]>sum2(j,i+1,n+1))
                    ans++;
            }
            fout<<ans<<endl;
    }
    return 0;
}
