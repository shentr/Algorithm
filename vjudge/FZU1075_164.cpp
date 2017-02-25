// FZU1075
//http://acm.fzu.edu.cn/problem.php?pid=1075


#include <iostream>
#define N 70000
#include <string.h>
using namespace std;
bool prime[N];
long long p[N];
int s=0;
int cnt;
int fac[N],num[N];

void isprime()
{
    memset(prime,true,sizeof(prime));
    for(long long i=2; i<N; i++)
    {
        if(prime[i])
        {
            p[s++]=i;
            for(long long j=i*i; j<N; j+=i)
                prime[j]=false;
        }
    }

}
void fenjie(int n)
{
    cnt=0;
    memset(num,0,sizeof(num));
    for(long long i=0; p[i]*p[i]<=n&&i<s; i++)
        if(n%p[i]==0)
        {
            fac[cnt]=p[i];
            while(n%p[i]==0)
            {
                num[cnt]++;
                n/=p[i];
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
    int x,k;
    while(cin>>k)
    {
        for(int j=0; j<k; j++)
        {
            cin>>x;
            isprime();
            fenjie(x);
            for(int i=0; i<x; i++)
            {
                if(fac[i]!=0)
                    for(int l=0; l<num[i]; l++)
                    {
                        if(l==num[i]-1)
                            cout<<fac[i];
                        else
                            cout<<fac[i]<<"*";
                    }
                if(num[i+1]!=0)cout<<"*";
            }
            cout<<endl;
        }
    }

    return 0;
}
