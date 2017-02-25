// HDU1299
//http://acm.hdu.edu.cn/showproblem.php?pid=1299


#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
long long cnt;
long long num[70000],fac[70000];
long long n,t,sum;
void  fenjie(long long n)
{
    cnt=0;
    memset(num,0,sizeof(num));
    for(long long i=2; i*i<=n; i++)
        if(n%i==0)
        {
            fac[cnt]=i;
            while(n%i==0)
            {
                num[cnt]++;
                n/=i;
            }
            cnt++;
        }
    if(n>1)
    {
        fac[cnt]=n;
        num[cnt++]=1;
    }
}
int main()
{

    cin>>t;
    for(long long j=1; j<=t; j++)
    {
        cin>>n;
        sum=1;
        fenjie(n);
        for(long long i=0; i<cnt; i++)
            sum*=(2*num[i]+1);
        printf("Scenario #%d:\n",j);
        cout<<(sum+1)/2<<endl<<endl;
    }
    return 0;
}
