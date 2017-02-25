// UVALive7261
//https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=7261


#include <bits/stdc++.h>

using namespace std;

struct D
{
	int x,y,l,h;
}a[200005];

long long c[2000005];

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		int i;
		long long sum=0;
		for(i=1;i<=m;i++)
		{
			scanf("%d%d%d%d",&a[i].x,&a[i].y,&a[i].l,&a[i].h);
			sum+=(long long)a[i].l*(long long)a[i].h;
		}
		sum=(sum+(long long)1)/(long long)2;
		memset(c,0,sizeof(c));
		for(i=1;i<=m;i++)
		{
			c[a[i].x]+=a[i].h;
			c[a[i].x+a[i].l]-=a[i].h;
		}
		long long dx=c[0],ss=0;
		int ans;
		for(i=1;i<=n;i++)
		{
			ss+=dx;
			if(ss>=sum)
			{
				ans=i;
				dx+=c[i];
				while(dx==0&&ans<n)
				{
					ans++;
					dx+=c[ans];
				}
				break;
			}
			dx+=c[i];
		}
		printf("%d\n",ans);
	}
	return 0;
}
