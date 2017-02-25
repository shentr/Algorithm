// CodeForces412C
//http://codeforces.com/problemset/problem/412C


#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int N=1e5+5;
char ans[N];
char a[N];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%s",a);
        for(int j=0;a[j];j++)
        {
            if(a[j]=='?')
                continue;
            if(!ans[j])
                ans[j] = a[j];
            else if(ans[j]!=a[j])
            {
                ans[j] = '?';
            }
        }
    }
    for(int i=0;a[i];i++)
    {
        if(!ans[i]) ans[i]='a';
    }
    printf("%s\n",ans);
    return 0;
}
