// CodeForces426B
//http://codeforces.com/problemset/problem/426B


#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int n,m;
	while(cin>>n>>m)
	{
	    int a[105][105];
	    for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                cin>>a[i][j];
        while(1)
        {
            if(n%2)
                break;
            int flag=0;
            for(int i=0;i<n/2;i++)
                for(int j=0;j<m;j++)
                    if(a[i][j]!=a[n-i-1][j])
                        flag=1;
            if(flag)
                break;
            n/= 2;
        }
        cout<<n<<endl;
    }
	return 0;
}
