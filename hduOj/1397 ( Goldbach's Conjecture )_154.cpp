// 1397 ( Goldbach's Conjecture )
//acm.hdu.edu.cn/showproblem.php?pid=1397


#include<iostream>
#include<cstring>
using namespace std;
const int N=32768+5;
bool prime[N];

void is_prime()
{
    memset(prime,0,sizeof(prime));
    for(int i=2;i*i<N;i++)
    {
        if(!prime[i])
        {
            for(int j=i+i;j<N;j+=i)
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
        int count=0;
        for(int i=2;i<=n/2;i++)
        {
            if(!prime[i]&&!prime[n-i])
                count++;
        }
        cout<<count<<endl;
    }
}
