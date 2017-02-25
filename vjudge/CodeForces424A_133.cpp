// CodeForces424A
//http://codeforces.com/problemset/problem/424A


#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=210;
char a[maxn];
int f[2];

int main()
{
    int n,ans;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		f[a[i]=='X']++;
	}
	ans=f[f[1]>f[0]]-n/2;
	printf("%d\n",ans);
	for(int i=1;i<=n;i++)
    {
        if(ans&&a[i]!=(f[0]>f[1]?'X':'x'))
		{
			ans--;
			printf("%c",f[0]>f[1]?'X':'x');
		}
		else
        printf("%c",a[i]);
    }
	printf("\n");
	return 0;
}
