// CodeForces401C
//http://codeforces.com/problemset/problem/401C


#include <iostream>

using namespace std;

int main()
{
    int n,m;
    while(cin>>n>>m)
    {
        if(n==1&&m==0)
            cout<<0<<endl;
        else if((n-m>1)||(m>(2*n+2)))
            cout<<-1<<endl;

        else
        {
            while(n&&m)
            {
                if(2*n<m)
                {
                    cout<<11;
                    m=m-2;
                    cout<<0;
                    n--;
                }
                else if(n-m==1)
                {
                    cout<<0;
                    n--;
                }
                else
                {
                    cout<<1;
                    m--;
                    cout<<0;
                    n--;
                }
            }
            if(n==1)
                cout<<0<<endl;
            else if(m==1)
                cout<<1<<endl;
            else if(m==2)
                cout<<11<<endl;
            else cout<<endl;
        }
    }


    return 0;
}
