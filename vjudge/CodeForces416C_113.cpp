// CodeForces416C
//http://codeforces.com/problemset/problem/416C


#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1e3+5;

struct node
{
    int x,y,cnt;
};

int cmp1(node i,node j)
{
    return i.x<j.x;
}

int cmp2(node i,node j)
{
    return i.y>j.y;
}

int main()
{
    int n;
    bool v[N];
    node c[N],a[N];
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        scanf("%d%d",&c[i].x,&c[i].y);
        c[i].cnt=i;
    }
    int m;
    cin>>m;
    for (int i=1;i<=m;i++)
    {
        scanf("%d",&a[i].x);
        v[i]=0;
    }
    for (int i=1;i<=m;i++)
        a[i].y=i;
    sort(a+1,a+1+m,cmp1);
    sort(c+1,c+1+n,cmp2);
    int s,mm,p[N];
    for (int i=1;i<=n;i++)
    {
    	for (int j=1;j<=m;j++)
    		if (a[j].x>=c[i].x && !v[j])
    		{
    			p[c[i].cnt]=a[j].y;
    			v[j]=1;
    			s+=c[i].y;
    			mm++;
    			break;
    		}
    }
    printf("%d %d\n",mm,s);
    for (int i=1;i<=n;i++)
    {
        if(p[i])
    	printf("%d %d\n",i,p[i]);
    }
}
