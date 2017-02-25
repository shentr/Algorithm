// CodeForces405D
//http://codeforces.com/problemset/problem/405D


#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=1e6;
int b[N+5];

int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        memset(b,0,sizeof(b));
        int k=0,bb;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&bb);
            b[bb]=1;
            if(b[N-bb+1]==1)
                k++;
        }
        printf("%d\n",n);
        for(int i=1;i<=N;i++)
        {
            if(k>0&&b[i]==0&&b[N-i+1]==0)
            {
                printf("%d %d ",i,N-i+1);
                k--;
            }
            if(b[i]==1&&b[N-i+1]==0)
                printf("%d ", N-i+1);
        }
    }
}
