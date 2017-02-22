// 1333 ( Smith Numbers )
//acm.hdu.edu.cn/showproblem.php?pid=1333


#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
bool prime[40000];

void is_prime()
{
    memset(prime,0,sizeof(prime));
    for(int i=2;i<4e4;i++)
    {
        if(!prime[i])
        {
            for(int j=i+i;j<4e4;j+=i)
                prime[j]=1;
        }
    }
}

int main()
{
    is_prime();
    int n;
    while(cin>>n&&n)
    {
        for(int i=n+1;i<1e9;i++)
        {
            int sum=0,nn=i;
            while(nn)
            {
                sum+=nn%10;
                nn/=10;
            }
            int sum1=0,ii=i;
            for(int j=2;j*j<=ii;j++)
            {
                if(!prime[j])
                {
                    if(ii%j==0)
                    {
                        if(j==i)
                            break;
                        int nn=j;
                        while(nn)
                        {
                            sum1+=nn%10;
                            nn/=10;
                        }
                        ii/=j;
                        j--;
                    }
                }
            }
            if(ii==i)
                continue;
            while(ii)
            {
                sum1+=ii%10;
                ii/=10;
            }
            if(sum==sum1)
            {
                cout<<i<<endl;
                break;
            }
        }
    }
}
