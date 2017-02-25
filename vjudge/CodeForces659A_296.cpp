// CodeForces659A
//http://codeforces.com/problemset/problem/659A


#include <iostream>

using namespace std;

int main()
{
    int n,a,b;
    while(cin>>n>>a>>b)
    {
        int k=0;
        if(b==0)
        {
            k=((a+b)%n==0)?n:(a+b)%n;
        }
        else
        {
            while(b<0)
            {
                //while(b+n<=0)
               
                    b+=n;
                
            }
            k=((a+b)%n==0)?n:(a+b)%n;
        }
        cout<<k<<endl;
    }
    return 0;
}
