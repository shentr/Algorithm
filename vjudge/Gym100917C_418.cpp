// Gym100917C
//undefined100917C


#include"bits/stdc++.h"
using namespace std;
const int N=1e5+5;
int hs[N];

void init()
{
    memset(hs,0,sizeof(hs));
    for(long long q=2;q<N;q++)
    {
        long long mi=q*q;
        while((mi-1)/(q-1)<N)
        {
            hs[(mi-1)/(q-1)]++;
            mi*=q;
        }
    }
}

int main()
{
    int n;
    init();
    while(cin>>n)
    {
        long long cnt=0;
        for(int i=1;i<n;i++)
        {
            if(n%i==0)
                cnt+=(hs[n/i]+1);
        }
        cout<<cnt<<endl;
    }
}
