// CodeForces659C
//http://codeforces.com/problemset/problem/659C


#include <stdio.h>
#include <string.h>
#include <iostream>
#include <stack>
using namespace std;
const int INF=10000005;
int a[INF],s[INF];
int n,m,b;
int main()
{
    while(cin>>n>>m)
    {
        memset(a,0,sizeof(a));
        memset(s,0,sizeof(s));
        for(int i=1; i<=n; i++)
        {
            cin>>b;
            if(b<INF)
            a[b]=1;
        }
        int len=m,k=0;
        for(int i=1; i<=len,m>0; i++)
        {
            if(!a[i])
            {
                s[++k]=i;
                m-=i;
            }
        }
        if(m<0)
            k--;
       // int sum=q.size();
        cout<<k<<endl;
        if(k==0)
            continue;
//        while(!q.empty())
//        {
//            cout<<q.top()<<" ";
//            q.pop();
//        }
//        getchar();
       for(int i=1;i<k;i++)
        cout<<s[i]<<" ";
        cout<<s[k]<<endl;
    }
    return 0;
}
