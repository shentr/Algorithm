// POJ3176
//http://poj.org/problem?id=3176


#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int main()
{
    int n;
    int data[360][360],a[360][360];
    while(cin>>n)
    {
        long long sum=0;
        memset(a,0,sizeof(a));
        memset(data,0,sizeof(data));
      for(int i=1;i<=n;i++)
            for(int j=1;j<=i;j++)
            cin>>data[i][j];
          /*  for(int i=1;i<=n;i++)
              {
                  for(int j=1;j<=i;j++)
                    cout<<data[i][j];
                cout<<endl;
              }*/
      for(int i=1;i<=n;i++)
            for(int j=1;j<=i;j++)
            {
                a[i][j]=data[i][j]+max(a[i-1][j-1],a[i-1][j]);
            }
            for(int i=1;i<=n;i++)
            for(int j=1;j<=i;j++)
            {
                if(sum<a[i][j])
                    sum=a[i][j];
            }
            cout<<sum<<endl;

    }

    return 0;
}
