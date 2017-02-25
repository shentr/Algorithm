// FZU1075
//http://acm.fzu.edu.cn/problem.php?pid=1075


#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

bool isprime[65539];

void prime()
{
    memset(isprime,true,sizeof(isprime));
    for(long long i=2;i<65539;i++)
    {
        if(isprime[i])
        {
            for(long long j=i*i;j<65539;j+=i)
            {
                isprime[j]=false;
            }
        }
    }
}

int main()
{
    prime();
    //for(int i=2;i<6553;i++)
    //    cout<<isprime[i];
    int t,n;
    int yue[65539];
    cin>>t;
    while(t--)
    {
        int cnt=0;
        cin>>n;
        for(int i=2;i<=n;i++)
        {
            if(isprime[i])
            {
                while(n%i==0)
                {
                    yue[cnt++]=i;
                    n/=i;
                }
            }
        }
        printf("%d",yue[0]);
        for(int i=1;i<cnt;i++)
            printf("*%d",yue[i]);
        printf("\n");
    }
}
