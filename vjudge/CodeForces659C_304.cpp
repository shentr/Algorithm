// CodeForces659C
//http://codeforces.com/problemset/problem/659C


#include <stdio.h>
#include <string.h>
#include <iostream>
#include <stack>
 #pragma comment(linker, ＂/STACK:102400000,102400000＂)
using namespace std;
const int INF=10000005;
int a[INF];
int n,m,b;
stack<int>q;
int main()
{
    while(cin>>n>>m)
    {
        while(!q.empty())
            q.pop();
        memset(a,0,sizeof(a));
        for(int i=1; i<=n; i++)
        {
            cin>>b;
            if(b<INF)
            a[b]=1;
        }
        int len=m;
        for(int i=1; i<=len,m>0; i++)
        {
            if(!a[i])
            {
                q.push(i);
                m-=i;
            }
        }
        if(m<0)
            q.pop();
        int sum=q.size();
        cout<<sum<<endl;
        while(!q.empty())
        {
            cout<<q.top()<<" ";
            q.pop();
        }
        getchar();
        cout<<endl;
    }
    return 0;
}