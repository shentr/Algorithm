// LightOJ1315
//http://lightoj.com/login_main.php?url=volume_showproblem.php?problem=1315


#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int N=2005,L=100;
int xx[6]= {-2,-3,-2,-1,-1,1};
int yy[6]= {1,-1,-1,-2,-3,-2};
int sg[N][N];
bool vis[N][N];
//int sta[L],top;
int calc_sg(int x,int y)
{
    bool tag[L];
    if(vis[x][y]) return sg[x][y];
    memset(tag,0,sizeof(tag));
    vis[x][y]=1;///
    for(int i=0; i<6; i++)
    {
        int tx=x+xx[i];
        int ty=y+yy[i];
        if(tx>=0 && ty>=0) tag[calc_sg(tx,ty)]=1; //sta[top++]=calc_sg(tx,ty);
    }
    //vis[x][y]=1;
    for(int i=0; i<L; i++)
    {
        if(tag[i]==0)
        {
            sg[x][y]=i;
            break;
        }
    }
    return sg[x][y];
}
int main()
{
    //freopen("cin.txt","r",stdin);
    int t,ca=1;
    int n;
    cin>>t;
    while(t--)
    {
        scanf("%d",&n);
        int ans=0;
        for(int i=0; i<n; i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            ans=ans^calc_sg(a,b);
        }
        printf("Case %d: ",ca++);
        if(ans) puts("Alice");
        else puts("Bob");
    }
    return 0;
}
