// HDU5251
//http://acm.hdu.edu.cn/showproblem.php?pid=5251


#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<cmath>
#include<iostream>
using namespace std;
typedef long long LL;
const double eps = 1e-10;
const int maxn = 4e3+10;
const double inf = 1e17;

int dcmp(double x)
{
    if(fabs(x)<eps) return 0;
    if(x>0) return 1;
    return -1;
}

struct point
{
    double x,y;
    bool operator <(const struct point &tmp)const
    {
        if(dcmp(x-tmp.x)==0) return dcmp(y-tmp.y)<0;
        return dcmp(x-tmp.x)<0;
    }
    bool operator == (const struct point &tmp)const
    {
        return dcmp(x-tmp.x)==0&&dcmp(y-tmp.y)==0;
    }
} p[maxn],st[maxn];

double Cross(point a,point b,point c)
{
    return (c.x-a.x)*(b.y-a.y) - (b.x-a.x)*(c.y-a.y);
}

double dot(point a,point b,point c) //点积
{
    double s1=b.x-a.x;
    double t1=b.y-a.y;
    double s2=c.x-a.x;
    double t2=c.y-a.y;
    return s1*s2+t1*t2;
}

int ConvexHull(point *p,int n,point *st)
{
    sort(p,p+n);
    n=unique(p,p+n)-p;
    int m=0;
    for(int i=0; i<n; i++)
    {
        while(m>1&&Cross(st[m-2],p[i],st[m-1])<=0) m--;
        st[m++]=p[i];
    }
    int k=m;
    for(int i=n-2; i>=0; i--)
    {
        while(m>k&&Cross(st[m-2],p[i],st[m-1])<=0)m--;
        st[m++]=p[i];
    }
    if(n>1) m--;
    return m;
}

double dist(point a,point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

double rotating_calipers(point *p,int n)
{
    int R=1,U=1,L;
    double ans = inf;
    p[n]=p[0];
    for(int i=0; i<n; i++)
    {
        while(dcmp(Cross(p[i],p[i+1],p[U+1])-Cross(p[i],p[i+1],p[U]))<=0) U=(U+1)%n;
        while(dcmp(dot(p[i],p[i+1],p[R+1])-dot(p[i],p[i+1],p[R]))>0) R=(R+1)%n;
        if(i==0) L=R;
        while(dcmp(dot(p[i],p[i+1],p[L+1])-dot(p[i],p[i+1],p[L]))<=0) L=(L+1)%n;
        double d=dist(p[i],p[i+1])*dist(p[i],p[i+1]);
        double area=fabs(Cross(p[i],p[i+1],p[U]))*
                    fabs(dot(p[i],p[i+1],p[R])-dot(p[i],p[i+1],p[L]))/d;
        if(area<ans) ans = area;
    }
    return ans;
}

int main()
{
    int n,t,cas=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        n*=4;
        for(int i=0; i<n; i++)
        {
            scanf("%lf%lf",&p[i].x,&p[i].y);
        }
        int m = ConvexHull(p,n,st);
        double ans;
        if(m<3) ans=0;
        else ans = rotating_calipers(st,m);
        printf("Case #%d:\n%.0lf\n",cas++,ans);
    }
    return 0;
}
