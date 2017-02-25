// POJ3259
//http://poj.org/problem?id=3259


#include <iostream>
#define INF 99999999
using namespace std;
struct sa
{
    int from,to,w;
} edge[5205];
int dis[5205],bak[5205];
int t,n,m,w;
int main()
{
    while(cin>>t)
    {
        while(t--)
        {
            cin>>n>>m>>w;
            for(int i=1; i<=m; i++)
            {
                cin>>edge[i].from>>edge[i].to>>edge[i].w;
            }
            int k=1;
            for(int i=m+1; i<=2*m; i++)
            {
                edge[i].from=edge[k].to;
                edge[i].to=edge[k].from;
                edge[i].w=edge[k].w;
                k++;
            }
            for(int i=2*m+1; i<=2*m+w; i++)
            {
                cin>>edge[i].from>>edge[i].to>>edge[i].w;
                edge[i].w=edge[i].w*(-1);
            }
            for(int i=1; i<=2*m+w; i++)
                dis[i]=INF;
            dis[1]=0;
            for(int j=1; j<=n-1; j++)
            {
                for(int i=1; i<=n; i++)
                {
                    bak[i]=dis[i];
                }
                for(int i=1; i<=2*m+w; i++)
                {
                    if(dis[edge[i].to]>dis[edge[i].from]+edge[i].w)
                        dis[edge[i].to]=dis[edge[i].from]+edge[i].w;
                }
                int check=0;
                for(int i=1; i<=n; i++)
                {
                    if(bak[i]!=dis[i])
                    {
                        check=1;
                        break;
                    }
                }
                if(check==0)
                    break;
            }
            bool flag=0;
            for(int i=1; i<=2*m+w; i++)
                if(dis[edge[i].to]>dis[edge[i].from]+edge[i].w)
                {
                    flag=1;
                    break;
                }
            if(flag==1)
                cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
    return 0;
}
