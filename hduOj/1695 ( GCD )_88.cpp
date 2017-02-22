// 1695 ( GCD )
//acm.hdu.edu.cn/showproblem.php?pid=1695


#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include<fstream>
using namespace std;
const int MAXN = 1000000;
bool check[MAXN+10];
int prime[MAXN+10];
int u[MAXN+10];
void Moblus()
{
    memset(check,false,sizeof(check));
    u[1] = 1;
    int tot = 0;
    for(int i = 2; i <= MAXN; i++)
    {
        if( !check[i] )
        {
            prime[tot++] = i;
            u[i] = -1;
        }
        for(int j = 0; j < tot; j++)
        {
            if(i * prime[j] > MAXN) break;
            check[i * prime[j]] = true;
            if( i % prime[j] == 0)
            {
                u[i * prime[j]] = 0;
                break;
            }
            else
            {
                u[i * prime[j]] = -u[i];
            }
        }
    }
}
int main()
{
    Moblus();
    int t;
    cin>>t;
    int a,b,c,d,k;
    for(int kase=1;kase<=t;kase++)
    {
        scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
        if(k==0)
        {
            printf("Case %d: 0\n",kase);
            continue;
        }
        long long ans=0;
        int ma=max(b,d),mi=min(b,d);
        for(int i=k;i<=mi;i+=k)
        {
            ans+=(long long)u[i/k]*((ma/i)*2-(mi/i)+1)*(mi/i)/2;
        }
        printf("Case %d: %I64d\n",kase,ans);
    }
    return 0;
}
