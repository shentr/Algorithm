// POJ1321
//http://poj.org/problem?id=1321


#include <iostream>
#include <string.h>
using namespace std;
char s[20][20];
bool vis[20];
int n,k;
long long ans;
void dfs(int x,int sum)
{
    if(sum==k)
        {
            ans++;
            return;
        }
    if(x==n)
        return;
       // cout<<-100<<endl;
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
           // cout<<s[x][i]<<endl;
            //cout<<-300<<endl;
            if(s[x][i]=='#')
            {
               // cout<<-200<<endl;
                vis[i]=1;
                dfs(x+1,sum+1);
                vis[i]=0;
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
        memset(vis,0,sizeof(vis));
        memset(s,0,sizeof(s));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
               // ans++;
                cin>>s[i][j];
            }
        }

        dfs(0,0);
        cout<<ans<<endl;

    }
    return 0;
}
