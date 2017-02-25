// CodeForces733A
//http://codeforces.com/problemset/problem/733A


#include <iostream>
#include <string.h>
using namespace std;
string s;
int main()
{
    int flag[105];
    while(cin>>s)
    {
        memset(flag,0,sizeof(flag));
        int k=0;
        flag[k]=-1;
        for(int i=0; i<s.length(); i++)
        {
            if(s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U'||s[i]=='Y')
                flag[++k]=i;
        }
        flag[++k]=s.length();
        int maxn=0;
        for(int i=1; i<=k; i++)
        {
            maxn=max(flag[i]-flag[i-1],maxn);
        }
        for(int i=0;i<s.length();i++)
            s.clear();
        cout<<maxn<<endl;
    }
    return 0;
}
