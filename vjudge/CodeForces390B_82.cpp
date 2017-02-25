// CodeForces390B
//http://codeforces.com/problemset/problem/390B


#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=1e5+5;
long long a[N],b[N];

int main()
{
    int n;
	while(cin>>n)
    {
        for(int i=1;i<=n;i++)
            scanf("%I64d",&a[i]);
        for(int i=1;i<=n;i++)
            scanf("%I64d",&b[i]);
        long long sum=0,count;
        for(int i=1;i<=n;i++)
        {
            if(2*a[i]>=b[i]&&b[i]!=1)
            {
                count=b[i]/2;
                sum+=count*(b[i]-count);
            }
            else
                sum--;
        }
        cout<<sum<<endl;
        }
        return 0;
}
