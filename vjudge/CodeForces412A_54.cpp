// CodeForces412A
//http://codeforces.com/problemset/problem/412A


#include<iostream>
#include<string>
using namespace std;

int main()
{
	int n,k;
	cin>>n>>k;
	string str;
	cin>>str;
	if((k-1)>=(n-k))
	{
		for(int i=k+1;i<=n;i++)
			cout<<"RIGHT"<<endl;
		for(int i=n-1;i>=0;i--)
		{
			cout<<"PRINT "<<str[i]<<endl;
			if(i>0)
				cout<<"LEFT"<<endl;
		}
	}
	else
	{
		for(int i=k-1;i>=1;i--)
			cout<<"LEFT"<<endl;
		for(int i=0;i<n;i++)
		{
			cout<<"PRINT "<<str[i]<<endl;
			if(i<n-1)
				cout<<"RIGHT\n";
		}
	}
}
