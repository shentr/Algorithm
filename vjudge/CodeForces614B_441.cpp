// CodeForces614B
//http://codeforces.com/problemset/problem/614B


#include <iostream>
#include <string.h>
using namespace std;
char s[100005],p[100005];
int main()
{
    int T;
    while(cin>>T)
    {
        bool flag=0;
        long long sum0=0,ans=0;
        while(T--)
        {
            long long len=0,sum1=0;
            bool flag2=0;
            memset(s,0,sizeof(s));
            cin>>s;
            len=strlen(s);
            for(int i=0; i<len; i++)
            {
                if(s[i]=='0'&&len==1)
                {
                    flag=1;
                    break;
                }
                // else if(s[i]=='0')
                //   sum0++;
                else if(s[i]=='1')
                    sum1++;
                else if(s[i]!='0'&&s[i]!='1')
                {
                    flag2=1;
                    break;
                }
            }
            if(flag==1)
                continue;
                //break;
            else if(sum1>1||flag2==1)
            {
                /*for(int i=0; i<len; i++)
                    ans=ans*10+s[i]-'0';*/
                    strcpy(p,s);
            }
            else
            {
                for(int i=0; i<len; i++)
                {
                    if(s[i]=='0')
                        sum0++;
                }
            }
        }
        if(flag==1)
        {
            cout<<0<<endl;
        }
        else
        {
            if(p[0]!=NULL)
            {
                cout<<p;
            }
            else
            {
                cout<<1;
            }
            for(int i=1; i<=sum0; i++)
                cout<<0;
            cout<<endl;
        }
    }

    return 0;
}
