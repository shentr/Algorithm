// CodeForces390A
//http://codeforces.com/problemset/problem/390A


#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
struct p
{
    int x;
    int y;
}a[105000];

int main()
{
    int n;
    bool b[105],c[105];
    while(cin>>n)
    {
        memset(b,0,sizeof(b));
        memset(c,0,sizeof(c));
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d",&a[i].x,&a[i].y);
            b[a[i].x]=1;
            c[a[i].y]=1;
        }
        int cntb=0,cntc=0;
        for(int i=0;i<=100;i++)
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