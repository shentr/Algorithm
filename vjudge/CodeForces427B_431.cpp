// CodeForces427B
//http://codeforces.com/problemset/problem/427B


#include <iostream>
#include <string.h>
#include <stdio.h>
#include <queue>
using namespace std;
long long a[200005];
int main()
{
    int n,c;
    long long t;
    while(scanf("%d%lld%d",&n,&t,&c)!=EOF)
    {
        queue<int>q;
        while(!q.empty())
            q.pop();
        long long sum=0;
        for(int i=1; i<=n; i++)
            scanf("%lld",&a[i]);
        for(int i=1; i<=n; i++)
        {
            if(a[i]<=t)
                q.push(a[i]);
            if(q.size()==c)
            {
                sum++;
                q.pop();
            }
            if(a[i]>t)
            {
                while(!q.empty())
                {
                    q.pop();
                }
            }
        }
        printf("%lld\n",sum);
    }

    return 0;
}
