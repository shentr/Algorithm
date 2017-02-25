// POJ1789
//http://poj.org/problem?id=1789


#include <iostream>
#include <string.h>
using namespace std;
int t;
const int INF=0x3f3f3f3f;
const int maxn=2005;
bool vis[maxn];
int lowc[maxn];
int g[maxn][maxn];
char s[maxn][7];
int prim(int cost[][maxn],int n)
{
    int ans=0;
    memset(vis,false,sizeof(vis));
    vis[0]=true;
    for(int i=1;i<n;i++)
        lowc[i]=cost[0][i];
    for(int i=1;i<n;i++)
    {
        int minc=INF;
        int p=-1;
        for(int j=0;j<n;j++)
            if(!vis[j]&&minc>lowc[j])
        {
            minc=lowc[j];
            p=j;
        }
        ans+=minc;
        vis[p]=true;
        for(int j=0;j<n;j++)
            if(!vis[j]&&lowc[j]>cost[p][j])
            lowc[j]=cost[p][j];
    }
    return ans;
}
void init()
{
    memset(s,0,sizeof(s));
    memset(g,0,sizeof(g));
}
int main()
{
    while(cin>>t)
    {
        init();
        if(t==0)
            break;
        for(int i=0; i<t; i++)
        {
            cin>>s[i];
        }
        for(int i=0; i<t; i++)
            for(int j=i+1; j<t; j++)
                for(int k=0; k<7; k++)
                {
                    if(s[i][k]!=s[j][k])
                    {
                        g[i][j]++;
                        g[j][i]++;
                    }
                }
            int sum=prim(g,t);
            cout<<"The highest possible quality is 1/";
            cout<<sum<<"."<<endl;
    }
    return 0;
}
