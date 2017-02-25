// CodeForces401A
//http://codeforces.com/problemset/problem/401A


#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
int a[1005];
double t;
int main()
{
    int n,x;
   while(cin>>n>>x)
   {
       int sum=0;
       t=0.0;
       memset(a,0,sizeof(a));
       for(int i=1;i<=n;i++)
        {
            cin>>a[i];
       sum+=a[i];
       }
       if(sum<0)
            sum=sum*(-1);
       if(sum==0)
        cout<<0<<endl;
       // else if(sum<=x)
        //    cout<<1<<endl;
       else
       {
           if((sum-0)%x==0)
            t=(sum-0)/x;
        else t=(sum-0)/x+1;
        cout<<t<<endl;
       }

   }
    return 0;
}
