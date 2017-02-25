// FZU2146
//http://acm.fzu.edu.cn/problem.php?pid=2146


#include <iostream>
#include <string.h>

using namespace std;
char s[11111];
int main()
{
    int T;
   while(cin>>T)
   {
       int k=0;
       while(T--)
       {
           memset(s,0,sizeof(s));
           bool flag=0;
           cin>>s;
           int len=strlen(s);
//           for(int i=0;i<len-1;i++)
//           {
//               if(s[i]==s[i+1])
//               {
//                   flag=1;
//                   break;
//               }
//           }
           cout<<"Case "<<++k<<": ";
           if(len%2==0)
            cout<<"Even"<<endl;
           else cout<<"Odd"<<endl;
       }
   }
    return 0;
}
