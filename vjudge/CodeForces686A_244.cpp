// CodeForces686A
//http://codeforces.com/problemset/problem/686A


#include <iostream>

using namespace std;
int n;
long long x,shu;
char str;
int main()
{
   while(cin>>n>>x)
   {
       long long sum=x;
       int ans=0;
       for(int i=1;i<=n;i++)
       {
           cin>>str>>shu;
           if(str=='+')
            sum+=shu;
           else if(str=='-')
           {
               if(sum>=shu)
               {
                   sum-=shu;
               }
                else   ans++;
           }

       }
       cout<<sum<<" "<<ans<<endl;
   }
    return 0;
}
