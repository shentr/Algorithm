// UVA11827
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=11827


#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

int data[101];

int gcd(int a, int b)
{
	return a%b?gcd(b, a%b):b;
}

int main()
{
	int n,m;
	scanf("%d",&n);
	while (getchar() != '\n');
	while (n --)
    {
		char buf;
		int  count = 0;
		while ((buf = getchar()) != '\n')
			if (buf >= '0' && buf <= '9') 
            {
				ungetc(buf,stdin);
				scanf("%d",&data[count ++]);
			}

		int max = 1,temp;
		for (int i = 0 ; i < count ; ++ i)
		for (int j = 0 ; j < i ; ++ j) {
			temp = gcd(data[i], data[j]);
			if (max < temp)
				max = temp;
		}

		printf("%d\n",max);
	}
	return 0;
}
