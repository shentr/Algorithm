// POJ2253
//http://poj.org/problem?id=2253


#include <iostream>
#include <cmath>
#include <stdio.h>
#include <string.h>
#include <queue>
#define INF 99999999
using namespace std;
struct sa
{
    double x, y;
}point[205];
queue<int>q;
double dis[205];
double s[205][205];
bool book[205];
int main()
{
    int n,t;
    int flag=0;
    while(cin>>n)
    {

        if(n==0)
            break;
            flag++;
        //cout<<-1<<endl;
        while(!q.empty())
            q.pop();
        int k=0;
        double sum=INF*1.0;
        memset(s,0,sizeof(s));
        memset(book,0,sizeof(book));
        for(int i=1;i<=n;i++)
        {
            cin>>point[i].x>>point[i].y;
            for(int j=1;j<i;j++)
            {
                s[i][j]=s[j][i]=sqrt((point[i].x-point[j].x)*(point[i].x-point[j].x)+(point[i].y-point[j].y)*(point[i].y-point[j].y));
            }
        }
      /*  for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            cout<<s[i][j]<<" ";
            cout<<endl;
        }*/
            for(int i=1;i<=n;i++)
                dis[i]=INF;
            dis[1]=0;
            q.push(1);
           // book[1]=1;
            while(!q.empty())
            {
                t=q.front();
                q.pop();
                //book[t]=0;
                for(int i=1;i<=n;i++)
                {
                   if(dis[i]>max(dis[t],s[t][i]))
                   {
                       dis[i]=min(dis[i],max(dis[t],s[t][i]));
                      // if(book[i]==0)
                       {
                           q.push(i);
                          // book[i]=1;
                       }
                   }

                }
            }
           /* for(int i=1;i<=n;i++)
            {
                if(dis[i]!=0)
                sum=min(dis[i],sum);
                //cout<<dis[i]<<endl;
            }*/
            //for(int i=1;i<=n;i++)
             //   cout<<dis[i]<<endl;
           // cout<<sum<<endl;
           printf("Scenario #");
           printf("%d\n",flag);
           printf("Frog Distance = ");
           printf("%.3f\n",dis[2]);
           cout<<endl;

    }
    return 0;
}
