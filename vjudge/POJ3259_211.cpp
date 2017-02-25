// POJ3259
//http://poj.org/problem?id=3259


#include <iostream>
#include <queue>
#include <string.h>
#define INF 99999999
using namespace std;
struct sa
{
    int from,to,w;
} edge[5205];
int dis[5205],first[5205],book[5205],next[5205];
int main()
{
    queue<int>q;
    int t,n,m,w,k;
    while(cin>>t)
    {
        while(t--)
        {
            //bool flag=1;

            while(!q.empty())
                q.pop();

            cin>>n>>m>>w;
            //cout<<n<<m<<w<<endl;
            memset(edge,0,sizeof(edge));
            memset(book,0,sizeof(book));
            memset(next,0,sizeof(next));
            memset(first,-1,sizeof(first));
            for(int i=1; i<=n; i++)
                dis[i]=INF;
            //dis[1]=0;
            //cout<<t<<endl;
            for(int i=1; i<=m; i++)
            {
                cin>>edge[i].from>>edge[i].to>>edge[i].w;
                next[i]=first[edge[i].from];
                first[edge[i].from]=i;
               // cout<<-1<<endl;
            }
            dis[1]=0;//这里改成dis[edge[i].from]=0
            int j=1;
            for(int i=m+1; i<=2*m; i++)
            {
                edge[i].from=edge[j].to;
                edge[i].to=edge[j].from;
                edge[i].w=edge[j].w;
                next[i]=first[edge[i].from];
                first[edge[i].from]=i;
                j++;
            }
            for(int i=2*m+1; i<=2*m+w; i++)
            {
                cin>>edge[i].from>>edge[i].to>>edge[i].w;
                edge[i].w=(-1)*edge[i].w;
                next[i]=first[edge[i].from];
                first[edge[i].from]=i;
            }
            q.push(1);//其实我这里想改成q.push（edge[1].from）；
            //book[edge[1].from]++;
            bool flag=0;
            while(!q.empty())
            {
                k=first[q.front()];
                book[k]++;
                if(book[k]>n)
                  {
                      flag=1;
                      break;
                  }
                while(k!=-1)
                {
                    if(dis[edge[k].to]>dis[edge[k].from]+edge[k].w)
                    {
                        dis[edge[k].to]=dis[edge[k].from]+edge[k].w;
                        q.push(edge[k].to);
                    }
                    k=next[k];

                }
                q.pop();
            }
             //bool flag=0;
           /* for(int i=1; i<=n; i++)
            {

                if(book[i]>n)
                    {
                        flag=1;
                    cout<<book[i]<<endl;
                    }
            }*/
            if(flag==1)
                cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
            //cout<<flag<<endl;
           // for(int i=1;i<=2*m+w;i++)
               // cout<<edge[i].from<<" "<<edge[i].to<<" "<<edge[i].w<<endl;

        }
    }
    return 0;
}
