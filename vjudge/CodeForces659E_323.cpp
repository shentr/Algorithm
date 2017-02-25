// CodeForces659E
//http://codeforces.com/problemset/problem/659E


#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<int>a[N];
int flag;
bool vis[N];
void dfs(int u,int pre)
{
    if(vis[u]){
        flag=0;
        return;
    }
    vis[u]=1;
    for(int i=0;i<a[u].size();i++){
        if(a[u][i]!=pre){
            dfs(a[u][i],u);
        }
    }
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int x,y;
    for(int i=0;i<m;i++){
        scanf("%d%d",&x,&y);
        a[x].push_back(y);
        a[y].push_back(x);

    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            flag=1;
            dfs(i,-1);
            ans+=flag;
        }
    }
    printf("%d\n",ans);
    return 0;
}