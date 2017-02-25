// POJ1321
//http://poj.org/problem?id=1321


#include <iostream>
#include <string.h>
using namespace std;
long long ans=0;
char s[10][10];
bool vis[10];
int n,k;
void dfs(int x,int sum)
{
    if(sum==k)
    {
        ans++;
        return;
    }
    if(x>n)
    return;
    for(int i=0; i<n; i++)
    {
        if(!vis[i])
        {
            if(s[x][i]=='#')
            {
                vis[i] = 1;
                dfs(x+1,sum+1);
                vis[i] = 0;
            }
        }
    }
    dfs(x+1,sum);
}
int main()
{
    while(cin>>n>>k)
    {
        ans=0;
        if(n==-1&&k==-1)
            break;
            memset(s,0,sizeof(s));
            memset(vis,0,sizeof(vis));
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                cin>>s[i][j];
            }
        }
        dfs(0,0);
        cout<<ans<<endl;
    }
    return 0;
}
