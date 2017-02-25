// UVALive7270
//https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=7270


#include <iostream>
#include <string.h>
using namespace std;
char s[10005];
int a[10005];
const int INF=0x3f3f3f3f;
int main()
{
    int n;
    while(cin>>n)
    {
        memset(a,0,sizeof(a));
        memset(s,0,sizeof(s));
        bool flag=0;
        int sum=0;
        if(n==0)
        {
            cout<<0<<endl;
            continue;
        }
//        for(int i=1;i<=n;i++)
//            a[i]=INF;
//            a[0]=-2;
        for(int i=1;i<=n;i++)
        {
            cin>>s[i];
            if(s[i]!='S')
                cin>>a[i];
                else a[i]=-1;
        }
        long long ans=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]==-1)
            {
                sum++;
                if(ans)
                {
                    sum++;
                    ans=0;
                }
            }
           else if(a[i]<=a[i-1])
               {
                   sum++;
                   ans+=a[i];
                   //flag=0;
               }
               else ans+=a[i];

        }
        if(ans)
            sum++;
         cout<<sum<<endl;
    }
    return 0;
}
