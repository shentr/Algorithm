// CodeForces417C
//http://codeforces.com/problemset/problem/417C


#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int n,k,x;
    while(scanf("%d%d",&n,&k)!=EOF)
    {

        if((n*(n-1)/2)<(n*k))
            printf("-1\n");
        else
            {
                printf("%d\n",n*k);
                for(int i=1;i<=n;i++)
                {
                    int x=0;
                    for(int j=i+1;j<=n*2;j++)
                    {
                        x++;
                       // cout<<i<<" "<<(j%n==0?n:j%n)<<endl;
                       printf("%d",i);
                       printf(" ");
                       printf("%d\n",j%n==0?n:j%n);
                        if(x==k)
                            break;

                    }
                }
            }
    }
    return 0;
}
