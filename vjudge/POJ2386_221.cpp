// POJ2386
//http://poj.org/problem?id=2386


#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
char s[105][105];
int n,m;
void dfs(int x,int y)
{
    s[x][y]='.';
    for(int dx=-1; dx<=1; dx++)
        for(int dy=-1; dy<=1; dy++)
        {
            int nx=dx+x;
            int ny=dy+y;
            if(nx>=0&&nx<n&&ny>=0&&ny<m&&s[nx][ny]=='W')
            {
                dfs(nx,ny);
            }
        }
}
int main()
{
    while(cin>>n>>m)
    {
        memset(s,0,sizeof(s));
        int sum=0;
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
            {
                //scanf("%c",&s[i][j]);
                cin>>s[i][j];
            }
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
            {
               if(s[i][j]=='W')
                {
                    dfs(i,j);
                    sum++;
                }
            }
            cout<<sum<<endl;

    }
    return 0;
}
