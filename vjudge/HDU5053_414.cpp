// HDU5053
//http://acm.hdu.edu.cn/showproblem.php?pid=5053


#include <iostream>

using namespace std;

int main()
{
    long long t,a,b,sum1,sum2,sum;
    while(cin>>t)
    {
        for(int i=1; i<=t; i++)
        {
            cin>>a>>b;
            sum1=(a*(a-1)/2)*(a*(a-1)/2);
            sum2=(b*(b+1)/2)*(b*(b+1)/2);
            sum=sum2-sum1;
            cout<<"Case #";
            cout<<i;
            cout<<": "<<sum<<endl;
        }
    }
    return 0;
}
