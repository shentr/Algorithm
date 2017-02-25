// POJ2492
//http://poj.org/problem?id=2492


#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int f[500500],sum[500500];
int ff(int x){
    if(f[x]!=x){
        int k=f[x];
        f[x]=ff(f[x]);
        sum[x]=(sum[x]+sum[k])%2;
    }
    return f[x];
}
int main()
{
    int t,flag;
    cin>>t;
    int k=1;
    while(t--){
        int m,n;
        memset(sum,0,sizeof(sum));
        scanf("%d%d",&n,&m);
        flag=0;
        for(int i=0;i<=n+6; i++)
        f[i]=i;
        while(m--){
            int x1,x2;
            scanf("%d%d",&x1,&x2);
            if(flag)continue;
            int f1=ff(x1);
            int f2=ff(x2);
            if(f1==f2&&sum[x1]==sum[x2]){
                flag=1;
            }
            if(f1!=f2){
                f[f2]=f1;
                sum[f2]=(sum[x1]-sum[x2]+1)%2;
            }

        }

        printf("Scenario #%d:\n",k++);
        if(flag==0)
            printf("No suspicious bugs found!\n\n");
        else
            printf("Suspicious bugs found!\n\n");
    }
    return 0;
}