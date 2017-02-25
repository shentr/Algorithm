// CodeForces416A
//http://codeforces.com/problemset/problem/416A


#include<iostream>
#include<cstdio>
using namespace std;
const int N=2e9;

int main()
{
	int n;
	cin>>n;
    int l=-N,r=N,x;
    char s1[100],s2[100];
	for (int i = 1;i <= n;++i)
    {
		scanf("%s%d%s",s1,&x,s2);
		if (s2[0]=='Y')
		{
			if (s1[0]=='>')
			{
				if (s1[1]!='=')
                    x++;
				if (x>l)
                    l=x;
			}
			else if(s1[0]=='<')
			{
				if (s1[1]!='=')
                    x--;
				if (x < r)
                    r=x;
			}
		}
		else
		{
			if (s1[0]=='>')
			{
				if (s1[1]=='=')
                    x--;
				if (x < r)
                    r=x;
			}
			else if (s1[0]=='<')
			{
				if(s1[1]=='=')
                    x++;
				if(x > l)
                    l = x;
			}
		}
		if(l>r)
            break;
	}
	if (l>r)
        printf("Impossible\n");
	else
        printf("%d\n",l);
}
