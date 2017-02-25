// POJ3669
//http://poj.org/problem?id=3669


#include <iostream>
#include <queue>
#include <string.h>
#define INF 99999999
using namespace std;
int s[305][305];
bool vis[305][305];
int xx[5][2]= {{0,1},{1,0},{-1,0},{0,-1},{0,0}};
int n,m;
struct sa
{
    int x,y,t;
} p,now,r;
int bfs(int x,int y,int t)
{
    if(t==-1)
        return 0;
    queue<sa>q;
    p.x=x;
    p.y=y;
    p.t=0;
    q.push(p);
    while(!q.empty())
    {
        now=q.front();
        q.pop();
        for(int i=0; i<4; i++)
        {
            p.x=now.x+xx[i][0];
            p.y=now.y+xx[i][1];
            p.t=now.t+1;
            if(p.x<0||p.x>302||p.y<0||p.y>302||vis[p.x][p.y])
                continue;
            if(s[p.x][p.y]==-1)
            {
                return p.t;
            }
            else if(s[p.x][p.y]>p.t&&!vis[p.x][p.y])
            {
                vis[p.x][p.y]=1;
                q.push(p);
            }


        }
    }
    return -1;
}
int main()
{
    int x,y,t;
    while(cin>>n)
    {
        int sum=0;
        memset(vis,0,sizeof(vis));
        memset(s,-1,sizeof(s));
        for(int i=1; i<=n; i++)
        {
            cin>>x>>y>>t;
            for(int i=0; i<5; i++)
            {
                int  dx=x+xx[i][0];
                int  dy=y+xx[i][1];
                // if(dx<0||dx>302||dy<0||dy>302||vis[dx][dy])
                //  continue;
                if(dx>=0&&dx<=302&&dy>=0&&dy<=302&&!vis[dx][dy])
                {
                    if(s[dx][dy]==-1)
                    {
                        s[dx][dy]=t;
                    }
                    else s[dx][dy]=min(s[dx][dy],t);
                }

            }
        }
        vis[0][0]=1;
        sum=bfs(0,0,s[0][0]);
        // cout<<s[0][0]<<endl;
        cout<<sum<<endl;
    }
    return 0;
}
