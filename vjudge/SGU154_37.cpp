// SGU154
//undefined154


#include<iostream>
#include<cstdio>

using namespace std;

long long f(long long n)
{
    if(n<5)
        return 0;
    else
        return n/5+f(n/5);
}

int main()
{
    long long m;
    while(cin>>m)
    {
        int d=0;
        if(m==0)
            cout<<1<<endl;
        else{
        for(long long n=4*m;n<4*m+100;n++)
        {
            if(f(n)==m)
            {
                cout<<n<<endl;
                d=1;
                break;
            }
        }
        if(d==0)
            cout<<"No solution"<<endl;
        }
    }
    return 0;
}
