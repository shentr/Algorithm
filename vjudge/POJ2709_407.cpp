// POJ2709
//http://poj.org/problem?id=2709


#include <iostream>
#include <algorithm>
using namespace std;
int cmp(const int x,const int y)
{
    return x>y;
}
int n,k;
int a[1005],b[1005];
int main()
{
    while(cin>>n)
    {
        if(n==0)
            break;
        int maxn=0;
        for(int i=1; i<=n; i++)
        {
            cin>>a[i];
            maxn=max(maxn,a[i]);
        }
        cin>>k;
       int sum=(maxn%50==0)?(maxn/50):(maxn/50+1);
        for(int i=1; i<=n; i++)
        {
            b[i]=sum*50-a[i];
        }
        int t=0;
        while(t<k)
        {
            sort(b+1,b+n+1,cmp);
            if(b[3]==0)
            {
                for(int i=1; i<=n; i++)
                {
                    b[i]+=50;
                }
                sum++;
            }
            else
            {
                b[1]--;
                b[2]--;
                b[3]--;
                t++;
                sort(b+1,b+n+1,cmp);
            }
        }
        //cout<<t<<" "<<k<<endl;
        cout<<sum<<endl;
    }
    return 0;
}
