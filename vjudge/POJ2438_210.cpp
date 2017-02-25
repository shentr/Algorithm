// POJ2438
//http://poj.org/problem?id=2438


#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
const int maxn=420;
int n,m;
bool mp[maxn][maxn];
int s,T,cnt,ans[maxn];
bool vis[maxn];
void reverse(int l,int r)
{
    while(l<r)
    {
        swap(ans[l],ans[r]);
        l++;
        r--;
    }
}
void expend()
{
    while(1)
    {
        bool flag=0;
        for(int i=1; i<=n; i++)
        {
            if(!vis[i]&&mp[T][i])
            {
                ans[cnt++]=i;
                T=i;
                vis[i]=1;
                flag=1;
                break;
            }
        }
        if(!flag)
            break;
    }
}
void ham(){
    memset(vis,0,sizeof(vis));

    s=1;
    for (T=2;T<=n;T++) if (mp[s][T]) break;
    //任意找两个相邻的节点s和T

    cnt=2;
    ans[0]=s, ans[1]=T;
    vis[s]=1, vis[T]=1;
    while (1) {
        expend();
        //在它们的基础上扩展出一条尽量长的没有重复节点的路径
        reverse(0,cnt-1);
        swap(s,T);
        expend();
        //在它们的基础上扩展出一条尽量长的没有重复节点的路径

        int mid=0;
        if (!mp[s][T]){
        //若s与T不相邻,可以构造出一个回路使新的s和T相邻

            for (int i=1;i<cnt-2;i++){
            // 设路径s到T上有k+2个节点，依次为s,v1,v2…… vk和T.
            // 可以证明存在节点vi,满足vi与T相邻,且vi+1与s相邻
                if (mp[ans[i]][T] && mp[ans[i+1]][s]){
                    mid=i+1;
                    break;
                }
            }
            reverse(mid,cnt-1);
            //把原路径变成s→vi→T→vi+1→s,即形成了一个回路

            T=ans[cnt-1];
        }
        if (cnt==n) break;
        //现在我们有了一个没有重复节点的回路.如果它的长度为N,则汉密尔顿回路就找到了
        //否则,由于整个图是连通的,所以在该回路上,一定存在一点与回路以外的点相邻
        //那么从该点处把回路断开,就变回了一条路径,再按照步骤1的方法尽量扩展路径
        for (int i=1;i<=n;i++){
            if (!vis[i]){
                int j;
                for (j=1;j<cnt-1;j++)
                    if (mp[ans[j]][i]) break;
                if (mp[ans[j]][i]){
                    T=i; mid=j;
                    break;
                }
            }
        }
        s=ans[mid-1];
        reverse(0,mid-1);
        reverse(mid,cnt-1);
        ans[cnt++]=T;
        vis[T]=1;
    }
}
/*void ham()
{
    memset(vis,0,sizeof(vis));
    s=1;
    for(T=2; T<=n; T++)
    {
        if(mp[s][T])
            break;
    }
    cnt=2;
    ans[0]=s;
    ans[1]=T;
    vis[s]=1;
    vis[T]=1;
    while(1)
    {
        expend();
        reverse(0,cnt-1);
        swap(s,T);
        expend();
        int mid=0;
        if(!mp[s][T])
        {
            for(int i=1; i<cnt-2; i++)
            {
                if(mp[ans[i]][T]&&mp[ans[i+1]][s])
                {
                    mid=i+1;
                    break;
                }
            }
            reverse(mid,cnt-1);
            T=ans[cnt-1];
        }
        if(cnt==n)
            break;
        for(int i=1; i<=n; i++)
        {
            if(!vis[i])
            {
                int j;
                for(int j=1; j<cnt-1; j++)
                {
                    if(mp[ans[j]][i])
                        break;
                }
                if(mp[ans[j]][i])
                {
                    T=i;
                    mid=j;
                    break;
                }
            }
        }
        s=ans[mid-1];
        reverse(0,mid-1);
        reverse(mid,cnt-1);
        ans[cnt++]=T;
        vis[T]=1;
    }
}*/
int main()
{
    int u,v;
    while(cin>>n>>m)
    {
        if(n==0&&m==0)
            break;
        n*=2;
        memset(mp,1,sizeof(mp));
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
            {
                if(i==j)
                    mp[i][j]=0;
            }
        for(int i=1; i<=m; i++)
        {
            cin>>u>>v;
            mp[u][v]=0;
            mp[v][u]=0;
        }
        ham();
        cout<<ans[0];
        for(int i=1;i<cnt;i++)
            cout<<" "<<ans[i];
        cout<<endl;
        }
    return 0;
}
