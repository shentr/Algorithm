// CodeForces688B
//http://codeforces.com/problemset/problem/688B


#include <iostream>
#include <string.h>
using namespace std;
string s;
int main()
{
   while(cin>>s)
   {
       ios::sync_with_stdio(false);
       for(int i=0;i<s.length();i++)
        cout<<s[i];
       for(int i=s.length()-1;i>=0;i--)
        cout<<s[i];
       cout<<endl;
   }
    return 0;
}
