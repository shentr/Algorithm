// HDU5512
//http://acm.hdu.edu.cn/showproblem.php?pid=5512


#include <iostream>

using namespace std;
int gcd(int x,int y)
{
    if(x>y)
        swap(x,y);
    int t;
    while(t=x%y)
    {
       x=y;
       y=t;
    }
    return y;
}
int main()
{
    int n,a,b,T;
   cin>>T;
   int cases=1;
   while(T--)
   {
       int sum=0;
       cin>>n>>a>>b;
        sum=gcd(a,b);
        int ans=n/sum;
//       if(a%2==0&&b%2==0)
//       {
//           sum=n/2;
//       }
//       else
//       {
//           sum=n;
//       }
       cout<<"Case #"<<cases++<<": ";
       if(ans%2==0)
        cout<<"Iaka"<<endl;
       else cout<<"Yuwgna"<<endl;
   }
    return 0;
}
