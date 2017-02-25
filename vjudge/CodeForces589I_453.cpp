// CodeForces589I
//http://codeforces.com/problemset/problem/589I


#include <iostream>
#include <string.h>
using namespace std;
int num[105];
int main()
{
    int n,k;
    ios::sync_with_stdio(false);
    while(cin>>n>>k)
    {
        memset(num,0,sizeof(num));
        int sum=0;
        int a;
        for(int i=1;i<=n;i++)
        {
            cin>>a;
            num[a]++;
        }
        for(int i=1;i<=n;i++)
        {
            if(num[i]>n/k)
                {
                    sum+=(num[i]-n/k);
                }
        }
        cout<<sum<<endl;
    }
    return 0;
}
