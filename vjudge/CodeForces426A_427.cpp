// CodeForces426A
//http://codeforces.com/problemset/problem/426A


#include <iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n,s;
    int a[105];
   while(cin>>n>>s)
   {
       int flag=1,sum=0;
       for(int i=0;i<n;i++)
        cin>>a[i];
       sort(a,a+n);
       for(int i=0;i<n-1;i++)
       {
           sum+=a[i];
           if(sum>s)
            {
                flag=0;
            break;
            }
       }
       if(flag==1)
        cout<<"YES"<<endl;
       else if(flag==0)
        cout<<"NO"<<endl;
      //  cout<<sum<<endl;
   }
}
