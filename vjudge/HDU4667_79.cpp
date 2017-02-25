// HDU4667
//http://acm.hdu.edu.cn/showproblem.php?pid=4667


#include <iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<ctime>
using namespace std;
const double eps=1e-10;
const double pi=acos(-1.0);
struct point
{
    double x,y;
    int s,o;
    void input()
    {
        scanf("%lf%lf",&x,&y);
    }
};
struct triangle
{
    point a,b,c;
    void input()
    {
        a.s=b.s=c.s=-1;
        a.input(),b.input(),c.input();
    }
};
struct circle
{
    point center;
    double r;
    void input()
    {
        center.input(),scanf("%lf",&r);
    }
};
point data[100005],stack[100005],MinA;
triangle t[55];
circle c[55];
int top,num,n,m;
double Direction(point pi,point pj,point pk) //判断向量PiPj在向量PiPk的顺逆时针方向 +顺-逆0共线
{
    return (pj.x-pi.x)*(pk.y-pi.y)-(pk.x-pi.x)*(pj.y-pi.y);
}
double dis(point a,point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double Dis(point a,point b)
{
    double ret=dis(a,b);
    if(a.s!=-1&&a.s==b.s)
    {
        int i=a.s;
        double a1=atan2(a.y-c[i].center.y,a.x-c[i].center.x),a2=atan2(b.y-c[i].center.y,b.x-c[i].center.x);
        a2-=a1;
        if(a2<0)
            a2+=2*pi;
        return a2*c[i].r;
    }
    return ret;
}
bool cmp(point a,point b)
{
    double k=Direction(MinA,a,b);
    if(k>0) return 1;
    if(k<0) return 0;
    return Dis(MinA,a)>Dis(MinA,b);
}
void Graham_Scan(point *a,int numa)
{
    for(int i=0; i<numa; i++)
        if(a[i].y<a[0].y||(a[i].y==a[0].y&&a[i].x<a[0].x))
            swap(a[i],a[0]);
    MinA=a[0],top=0;
    sort(a+1,a+numa,cmp);
    stack[top++]=a[0],stack[top++]=a[1],stack[top++]=a[2];
    for(int i=3; i<numa; i++)
    {
        while(Direction(stack[top-2],stack[top-1],a[i])<=eps&&top>=2)
            top--;
        stack[top++]=a[i];
    }
}
void pointcircle(point a,circle c,int i)
{
    double a1=atan2(a.y-c.center.y,a.x-c.center.x),a2=acos(c.r/dis(a,c.center));
    data[num].o=-1,data[num].s=i,data[num].x=c.center.x+c.r*cos(a1+a2),data[num++].y=c.center.y+c.r*sin(a1+a2);
    data[num].o=-1,data[num].s=i,data[num].x=c.center.x+c.r*cos(a1-a2),data[num++].y=c.center.y+c.r*sin(a1-a2);
}
void get1(triangle t,circle c,int i)
{
    pointcircle(t.a,c,i);
    pointcircle(t.b,c,i);
    pointcircle(t.c,c,i);
}
void get2(circle a,circle b,int i,int j)
{
    double d1=dis(a.center,b.center),d2=fabs(a.r-b.r),a1,a2;
    a1=atan2(b.center.y-a.center.y,b.center.x-a.center.x);
    a2=acos(d2/d1);
    data[num].o=0,data[num].s=i,data[num].x=a.center.x+a.r*cos(a1+a2),data[num++].y=a.center.y+a.r*sin(a1+a2);
    data[num].o=0,data[num].s=i,data[num].x=a.center.x+a.r*cos(a1-a2),data[num++].y=a.center.y+a.r*sin(a1-a2);
    data[num].o=0,data[num].s=j,data[num].x=b.center.x+b.r*cos(a1+a2),data[num++].y=b.center.y+b.r*sin(a1+a2);
    data[num].o=0,data[num].s=j,data[num].x=b.center.x+b.r*cos(a1-a2),data[num++].y=b.center.y+b.r*sin(a1-a2);
}
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        num=0;
        for(int i=0; i<n; i++)
            c[i].input();
        for(int i=0; i<m; i++)
            t[i].input();
        if(n==1&&m==0)
        {
            printf("%.10f\n",2*pi*c[0].r);
            continue;
        }
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
            {
                if(i==j)continue;
                get2(c[i],c[j],i,j);
            }
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                get1(t[i],c[j],j);
        for(int i=0; i<m; i++)
            data[num++]=t[i].a,data[num++]=t[i].b,data[num++]=t[i].c;
        Graham_Scan(data,num);
        double ans=0;
        for(int i=0; i<top; i++)
            ans+=Dis(stack[i],stack[(i+1)%top]);
        printf("%.10f\n",ans);
    }
    return 0;
}
