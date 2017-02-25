// CodeForces22C
//http://codeforces.com/problemset/problem/22C


#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;

int n,m,v;
int main()
{
    while(scanf("%d%d%d",&n,&m,&v)!=-1)
    {
        if (m<n-1 || m>((n*n-3*n+4)/2))
        {
            printf("-1\n");
            continue;
        }
        for(int i=1; i<=n; i++)
        {
            if (i!=v) printf("%d %d\n",i,v);//n-1条与割点相连的边
        }
        m-=n-1;
        int tt=1;//通过tt保证v是割点
        if (v==1) tt=2;
        for(int i=1; i<=n && m>0; i++)
            if(i!=v && i!=tt)
                for(int j=i+1; j<=n &&m>0; j++)
                    if(j!=v && j!=tt)
                    {
                        printf("%d %d\n",i,j);//其它的边
                        m--;
                    }
    }
    return 0;
}