// UVA11237
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=11237


#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int p[100005],a[100005];
long long sum[100005];
int main()
{
    int left,right,c,n;
    while(scanf("%d%d",&c,&n)!=EOF)
    {
        memset(p,0,sizeof(p));
        memset(sum,0,sizeof(sum));
        memset(a,-1,sizeof(a));
        if((c==0)&&(n==0))
            break;
        for(int i=1; i<=n; i++)
            cin>>p[i];
        for(int i=1; i<=n; i++)
        {
            sum[i]=p[i]+sum[i-1];
            if(sum[i]%c==0)
            {
                left=1;
                right=i;
                break;
            }
            else if(a[sum[i]%c]==-1)
            {
                a[sum[i]%c]=i;
            }
            else
            {
                left=a[sum[i]%c]+1;
                right=i;
                break;
            }
                   }

            for(int i=left; i<right; i++)
              cout<<i<<"  ";
                printf("%d\n",right);
    }
    return 0;
}
