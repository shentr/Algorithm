// POJ1611
//http://poj.org/problem?id=1611


#include <iostream>
#define max 30005
using namespace std;
int pre[max],p[max];
int n,m,s;
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
        pre[fx]=fy;
}
int main()
{
    while(cin>>n>>m)
    {
        int sum=0;
        if(n==0&&m==0)
            break;
        for(int i=0; i<n; i++)
            pre[i]=i;
        for(int i=0; i<m; i++)
        {
            cin>>s;
            for(int i=0; i<s; i++)
                cin>>p[i];

            for(int i=1; i<s; i++)
                join(p[0],p[i]);
                }

        for(int i=0; i<n; i++)
        {
            if(find(0)==find(i))
            {
                sum++;
            }
        }
        cout<<sum<<endl;

    }

return 0;
}
