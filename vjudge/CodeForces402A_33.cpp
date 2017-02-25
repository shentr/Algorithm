// CodeForces402A
//http://codeforces.com/problemset/problem/402A


#include<iostream>
using namespace std;

int main()
{
    int k,a,b,v,bb,ans,d;
    while(cin>>k>>a>>b>>v)
    {
        d=k*v;
        bb=b/(k-1);
        if(bb*d>=a)
        {
            if(a%d==0)
                cout<<a/d<<endl;
            else
                cout<<a/d+1<<endl;;
        }
        else
        {
            ans=a-bb*d;
            if(b-bb*(k-1)>0)
            {
                ans-=(b-bb*(k-1)+1)*v;
                bb++;
            }
            if(ans>0)
            {
                if(ans%v==0)
                {
                    bb+=ans/v;
                }
                else
                {
                    bb+=ans/v;
                    bb++;
                }
            }
            cout<<bb<<endl;
        }
    }
}


