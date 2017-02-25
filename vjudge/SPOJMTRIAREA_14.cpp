// SPOJMTRIAREA
//http://www.spoj.com/problems/MTRIAREA


#include<iostream>
#include<cstdio>
#include<algorithm>
#include<math.h>
#define eps 1e-8
#define inf 1e10
#define maxn 50020
struct point
{
    double x,y;
} p[maxn],save[maxn];
int n;
double xmult(point p1,point p2,point p0)
{
    return (p1.x-p0.x)*(p2.y-p0.y)-(p1.y-p0.y)*(p2.x-p0.x);
}
double max(double a,double b)
{
    return a>b? a:b;
}
bool cmp(const point &a,const point &b )
{
    if(a.y==b.y)return a.x<b.x;
    return a.y<b.y;
}
int Graham()
{
    int i;
    std::sort(p,p+n,cmp);
    save[0]=p[0];
    save[1]=p[1];
    int top=1;
    for(i=0; i<n; i++)
    {
        while(top>0&& xmult(save[top],p[i],save[top-1])>=0)top--;
        save[++top]=p[i];
    }
    int mid=top;
    for(i=n-2; i>=0; i--)
    {
        while(top>mid&&xmult(save[top],p[i],save[top-1])>=0)top--;
        save[++top]=p[i];
    }
    return top;
}
double rc_tri()
{
    if(n<3)return 0;
    double maxx=0 ,temp;
    int i;
    int b=1,c=2;
    save[n]=save[0];
    save[n+1]=save[1];
    save[n+2]=save[2];
    for(i=0; i<n; i++)
    {
        while(xmult(save[c+1],save[b],save[i])-(temp=xmult(save[c],save[b],save[i]))>eps)
            c=(c+1)%n;
        maxx=max(maxx,temp);
        while(xmult(save[c],save[b+1],save[i])
                -(temp=xmult(save[c],save[b],save[i]))>eps)
            b=(b+1)%n;
        maxx=max(maxx,temp);
    }
    return maxx;
}

int main()
{
    while(scanf("%d",&n),n!=-1)
    {
        int i;
        for(i=0; i<n; i++)scanf("%lf%lf",&p[i].x,&p[i].y);
        n=Graham();
        printf("%.2lf\n",rc_tri()/2);
    }
    return 0;
}
