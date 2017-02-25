// UESTC1226
//http://acm.uestc.edu.cn/#/problem/show/1226


#include <iostream>

using namespace std;

int main()
{
    int n,t;
   while(cin>>t)
   {
      for(int k=1;k<=t;k++)
       {
           cin>>n;
           cout<<"Case #"<<k<<": ";
           cout<<2*n-1<<endl;
       }
   }
    return 0;
}
