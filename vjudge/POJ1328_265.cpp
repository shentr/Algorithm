// POJ1328
//http://poj.org/problem?id=1328


#include <iostream>
#include <math.h>
#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;
struct sa
{
    double x,y,left,right;
}data[1005];
double cmp(const sa&a,const sa&b)
{
    return a.left>b.left;
}
int main()
{
    sa tmp;
    int n;
    double d;
    int k=1;
    while(cin>>n>>d)
    {
        memset(data,0,sizeof(data));
        int sum=1;
        double maxn=0.0,minn=0.0;
        if(n==0&&d==0)
            break;
        for(int i=0;i<n;i++)
           {
              cin>>data[i].x>>data[i].y;
              data[i].left=data[i].x-sqrt(d*d-data[i].y*data[i].y);
               data[i].right=data[i].x+sqrt(d*d-data[i].y*data[i].y);
               maxn=max(maxn,data[i].y);
               minn=min(minn,data[i].y);
              // cout<<maxn<<endl;
           }
         //  cout<<maxn<<endl;
        sort(data,data+n,cmp);
        tmp=data[0];
        if(maxn>d||d<=0||minn<0)
        {

            printf("Case ");
            printf("%d",k);
            printf(": ");
             cout<<-1<<endl;
            k++;
            //break;
            continue;
        }
        else
            {
               /* for(int i=0;i<n;i++)
                    if(sqrt((tmp.left-data[i].x)*(tmp.left-data[i].x)+data[i].y*data[i].y)>d||sqrt((tmp.right-data[i].x)*(tmp.right-data[i].x)+data[i].y*data[i].y)>d)
                    {
                        sum++;
                        tmp=data[i];
                    }*/
                    for(int i=1;i<n;i++)
                    {
                        if(data[i].right<tmp.left)
                        {
                            sum++;
                            tmp=data[i];
                        }
                        else if(data[i].left>tmp.left)
                        {
                            tmp=data[i];
                        }
                    }
            }
            printf("Case ");
            printf("%d",k);
            printf(": ");
            cout<<sum<<endl;
            k++;
           // for(int i=0;i<n;i++)
             //   cout<<data[i].left<<endl;
    }
    return 0;
}
