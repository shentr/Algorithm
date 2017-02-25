// UESTC1226
//http://acm.uestc.edu.cn/#/problem/show/1226


#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int t,n;
	cin>>t;
	for(int kase=1;kase<=t;kase++)
	{
		cin>>n;
		if(n==0)
		{
			printf("Case #%d: 0\n",kase);
			continue;
		}
		printf("Case #%d: %d\n",kase,2*n-1);
	}
	return 0;
}
