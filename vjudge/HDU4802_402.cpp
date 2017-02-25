// HDU4802
//http://acm.hdu.edu.cn/showproblem.php?pid=4802


#include <iostream>
#include <map>
#include <stdio.h>
using namespace std;
map<string,double>mp;
void init()
{
    mp.insert(pair<string,double>("A",4.0));
    mp.insert(pair<string,double>("A-",3.7));
    mp.insert(pair<string,double>("B+",3.3));
    mp.insert(pair<string,double>("B",3.0));
    mp.insert(pair<string,double>("B-",2.7));
    mp.insert(pair<string,double>("C+",2.3));
    mp.insert(pair<string,double>("C",2.0));
    mp.insert(pair<string,double>("C-",1.7));
    mp.insert(pair<string,double>("D",1.3));
    mp.insert(pair<string,double>("D-",1.0));
    mp.insert(pair<string,double>("F",0));
}
int main()
{
    int n;
    string s;
   while(cin>>n)
   {

       double ans=0;
       int c=0,chu=0;
       init();
       for(int i=1;i<=n;i++)
       {
           cin>>c>>s;
           if(s=="P"||s=="N")
           continue;
           ans+=c*mp[s];
           chu+=c;

       }
       if(chu==0)
        puts("0.00");
       else printf("%.2lf\n",ans/chu);
   }
    return 0;
}
