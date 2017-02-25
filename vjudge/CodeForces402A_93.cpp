// CodeForces402A
//http://codeforces.com/problemset/problem/402A


#include<iostream>
using namespace std;

int main()
{
    int k,a,b,v;
    while(cin>>k>>a>>b>>v)
    {
        int d;
        if(a%v==0)
            d=a/v;
        else
            d=a/v+1;
        if(d%k==0)
        d-=min(b,(d/k)*(k-1)+d%k);
        else
            d-=min(b,(d/k)*(k-1)+d%k-1);
        cout<<d<<endl;
    }
}
