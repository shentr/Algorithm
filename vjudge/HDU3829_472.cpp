// HDU3829
//http://acm.hdu.edu.cn/showproblem.php?pid=3829


#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
const int maxn=510;
int cat_cnt,dog_cnt;
int g[maxn][maxn];
int linker[maxn];
bool used [maxn];
string s1,s2;
struct node
{
    string love;
    string hate;
}cat[maxn],dog[maxn];
bool dfs(int u)
{
    for(int v=0;v<dog_cnt;v++)
    {
        if(g[u][v]&&!used[v])
        {
            used[v]=true;
            if(linker[v]==-1||dfs(linker[v]))
            {
                linker[v]=u;
                return true;
            }
        }
    }
    return false;
}
int hungry()
{
    int res=0;
    memset(linker,-1,sizeof(linker));
    for(int u=0;u<cat_cnt;u++)
    {
        memset(used,false,sizeof(used));
        if(dfs(u))
            res++;
    }
    return res;
}
void init()
{
    //s1.clear();
    //s2.clear();
    cat_cnt=0;
    dog_cnt=0;
    for(int i=0;i<maxn;i++)
    {
        cat[i].love.clear();
        dog[i].love.clear();
        cat[i].hate.clear();
        dog[i].hate.clear();
    }
}
int main()
{
    int n,m,p;
    while(cin>>n>>m>>p)
    {
        init();
        memset(g,0,sizeof(g));
        for(int i=1;i<=p;i++)
        {
            s1.clear();
            s2.clear();
            cin>>s1>>s2;
            if(s1[0]=='C')
            {
                cat[cat_cnt].love=s1;
                cat[cat_cnt++].hate=s2;
            }
            else if(s1[0]=='D')
            {
                dog[dog_cnt].love=s1;
                dog[dog_cnt++].hate=s2;
            }
        }
        for(int i=0;i<cat_cnt;i++)
            for(int j=0;j<dog_cnt;j++)
        {
            if(cat[i].hate==dog[j].love||cat[i].love==dog[j].hate)
                g[i][j]=1;
        }
        int ans=hungry();
        cout<<p-ans<<endl;
       // cout<<ans<<endl;

    }

    return 0;
}
