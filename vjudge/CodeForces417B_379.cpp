// CodeForces417B
//http://codeforces.com/problemset/problem/417B


#include <iostream>
#include <string.h>
using namespace std;
int s[100005];
int main()
{
    int n,k,x;
    while(cin>>n)
    {
        int f=0;
        memset(s,-1,sizeof(s));
        for(int i=1;i<=n;i++)
        {
            cin>>x>>k;
            if(s[k]==x-1)
                s[k]=x;
            else if(s[k]>=x)
                continue;
            else f=-1;
        }
        if(f==-1)
            cout<<"NO"<<endl;
            else cout<<"YES"<<endl;
    }
    return 0;
}
