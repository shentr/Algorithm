// POJ2240
//http://poj.org/problem?id=2240


#include <iostream>
#include <map>
using namespace std;
string str[35],s1,s2;
map<string, int> mapp;
int T,m,n;
double rate;
const int INF=1e9;
const int maxn=1005;
double dis[105][105];
double dis2[105][105];
void init()
{
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
        {
            if(i==j)
            {
                dis[i][j]=1;
                dis2[i][j]=1;
            }
            else
            {
                dis[i][j]=0;
                dis2[i][j]=0;
            }
        }
}
int main()
{
    int ans=1;
    while(cin>>n)
    {
        if(n==0)
            break;
        init();
        for(int i=1; i<=n; i++)
        {
            cin>>str[i];
            mapp[str[i]]=i;
        }
//        for(int i=1;i<=T;i++)
//            cout<<mapp[str[i]]<<" ";
//        cout<<endl;
        cin>>m;
        for(int i=1; i<=m; i++)
        {
            cin>>s1>>rate>>s2;
            dis[mapp[s1]][mapp[s2]]=rate;
            dis2[mapp[s1]][mapp[s2]]=rate;
        }
        for(int k=1; k<=n; k++)
            for(int i=1; i<=n; i++)
                for(int j=1; j<=n; j++)
                {
                    dis2[i][j]=max(dis2[i][j],dis2[i][k]*dis2[k][j]);
                }
        bool flag=0;
        for(int i=1; i<=n; i++)
        {
            if(dis2[i][i]>dis[i][i])
            {
                flag=1;
                break;
            }
        }
//            for(int i=1; i<=m; i++)
//            {
//                for(int j=1; j<=m; j++)
//                cout<<dis2[i][j]<<" ";
//                cout<<endl;
//            }
        cout<<"Case "<<ans++<<": ";
        if(flag==1)
            cout<<"Yes"<<endl;
        else cout<<"No"<<endl;

    }
    return 0;
}
