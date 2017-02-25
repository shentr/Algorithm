// CodeForces424B
//http://codeforces.com/problemset/problem/424B


#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
const int N=1000000;
int b;

struct Node
{
	int x,y,num;
}a[100010];

bool cmp(const Node &i,const Node &j)
{
	return (i.x*i.x+i.y*i.y)<(j.x*j.x+j.y*j.y);
}

int main()
{
    int n,k,ans;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].num);
	sort(a+1,a+n+1,cmp);
	while(k<N&&b<=n)
        k+=a[++b].num;
	ans=a[b].x*a[b].x+a[b].y*a[b].y;
	if(b==n+1)
        cout<<-1;
	else
        printf("%.7lf\n",sqrt(ans));
	return 0;
}
