// HDU3018
//http://acm.hdu.edu.cn/showproblem.php?pid=3018


#include<stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
int pre[100005],s[100005],flag[100005];
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
        pre[fx]=fy;
}
int main()
{
    int n,m,a,b;
    while(cin>>n>>m)
    {
        memset(flag,0,sizeof(flag));
        memset(s,0,sizeof(s));
        memset(pre,0,sizeof(pre));
        int sum=0;
        for(int i=1;i<=n;i++)
            pre[i]=i;
        for(int i=1;i<=m;i++)
            {
                cin>>a>>b;
                join(a,b);
                flag[a]++;
                flag[b]++;
            }
        for(int i=1;i<=n;i++)
        {
            if(flag[i]%2==1)
            {
                s[find(i)]++;
                sum++;
            }
        }
        sum/=2;
        for(int i=1;i<=n;i++)
        {
            if(find(i)==i)
              {
                  if(flag[i]&&s[i]==0)
                sum++;
              }

        }
        cout<<sum<<endl;

    }
    return 0;
}
