// UVALive6855
//https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=6855


#include <iostream>
#include <string.h>
using namespace std;
int a[10005];
int n;
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>n)
    {
        memset(a,0,sizeof(a));
        for(int i=1; i<=n; i++)
        {
            cin>>a[i];
        }

        int sum=0;
        while(1)
        {
             bool flag=0;
            for(int i=1; i<=n; i++)
            {
                if(i==1&&a[i]<0)
                {
                    a[i]*=-1;
                    a[i+1]-=a[i];
                    a[n]-=a[i];
                    sum++;
                }
                else if(i==n&&a[i]<0)
                {
                    a[i]*=-1;
                    a[1]-=a[i];
                    a[i-1]-=a[i];
                    sum++;
                }
                else if(a[i]<0)
                {
                    a[i]*=-1;
                    a[i-1]-=a[i];
                    a[i+1]-=a[i];
                    sum++;
                }

            }
            for(int i=1; i<=n; i++)
            {
               // cout<<a[i]<<endl;
                if(a[i]<0)
                {
                    flag=1;
                }
            }
            if(!flag)
                break;
        }
        cout<<sum<<endl;
    }
    return 0;
}
