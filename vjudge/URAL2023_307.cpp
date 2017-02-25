// URAL2023
//http://acm.timus.ru/problem.aspx?space=2.023&num=2023


#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
string s;
int main()
{
    int T;
    int sum=0;
    int ans=1;
    int flag=1;
    cin>>T;
    while(T--)
    {
        cin>>s;

        if(s[0]=='A'||s[0]=='P'||s[0]=='O'||s[0]=='R')
        {
            flag=1;

            sum+=abs(ans-flag);
            ans=flag;
        }
       else if(s[0]=='B'||s[0]=='M'||s[0]=='S')
        {
            flag=2;
            sum+=abs(ans-flag);
            ans=flag;
        }
       else if(s[0]=='D'||s[0]=='G'||s[0]=='J'||s[0]=='K'||s[0]=='T'||s[0]=='W')
        {
            flag=3;
            sum+=abs(ans-flag);
            ans=flag;
        }
        for(int i=0;i<s.length();i++)
            s.clear();
           // cout<<sum<<endl;
    }
    cout<<sum<<endl;
    return 0;
}
