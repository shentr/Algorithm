// CodeForces401A
//http://codeforces.com/problemset/problem/401A


#include<iostream>
using namespace std;

int main()
{
    int n,x,a;
    while(cin>>n>>x)
    {
        int sum=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a;
            sum+=a;
        }
        if(sum<0)
            sum=-sum;
        if(sum%x==0)
        cout<<sum/x<<endl;
        else
            cout<<sum/x+1<<endl;
    }
}
