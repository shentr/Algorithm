// HDU3018
//http://acm.hdu.edu.cn/showproblem.php?pid=3018


#include <iostream>
#include <string.h>
int pre[100005],flag[100005],s[100005];
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
        pre[fy]=fx;
}
int same(int x,int y)
{
    return find(x)==find(y);
}
int main()
{
    int a,b,n,m;
    while(cin>>n>>m)
    {
        long long sum=0;
        memset(pre,0,sizeof(pre));
        memset(flag,0,sizeof(flag));
        memset(s,0,sizeof(s));
        for(int i=1; i<=n; i++)
            pre[i]=i;
        for(int i=1; i<=m; i++)
        {
            cin>>a>>b;
            // data[a][b]=1;
            join(a,b);
            flag[a]++;
            flag[b]++;
        }
        for(int i=1; i<=n; i++)
        {
            if(flag[i]%2==1)
            {
                s[find(i)]++;
                sum++;
            }
        }
        sum/=2;
        for(int i=1; i<=n; i++)
        {
            if(find(i)==i)
            {
                if(flag[i]&&s[i]==0)
                    sum++;
            }
        }
        //for(int i=1;i<=n;i++)
           // cout<<flag[i]<<" ";
        cout<<sum<<endl;
        /*for(int i=1; i<=n; i++)
        {
            b[pre[i]]=1;
        }
        for(int i=1; i<=n; i++)
        {
            if(b[i]==1)
            {
                v[n2]=pre[i];
                n2++;
            }
        }
        for(int i=1; i<=n2; i++)
        {
            int sum2=0;
            for(int j=1; j<=n; j++)
            {
                if(pre[j]==v[i])
                {
                    if(flag[i]%2==1)
                    {
                        sum2+=1;
                    }
                    else if(!sum2&&)
                    {

                    }
                }
            }
        }*/
    }
    return 0;
}
