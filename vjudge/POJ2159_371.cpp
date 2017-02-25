// POJ2159
//http://poj.org/problem?id=2159


#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
string s1,s2;
int a1[150],a2[150];
int main()
{
    while(cin>>s1>>s2)
    {
        int ans=0,k=1;
        for(int i=0; i<s1.length(); i++)
        {
            a1[i]=0;
            a2[i]=0;
        }
        bool flag=0;
        //for(int i=0; i<s2.length(); i++)
           // s2[i]=s2[i]+1-'A';
        for(int i=0; i<s1.length(); i++)
            a1[s1[i]-'A']++;
        for(int i=0; i<s2.length(); i++)
            a2[s2[i]-'A']++;
        sort(a1,a1+30);
        sort(a2,a2+30);
            for(int i=0; i<=30; i++)
            {
                if(a1[i]==a2[i])
                    continue;
                else
                {
                    flag=1;
                    break;
                }
            }
           /* for(int i=0; i<=25; i++)
                {
                    cout<<a1[i]<<" "<<a2[i]<<endl;
                }
                */

            if(flag==1)
                cout<<"NO"<<endl;
            else cout<<"YES"<<endl;
            //  cout<<s2<<endl;
            for(int i=0; i<s1.length(); i++)
                s1.clear();
            for(int i=0; i<s2.length(); i++)
                s2.clear();
    }
    return 0;
}
