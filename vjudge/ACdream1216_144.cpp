// ACdream1216
//http://acdream.info/problem?pid=1216


#include <iostream>
#define INF -9999999999
#include <string.h>
#include <algorithm>
#include <stdio.h>
using namespace std;
const int maxn=100005;
struct sa
{
    int x,y;
    int p;
};
int cmp2(const sa a,const sa b)
{
    if(a.x==b.x)
        return a.y>b.y;
    else return a.x<b.x;
}
sa a[maxn];
int dp[maxn],path[maxn];
int main()
{
    int n;
    while(cin>>n)
    {
        memset(a,0,sizeof(a));
        memset(dp,0,sizeof(dp));
        memset(path,0,sizeof(path));
        for(int i=1; i<=n; i++)
        {
            cin>>a[i].x>>a[i].y;
            a[i].p=i;
        }
        sort(a+1,a+1+n,cmp2);
        int len=1,pos=1;
       /* dp[1]=a[1].y;
        path[1]=a[1].p;

        for(int i=2; i<=n; i++)
        {
            if(a[i].y>dp[len])
            {
                dp[++len]=a[i].y;
                path[i]=len;
            }
            else
            {
                pos=lower_bound(dp+1,dp+len+1,a[i].y)-dp;
                // if(dp[pos]!=a[i].y)
                {
                    dp[pos]=a[i].y;
                    path[i]=pos;
                }
                // cout<<a[i].p<<endl;
            }
        }*/
        dp[len=1]=a[1].y;
    path[1]=1;
    for(int i=2;i<=n;i++)
    {
        if(a[i].y>dp[len])
        {
            dp[++len]=a[i].y;
            path[i]=len;
          //  printf("len=%d,pos=%d,d=%d\n",len,pos[len],d[len]);
        }
        else
        {
            int tmp=pos=lower_bound(dp+1,dp+len+1,a[i].y)-dp;
            dp[tmp]=a[i].y;
            path[i]=tmp;
          //  printf("tmp=%d,pos=%d,d=%d\n",tmp,pos[tmp],d[tmp]);
        }
    }
        cout<<len<<endl;
        int tmp=len;
        for(int i=n;i>=1;i--)
        {
           // printf("i=%d,pos=%d\n",i,pos[i]);
            if(path[i]==tmp)
            {
                printf("%d",a[i].p);
                if(tmp!=1)printf(" ");
                tmp--;
            }
        }
       /* for(int i=n; i>=1; i--)
        {
            if(path[i]==len)
            {
                cout<<a[i].p;
                if(len!=1)
                    cout<<" ";
                len--;
            }
        }*/
        cout<<endl;
//        for(int i=1;i<=n;i++)
//            cout<<path[i]<<" ";
//        cout<<endl;
//        if(len==1)
//            cout<<path[1]<<endl;
//        else
//        {
//            for(int i=1; i<len; i++)
//                cout<<path[i]<<" ";
//            cout<<path[len]<<endl;
//        }
//        for(int i=1;i<=n;i++)
//            cout<<a[i].x<<" "<<a[i].y<<" "<<path[i]<<endl;


    }
    return 0;
}
