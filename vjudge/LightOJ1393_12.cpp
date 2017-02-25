// LightOJ1393
//http://lightoj.com/login_main.php?url=volume_showproblem.php?problem=1393


#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    int k=1;
    while(t--)
    {
        int n,m,x;
        scanf("%d%d",&n,&m);
        int sum=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                scanf("%d",&x);
                if(((i+j)%2)!=((m+n)%2))
                    sum^=x;
            }
        }
        if(sum==0)
             printf("Case %d: lose\n",k++);
        else 
             printf("Case %d: win\n",k++);
    }
    return 0;
}
