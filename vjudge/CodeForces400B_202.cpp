// CodeForces400B
//http://codeforces.com/problemset/problem/400B


#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
char s[1005][1005];
int b[1005];
int n,m,q,w;
bool flag;
int sum;
int cmp(int x,int y)
{
    return x<=y;
}
int main()
{
    while(cin>>n>>m)
    {
        memset(s,0,sizeof(s));
        memset(b,0,sizeof(b));
        sum=1;flag=0;
        for(int i=1; i<=n; i++)
        {
          for(int j=1; j<=m; j++)
          {
                cin>>s[i][j];
                if(s[i][j]=='G')
                    q=j;
                else if(s[i][j]=='S')
                    w=j;
           }
            b[i]=w-q;
            if(b[i]<=0)
            {
                flag=1;
                break;
            }
        }
        sort(b+1,b+n+1,cmp);
        if(flag==0)
        {
            for(int i=1; i<n; i++)
            {

                if(b[i]!=b[i+1])
                sum++;
            }
            cout<<sum<<endl;
        }
        if(flag==1)
            cout<<-1<<endl;
    }
    return 0;
}
