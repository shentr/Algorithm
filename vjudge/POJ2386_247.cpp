// POJ2386
//http://poj.org/problem?id=2386


#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
int xx[8][2] = {{0,1},{0,-1},{-1,0},{1,0},{1,1},{1,-1},{-1,-1},{-1,1}};
char s[105][105];
int n,m;
struct sa
{
    int x,y;
} t,a;

void bfs(int x,int y)
{
    //q.push(s[x][y]);
    queue<sa>q;
    s[x][y]='.';
    t.x=x;
    t.y=y;
    q.push(t);
    while(!q.empty())
    {
        t=q.front();
        q.pop();
        for(int i=0; i<8; i++)
        {
            int x1=t.x+xx[i][0];
            int y1=t.y+xx[i][1];
            if(x1>=0&&x1<n&&y1>=0&&y1<m&&s[x1][y1]=='W')
            {
                s[x1][y1]='.';
                a.x=x1;
                a.y=y1;
                q.push(a);
            }
        }
    }
}
int main()
{
    while(cin>>n>>m)
    {
        //while(!q.empty())
        //    q.pop();
        int sum=0;
        memset(s,0,sizeof(s));
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                cin>>s[i][j];
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
            {
                if(s[i][j]=='W')
                {
                    // q.push(s[i][j]);
                    bfs(i,j);
                    sum++;
                }
            }
        cout<<sum<<endl;

    }
    return 0;
}
