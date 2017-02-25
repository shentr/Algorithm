// CodeForces427A
//http://codeforces.com/problemset/problem/427A


#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    int n;
    while(cin>>n)
    {
        int count=0;
        int a,p=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a;
            if(a>0)
            {
                p+=a;
            }
            else if(a==-1)
            {
                if(p>0)
                    p--;
                else if(p==0)
                    count++;
            }
        }
        cout<<count<<endl;
    }
}
