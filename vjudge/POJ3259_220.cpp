// POJ3259
//http://poj.org/problem?id=3259


#include <stdio.h>
#include <queue>
#include <iostream>
#include <string.h>
#define INF 99999999
using namespace std;
struct sa
{
    int w,from,to;
} edge[5205];
int book[5205],first[5205],next[5205],dis[5205];
int n,t,m,w,k;
int main()
{
    while(cin>>t)
    {
        while(t--)
        {
            //cout<<t<<endl;
            queue<int>q;
            while(!q.empty())
                q.pop();
            cin>>n>>m>>w;
            bool flag=0;
            memset(edge,0,sizeof(edge));
            memset(next,0,sizeof(next));
            memset(book,0,sizeof(book));
            memset(first,-1,sizeof(first));
            for(int i=1; i<=n; i++)
                dis[i]=INF;
            dis[1]=0;
            for(int i=1; i<=m; i++)
            {
                cin>>edge[i].from>>edge[i].to>>edge[i].w;
                next[i]=first[edge[i].from];
                first[edge[i].from]=i;
            }
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
                edge[i].w=edge[i].w*(-1);
                next[i]=first[edge[i].from];
                first[edge[i].from]=i;
            }
            q.push(1);
            while(!q.empty())
            {

                //cout<<-2<<endl;
                k=first[q.front()];
                q.pop();
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

            }
            if(flag==1)
                cout<<"YES"<<endl;
            else cout<<"NO"<<endl;

        }
    }
    return 0;
}
