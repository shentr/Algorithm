// POJ2492
//http://poj.org/problem?id=2492


#include <iostream>
#include <string.h>
#include <stdio.h>
int pre[2000015];
using namespace std;
int find(int x)
{
    int r=x;
    while(r!=pre[r])
        r=pre[r];
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
    int t,m,n,a,b;
       cin>>t;
        for(int k=1; k<=t; k++)
        {
            bool flag=false;
            memset(pre,0,sizeof(pre));
            printf("Scenario #%d:\n",k);
            cin>>n>>m;
            for(int i=1; i<=2*n; i++)
                pre[i]=i;
                
            for(int i=1; i<=m; i++)
            {
                cin>>a>>b;
                if(flag==true)
                   // break;
                   continue;
                if(same(a,b))
                {
                    flag=true;
                    continue;
                }
                join(a+n,b);
                join(a,b+n);
            }
            if(flag)
            {
                printf("Suspicious bugs found!\n\n");
            }
            else
            {
                printf("No suspicious bugs found!\n\n");
            }

    }
    return 0;
}
