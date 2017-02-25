// CodeForces677A
//http://codeforces.com/problemset/problem/677A


#include <iostream>
#include <string.h>
using namespace std;
int a[1004];
int main()
{
    int n,m;
    while(cin>>n>>m)
    {
        memset(a,0,sizeof(a));
        int sum=0;
        for(int i=0;i<n;i++)
            {
                cin>>a[i];

            }
            for(int i=0;i<n;i++)
            {
                if(a[i]>m)
                    sum+=2;
                else sum+=1;
            }
            cout<<sum<<endl;


    }
    return 0;
}
