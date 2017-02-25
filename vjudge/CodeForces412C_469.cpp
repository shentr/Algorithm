// CodeForces412C
//http://codeforces.com/problemset/problem/412C


#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
char a[100100];
char s[100100];
int flag[100100];
int n,len;
int main()
{
    while(cin>>n)
    {
        for(int i=0; i<100050; i++)
            a[i]='?';
        memset(flag,0,sizeof(flag));
        while(n--)
        {
            //len=0;
            scanf("%s",s);
            len=strlen(s);
            for(int i=0; i<len; i++)
            {
                if(!flag[i]&&a[i]=='?')
                    {
                        a[i]=s[i];
                        //flag[i]=1;
                    }
                else if(!flag[i]&&s[i]!='?'&&a[i]!='?'&&a[i]!=s[i])
                {
                    a[i]='?';
                    flag[i]=1;
                }
                else if(s[i]==a[i]||s[i]=='?')continue;
            }

        }
        for(int i=0; i<len; i++)
        {
            if(flag[i]&&a[i]=='?')
                cout<<'?';
            else if(!flag[i]&&a[i]=='?')
                cout<<'z';
            else cout<<a[i];
        }
       // cout<<a[len-1]<<endl;
    }
    return 0;
}
