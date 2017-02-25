// POJ3069
//http://poj.org/problem?id=3069


#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int main()
{
    int a[1005],b[1005];
    int n,s,r;
    while(cin>>r>>n)
    {
        if(r==-1&&n==-1)
            break;
        int sum=1;
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        for(int i=0;i<n;i++)
            cin>>a[i];
        sort(a,a+n);
       int p=0,q=0;
       while(p<n&&q<n)
        {
            if(a[q]-a[p]<=r)
            {
                //b[p]=1;
                s=a[q];
                q++;
            }
           else if(s+r>=a[q])
            {
               q++;
              // b[q]=1;
            }
            else
            {
                sum++;
                p=q;
            }
            //cout<<p<<" "<<q<<endl;
        }
       /* for(int i=0;i<n;i++)
           cout<<a[i]<<" "<<b[i]<<endl;*/
        cout<<sum<<endl;
    }

    return 0;
}
