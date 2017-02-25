// CodeForces424A
//http://codeforces.com/problemset/problem/424A


#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
char s[205];
int main()
{
    int n,x1,x2,t1,t2;
    while(cin>>n)
    {
        int sum=0,t1=0,t2=0,x1=0,x2=0;
        memset(s,0,sizeof(s));
        for(int i=0; i<n; i++)
        {
            cin>>s[i];
            if(s[i]=='X')
                x1++;
            else if(s[i]=='x')
                x2++;

        }
        t1=x1-n/2;
        t2=x2-n/2;
       // cout<<x1<<" "<<x2<<endl;
        if(t1>t2)
        {
            for(int i=0; i<n; i++)
            {
                if(s[i]=='X')
                {
                    s[i]=s[i]+32;
                    sum++;
                }
                if(t1==sum)
                    break;
            }
        }
        else if(t1<t2)
        {
            for(int i=0; i<n; i++)
            {
                if(s[i]=='x')
                {
                    s[i]=s[i]-32;
                    sum++;
                }
                if(fabs(x1-n/2)==sum)
                    break;
            }
        }
        else if(t1==t2)
        {
            sum=0;
        }
        cout<<sum<<endl;
        for(int i=0;i<n;i++)
            cout<<s[i];
        cout<<endl;
    }
    return 0;
}
