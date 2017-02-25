// CodeForces402C
//http://codeforces.com/problemset/problem/402C


#include<iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,p,flag=0;
        cin>>n>>p;
        int k=n*2+p;
        for(int i=1;i<=n;i++)
        {
            if(flag==1)
                break;
            for(int j=i+1;j<=n;j++)
            {
                k--;
                cout<<i<<" "<<j<<endl;
                if(k==0)
                {
                    flag=1;
                    break;
                }
            }
        }
    }
}
