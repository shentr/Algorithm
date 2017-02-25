// CodeForces420A
//http://codeforces.com/problemset/problem/420A


#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
//queue <char>q,p;
char s[100005];
int main()
{

    while(cin>>s)
    {
        int len=0;
        bool flag=0;
        len=strlen(s);
        for(int i=0;i<len;i++)
        {
            if(s[i]!='W'&&s[i]!='T'&&s[i]!='Y'&&s[i]!='I'&&s[i]!='U'&&s[i]!='O'&&s[i]!='A'&&s[i]!='H'&&s[i]!='X'&&s[i]!='V'&&s[i]!='M')
            {
                printf("NO\n");
                //flag=0;
               return 0;
                //break;
            }
        }
               for(int i=0;i<(len+1)/2;i++)
                {
                    if(s[i]!=s[len-i-1])
                     flag=1;
                }

         if(flag==1)
            printf("NO\n");
        else// cout<<""<<endl;
            printf("YES\n");

    }
    return 0;
}
