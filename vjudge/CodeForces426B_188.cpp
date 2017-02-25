// CodeForces426B
//http://codeforces.com/problemset/problem/426B


#include <iostream>
#include <string.h>
using namespace std;
int a[105][105];
int main()
{
    int n,m;
    while(cin>>n>>m)
    {
        int flag=0;
        memset(a,0,sizeof(a));
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
            cin>>a[i][j];
        while(n%2==0)
        {
            for(int i=1;i<=n/2;i++)
                for(int j=1;j<=m;j++)
            {
                if(a[i][j]!=a[n-i+1][j])
                {
                    flag=1;
                    //break;
                }
            }
            if(flag==1)
                //cout<<n<<endl;
                break;
            else n=n/2;
        }
        cout<<n<<endl;
    }
    return 0;
}
