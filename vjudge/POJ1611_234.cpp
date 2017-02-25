// POJ1611
//http://poj.org/problem?id=1611


#include <iostream>
#include <string.h>
int pre[30005];
using namespace std;
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
    {
        pre[fy]=fx;
    }
}
int main()
{
    int n,m,k,a,b,sum;
    while(cin>>n>>m)
    {
        memset(pre,0,sizeof(pre));
        sum=1;
        if(n==0&&m==0)
            break;
        for(int i=1; i<=n; i++)
            pre[i]=i;
        for(int i=1; i<=m; i++)
        {
            cin>>k;
            cin>>a;
            for(int j=1; j<k; j++)
            {
                cin>>b;
                join(a,b);
            }
        }
        for(int i=1; i<=n; i++)
        {
            if(find(i)==find(0))
                sum++;
        }
        cout<<sum<<endl;
    }

    return 0;
}
