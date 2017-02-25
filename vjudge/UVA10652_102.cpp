// UVA10652
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=10652


#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const double eps=1e-7;
struct Point{
    double x,y;
    Point(double x0=0,double y0=0){
        x=x0,y=y0;
    }
    void read(){ scanf("%lf%lf",&x,&y); }
    friend bool operator < (Point a,Point b){
        if(a.y!=b.y) return a.y<b.y;
        else return a.x<b.x;
    }
    double getdis(Point q){ return sqrt( (x-q.x)*(x-q.x)+(y-q.y)*(y-q.y) ); }
};

typedef Point Vector;

Vector operator + (Vector A,Vector B) { return Vector(A.x+B.x,A.y+B.y); }
Vector operator - (Vector A,Vector B) { return Vector(A.x-B.x,A.y-B.y); }
Vector operator * (Vector A,double p) { return Vector(A.x*p,A.y*p); }
Vector operator / (Vector A,double p) { return Vector(A.x/p,A.y/p); }

int dcmp(double x) { if(fabs(x)<eps) return 0; else return x<0?-1:1; }
double Dot(Vector A,Vector B){ return A.x*B.x+A.y*B.y; }
double Length(Vector A){ return sqrt(Dot(A,A)); }
double Angle(Vector A,Vector B){ return acos(Dot(A,B)/Length(A)/Length(B)); }
double Cross(Vector A,Vector B){ return A.x*B.y-A.y*B.x; }
Vector Rotate(Vector A,double rad){ return Vector(A.x*cos(rad)-A.y*sin(rad),A.x*sin(rad)+A.y*cos(rad)); }//逆时针旋转rad弧度
double torad(double ang){ return ang/180.0*acos(-1.0); }

const int maxn=2500;
Point p[maxn];
int n,top;
double sum;

bool cmp(Point a,Point b){
    if( fabs( Cross(a-p[0],b-a) )<eps ) return a.getdis(p[0])<b.getdis(p[0]);
    else return Cross(a-p[0],b-a)>0;
}

double ConvexHull(){
    top=1;
    sort(p,p+n);
    sort(p+1,p+n,cmp);
    for(int i=2;i<n;i++){
        while(top>0 && Cross(p[top]-p[top-1],p[i]-p[top-1])<=0) top--;
        p[++top]=p[i];
    }
    p[++top]=p[0];
    double area=0;
    for(int i=1;i<top;i++){
        area+=Cross(p[i]-p[0],p[i+1]-p[0]);
    }
    return area/2.0;
}

void input(){
    n=0;
    sum=0;
    int m;
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        Point o;
        double w,h,ang,rad;
        scanf("%lf%lf%lf%lf%lf",&o.x,&o.y,&w,&h,&ang);
        rad=-torad(ang);
        p[n++]=o+Rotate(Vector(-w/2.0,-h/2.0),rad);
        p[n++]=o+Rotate(Vector(-w/2.0,h/2.0),rad);
        p[n++]=o+Rotate(Vector(w/2.0,h/2.0),rad);
        p[n++]=o+Rotate(Vector(w/2.0,-h/2.0),rad);
        sum+=w*h;
    }
}

void solve(){
    double ans=ConvexHull();
    printf("%.1lf %%\n",sum*100.0/ans);
}

int main(){
    int T;
    scanf("%d",&T);
    while(T-- >0){
        input();
        solve();
    }
    return 0;
}
