// CodeForces589D
//http://codeforces.com/problemset/problem/589D


#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const int MAX=1005;
int n,sj,si,fj,fi,t[MAX],s[MAX],f[MAX],w[MAX],d[MAX];
int main()
{
    cin>>n;
    for (int i=0; i<n; i++)
    {
        cin>>t[i]>>s[i]>>f[i];
        w[i] = 1;
        if(s[i]> f[i]) w[i]=-1;
        if(s[i]==f[i]) w[i]=0;
        for (int j=0; j<i; j++)
        {
            fj=f[j],fi=f[i],sj=s[j],si=s[i];
            if((t[i]+abs(f[i]-s[i])<t[j]) || (t[j] + abs(f[j] - s[j]) < t[i])) continue;
            if(t[j]>t[i]) si+=w[i]*(t[j]-t[i]);
            else sj+=w[j]*(t[i]-t[j]);
            if(abs(fj-sj)>abs(fi-si))   fj-=w[j]*(abs(fj-sj)-abs(fi-si));
            else fi-=w[i]*(abs(fi-si)-abs(fj-sj));
            if((fj<fi && sj>si)||(fj>fi && sj<si) || fj==fi || sj==si) d[i]++,d[j]++;
        }
    }
    for(int i = 0; i < n; i ++) cout<<d[i]<<" ";
}

/*
10
3 3 2
3 1 3
3 2 3
1 2 3
1 1 3
2 3 1
2 3 2
2 1 2
3 2 3
3 3 1
*/
