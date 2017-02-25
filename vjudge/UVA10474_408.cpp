// UVA10474
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=10474


#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
int a[10005],hashs[10005];
int main()
{
    int x,n,q;
    int cases=1;
    while(cin>>n>>q)
    {
        if(n==0&&q==0)
            break;
        memset(a,-1,sizeof(a));
        memset(hashs,-1,sizeof(hashs));
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        sort(a,a+n);
        hashs[a[0]]=1;
        for(int i=1;i<n;i++)
        {
            if(a[i]!=a[i-1])
            {
                hashs[a[i]]=i+1;
            }
        }
         cout<<"CASE# "<<cases++<<":"<<endl;
        for(int i=1;i<=q;i++)
        {
            cin>>x;
            if(hashs[x]!=-1)
            {
                cout<<x<<" found at "<<hashs[x]<<endl;
            }
            else
            {
                cout<<x<<" not found"<<endl;
            }
        }
    }
    return 0;
}
