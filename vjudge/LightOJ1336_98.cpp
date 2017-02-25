// LightOJ1336
//http://lightoj.com/login_main.php?url=volume_showproblem.php?problem=1336


#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
typedef long long LL;

int main()
{
	int t;
	scanf("%d",&t);
	int count=1;
	while(t--)
        {
                LL n;
	        scanf("%lld",&n);
		LL num1=(LL)sqrt((double)n);
		LL num2=(LL)sqrt((double)n/2.0);
		printf("Case %d: %lld\n",count++,n-num1-num2);
	}
	return 0;
}
