// POJ1734
//http://poj.org/problem?id=1734


#include<iostream>
#include<cstdio>
using namespace std;
const int N=105;
const int inf=9999999;
int dis[N][N],sp[N][N],ans[N],spp[N][N];
int n,m,a,b,va,minn,cnt;

void init()
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            dis[i][j]=inf;
            spp[i][j]=i;
        }
        for(int i=1;i<=n;i++)
            dis[i][i]=0;
}

void floyd()
{
    minn=inf;
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<k;i++)
            for(int j=i+1;j<k;j++)
            if(sp[i][j]+dis[i][k]+dis[k][j]<minn)
            {
                minn=sp[i][j]+dis[i][k]+dis[k][j];
                int p=j;
                cnt=0;
                while(p!=i)
                {
                    ans[cnt++]=p;
                    p=spp[i][p];
                }
					ans[cnt++]=i;
					ans[cnt++]=k;
            }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
            {
                if(sp[i][k]+sp[k][j]<sp[i][j])
                {
                    sp[i][j]=sp[i][k]+sp[k][j];
                    spp[i][j]=spp[k][j];
                }
            }
    }
}

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        init();
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&a,&b,&va);
            if(dis[a][b]>va||dis[b][a]>va)
            dis[a][b]=dis[b][a]=va;
        }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
            sp[i][j]=dis[i][j];
        floyd();
        if(minn==inf)
            printf("No solution.\n");
        else
        {
            printf("%d",ans[0]);
            for(int i=1;i<cnt;i++)
                printf(" %d",ans[i]);
            printf("\n");
        }
    }
    return 0;
}
