// CodeForces401C
//http://codeforces.com/problemset/problem/401C


#include<iostream>
using namespace std;

int main()
{
    long long n,m;
    while(cin>>n>>m)
    {
        if(n>m+1||m>2*n+2)
        {
            cout<<-1<<endl;
            continue;
        }
        if(n==m+1)
        {
            for(int i=1;i<=n+m;i++)
            {
                if(i%2==1)
                    cout<<0;
                else
                    cout<<1;
            }
        }
        else
        {
            int duo=m-n;
            int d=0;
            for(int i=1;i<=n+m;i++)
            {
                if(duo>0)
                {
                    if(i%3==1)
                    {
                        cout<<1;
                    }
                    else if(i%3==2)
                    {
                        cout<<1;
                        duo--;
                    }
                    else
                        cout<<0;
                }
                else
                {
                    if(d==0)
                    {
                        cout<<0;
                        d=1;
                    }
                    else
                    {
                        cout<<1;
                        d=0;
                    }
                }
            }
        }
        cout<<endl;
    }
}
