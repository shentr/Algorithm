// Gym100917L
//undefined100917L


#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
   long long n;
    while(cin>>n)
    //while(scanf("%lld",&n)!=EOF)
    {
        long long sum=0;
        while(n!=1)
        {
            if(n%2==1)
               {
                   sum+=(n/2+1)*2;
                   n=(n/2+1)*3-1;
               }
               else if(n%2==0)
               {
                   sum+=n;
                   n=n/2;
               }
        }
        cout<<sum<<endl;
        //printf("%lld\n",sum);
    }
    return 0;
}
