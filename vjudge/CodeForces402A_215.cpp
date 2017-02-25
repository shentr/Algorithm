// CodeForces402A
//http://codeforces.com/problemset/problem/402A


#include <iostream>

using namespace std;

int main()
{
    int b,a,k,v;
    while(cin>>k>>a>>b>>v)
    {
        int sum=0;

        while(a>v)
        {

            if(k-b>1)
            {
               // if((k*v)<=a)
                //    sum=1;
               // else
                {
                    a-=((b+1)*v);
                    b=0;
                    sum++;
                }
            }
            else
            {
                a-=(k*v);
                b=b-(k-1);
                sum++;
            }
        }
        if(a>0)
            cout<<sum+1<<endl;
            else cout<<sum<<endl;

    }
    return 0;
}
