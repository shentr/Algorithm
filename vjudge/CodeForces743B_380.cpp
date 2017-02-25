// CodeForces743B
//http://codeforces.com/problemset/problem/743B


#include<iostream>
using namespace std;
int main()
{

	long long n,k,sum=1,a,b;
	//while(true)
	{
		sum=1;
		cin>>n>>k;
		while(k%2==0)
		{
			sum++;
			k/=2;
		}
		cout<<sum<<endl;
	}
}
