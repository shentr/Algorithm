// POJ1979
//http://poj.org/problem?id=1979


#include <iostream>
#include <string.h>
using namespace std;
char s[25][25];
bool flag[25][25];
long long sum;
int n,m;
int xx[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
void dfs(int x,int y)
{
    for(int i=0;i<4;i++)
    {
        int x1=x+xx[i][0];
        int y1=y+xx[i][1];
        if(x1>=0&&x1<m&&y1>=0&&y1<n&&s[x1][y1]=='.'&&!flag[x1][y1])
        {
            sum++;
            flag[x1][y1]=1;
            dfs(x1,y1);

        }
    }
}
int main()
{
    while(cin>>n>>m)
    {
        if(n==0&&m==0)
            break;
       // memset(flag,0,sizeof(flag));
        //memset(s,0,sizeof(s));
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                flag[i][j]=0;
         sum=0;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            cin>>s[i][j];
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
           {
              if(s[i][j]=='@')
              {
                  flag[i][j]=1;
                  sum++;
                  dfs(i,j);
              }
           }
           cout<<sum<<endl;
    }
    return 0;
}
