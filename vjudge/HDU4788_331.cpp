// HDU4788
//http://acm.hdu.edu.cn/showproblem.php?pid=4788


#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
string s;
int main()
{
    int T,cases=0;
    cin>>T;
    while(T--)
    {
        cin>>s;
        cout<<"Case #"<<++cases<<": ";
        char c;
        bool flag=0,flag2=0;
        int sum=0;
        for(int i=0; i<s.length(); i++)
        {
            if(s[i]!='B')
            {
                if(flag)
                    continue;
                c=s[i];
                //if(s[i-1])
            }
            else if(s[i]=='B')
            {
                flag=1;
                if(c=='[')
                {
                    flag2=1;
                    cout<<"0.00%"<<endl;
                    break;
                }
                else if(c=='K')
                    sum=1;
                else if(c=='M')
                    sum=2;
                else if(c=='G')
                    sum=3;
                else if(c=='T')
                    sum=4;
                else if(c=='P')
                    sum=5;
                else if(c=='E')
                    sum=6;
                else if(c=='Z')
                    sum=7;
                else if(c=='Y')
                    sum=8;
            }

        }
if(flag2)
    continue;
        double ans=1.0;
        double mm=1000.0*1.0/1024.0;
        while(sum--)
            ans*=mm;
        printf("%.2lf",(1-ans)*100.0);
        //cout<<"%"<<endl;
printf("%%\n");
    }
    return 0;
}
