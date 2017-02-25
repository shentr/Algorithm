// CodeForces390A
//http://codeforces.com/problemset/problem/390A


#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
    int n;
    bool b[150],c[150];
    int x,y;
    while(cin>>n)
    {
        memset(b,0,sizeof(b));
        memset(c,0,sizeof(c));
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d",&x,&y);
            b[x]=1;
            c[y]=1;
        }
        int cntb=0,cntc=0;
        for(int i=0;i<=105;i++)
        {
            if(b[i]==1)
                cntb++;
            if(c[i]==1)
                cntc++;
        }
        if(cntb>cntc)
            cout<<cntc<<endl;
        else
            cout<<cntb<<endl;
    }
}
