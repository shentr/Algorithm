// HDU4781
//http://acm.hdu.edu.cn/showproblem.php?pid=4781


#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
const int INF=0x3f3f3f3f;
long long T,n,m;
long long g[105][105];
bool vis[105][105];
bool flag[105*105];
struct sa
{
    int u;
    int v;
    int w;
} a[105*105];
int cmp(const sa &a,const sa &b)
{
    if(a.u==b.u)
        return a.v<b.v;
    return a.u<b.u;
}
int main()
{
    ios::sync_with_stdio(false);
    int cases=1;
    cin>>T;
    while(T--)
    {
        long long sum=0;
        memset(a,0,sizeof(a));
        memset(g,0,sizeof(g));
        memset(vis,0,sizeof(vis));
        memset(flag,0,sizeof(flag));
        cin>>n>>m;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(i==j)
                {
                    g[i][j]=0;
                    vis[i][j]=1;
                }
                else g[i][j]=INF;
            }
        }
        cout<<"Case #"<<cases++<<":"<<endl;
        if(m>(n*(n-1)/2))
        {
            cout<<-1<<endl;
            continue;
        }
        for(int i=1; i<n; i++)
        {
            a[i].u=i;
            a[i].v=i+1;
            a[i].w=i;
            g[i][i+1]=i;
            vis[a[i].u][a[i].v]=1;
            flag[i]=1;
            sum+=i;
        }
        a[n].u=n;
        a[n].v=1;
        if((sum+n)%3==0)
        {
            a[n].w=n;
            g[n][1]=n;
            vis[n][1]=1;
            flag[n]=1;
        }
        else if((sum+n+1)%3==0)
        {
            a[n].w=n+1;
            g[n][1]=n+1;
            vis[n][1]=1;
            flag[n+1]=1;
        }
        else if((sum+n+2)%3==0)
        {
            a[n].w=n+2;
            g[n][1]=n+2;
            vis[n][1]=1;
            flag[n+2]=1;
        }
        for(int k=1; k<=n; k++)
        {
            for(int i=1; i<=n; i++)
            {
                for(int j=1; j<=n; j++)
                {
                    if(g[i][k]+g[k][j]<g[i][j])
                        g[i][j]=g[i][k]+g[k][j];
                }
            }
        }

        long long cnt=n;
        int ans=0;
        for(int k=1; k<=m; k++)
        {
            for(int i=1; i<=n; i++)
            {
                for(int j=1; j<=n; j++)
                {
                    if(!flag[k])
                    {
                        //cout<<++ans<<endl;
                        //cout<<k<<endl;
                        if((k%3)==(g[i][j]%3)&&!vis[i][j]&&!vis[j][i])
                        {
                            //cout<<-100<<endl;
                            vis[i][j]=1;
                            // vis[j][i]=1;
                            flag[k]=1;
                            a[++cnt].u=i;
                            a[cnt].v=j;
                            a[cnt].w=k;
                            //cout<<cnt<<endl;
                        }
                    }
                }
            }
        }

        bool num=0;
        for(int i=1; i<=m; i++)
        {
            if(!flag[i])
            {
                num=1;
                break;
            }
        }
        if(num)
        {
            cout<<-1<<endl;
            continue;
        }
        //sort(a+1,a+cnt+1,cmp);
        for(int i=1; i<=cnt; i++)
        {
            cout<<a[i].u<<" ";
            cout<<a[i].v<<" ";
            cout<<a[i].w<<endl;
        }
    }
    return 0;
}
