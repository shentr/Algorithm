// HDU5040
//http://acm.hdu.edu.cn/showproblem.php?pid=5040


#include <iostream>
#include <string.h>
#include <stdio.h>
#include <queue>
using namespace std;
int dx[4]= {0,-1,0,1};
int dy[4]= {-1,0,1,0};
const int maxn=510;
char str[maxn][maxn];
bool vis[maxn][maxn][5];
int n;
int p[maxn];
struct node
{
    int x,y,t;
    friend bool operator<(node a,node b)
    {
        return a.t>b.t;
    }
};
int check(int x,int y,int t)
{
    if(x<0||x>=n||y<0||y>=n||str[x][y]=='#')
        return 0;
    if(p[str[x][y]]!=-1)
        return 1;
    int nx,ny,nowt;
    for(int i=0; i<4; i++)
    {
        nx=dx[i]+x;
        ny=dy[i]+y;
        if(nx<0||nx>=n||ny<0||ny>=n||str[nx][ny]=='#')
            continue;
        int temp=p[str[nx][ny]];
        if(temp>=0&&(temp+t)%4==i)
            return 1;
        /*temp+=t;
            if(temp>4)
            temp%=4;
            if(i==0&&temp==1)
            return false;
            if(i==1&&temp==4)
                return false;
            if(i==2&&temp==3)
                return false;
            if(i==3&&temp==2)
                return false;
                */

    }
    return 2;
}

int bfs(int fx,int fy)
{
    priority_queue<node>q;
    memset(vis,0,sizeof(vis));
    node k1;
    k1.x=fx;
    k1.y=fy;
    k1.t=0;
    q.push(k1);
    while(!q.empty())
    {
        node now=q.top();
        q.pop();
        if(str[now.x][now.y]=='T')
            return now.t;
        int next_x,next_y,next_t;
        next_t=now.t+1;
        if(!vis[now.x][now.y][next_t%4])
        {
            vis[now.x][now.y][next_t%4]=true;
            node k2;
            k2.x=now.x;
            k2.y=now.y;
            k2.t=next_t;
            q.push(k2);
        }
        int nowv=check(now.x,now.y,now.t);
        for(int i=0; i<4; i++)
        {
            next_x=dx[i]+now.x;
            next_y=dy[i]+now.y;
            //next_t=now.t;
            int sta=check(next_x,next_y,now.t);
            if(sta==0)
                continue;
            else  if(sta==1||nowv==1)
                next_t=now.t+3;
            else if(sta==2)
            {
                next_t=now.t+1 ;
            }
            if(!vis[next_x][next_y][next_t%4])
            {
                vis[next_x][next_y][next_t%4]=true;
                node k3;
                k3.x=next_x;
                k3.y=next_y;
                k3.t=next_t;
                q.push(k3);
            }
        }
    }
    return -1;
}
/*int main()
{
    int t;
    int T=0;
    int mi,mj;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        memset(p,-1,sizeof(p));
        p['E']=0,p['S']=1,p['W']=2,p['N']=3;
        for(int i=0; i<n; i++)
        {
            scanf("%s",str[i]);
            for(int j=0; j<n; j++)
            {
                if(str[i][j]=='M')
                    mi=i,mj=j;
            }
        }
        int ans=bfs(mi,mj);
        printf("Case #%d: %d\n",T++,ans);
    }
    return 0;
}*/
int main()
{
    int T=1;
    int t,mi,mj;
    cin>>t;
    while(t--)
    {
        int ans=0;
        cin>>n;
         memset(p,-1,sizeof(p));
        p['E']=0,p['S']=1,p['W']=2,p['N']=3;
        for(int i=0; i<n; i++)
        {
            cin>>str[i];
            //scanf("%s",str[i]);
            for(int j=0; j<n; j++)
            {
                if(str[i][j]=='M')
                {
                    mi=i;
                    mj=j;
                }
            }
        }
        ans=bfs(mi,mj);
        printf("Case #%d: %d\n",T++,ans);
    }
    return 0;

}
