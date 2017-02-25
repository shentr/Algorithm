// POJ2492
//http://poj.org/problem?id=2492


#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
int pre[2000015];
int find(int x)
{
    int r=x;
    while(r!=pre[r])
    {
        r=pre[r];
    }
   int i=x,j;
    while(pre[i]!=r)
    {
        j=pre[i];
        pre[i]=r;
        i=j;
    }
    return r;
}
void join(int x,int y)
{
    int fx=find(x);
    int fy=find(y);
    if(fx!=fy)
    pre[fy]=fx;
}
bool same(int x,int y)
{
    return find(x)==find(y);
}
int main()
{
    int t,n,m,a,b;
    cin>>t;
    {
        //int s=0;
        //while(t--)
        for(int k=1;k<=t;k++)
        {
            //s++;
            memset(pre,0,sizeof(pre));
            printf("Scenario #%d:\n",k);
            bool flag=0;
            cin>>n>>m;
            for(int i=1;i<=2*n;i++)
                pre[i]=i;
            for(int i=1;i<=m;i++)
            {
                cin>>a>>b;
                if(flag==true)
                    continue;
                if(same(a,b))
                {
                    flag=true;
                    continue;
                }
                join(a+n,b);
                join(a,b+n);
            }
           /* if(flag)
                {
                    cout<<"Scenario #"<<k<<":"<<endl;
                    cout<<"Suspicious bugs found!"<<endl;
                    cout<<endl;
                }
                else
                {
                    cout<<"Scenario #"<<k<<":"<<endl;
                    cout<<"No suspicious bugs found!"<<endl;
                    cout<<endl;
                }*/
                if(flag)
            {
                printf("Suspicious bugs found!\n\n");
            }
            else
            {
                printf("No suspicious bugs found!\n\n");
            }
                   //  s++;
        }
    }
    return 0;
}
