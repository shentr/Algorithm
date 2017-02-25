// ACdream1414
//http://acdream.info/problem?pid=1414


#include"iostream"
#include"cstdio"
#include"cmath"
using namespace std;

struct point
{
    double x,y;
};

double dis(point a,point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

int main()
{
    point a,b,c,d;
    while(cin>>a.x>>a.y>>b.x>>b.y)
    {
        cin>>c.x>>c.y>>d.x>>d.y;
        if(!a.x&&!a.y&&!b.y&&!b.x&&!c.x&&!c.y&&!d.x&&!d.y)
            break;
        point circle;
        double r,aa[4];
        aa[0]=dis(a,c);
        aa[1]=dis(a,d);
        aa[2]=dis(b,c);
        aa[3]=dis(b,d);
        point tmp1,tmp2;
        double dd=min(min(aa[0],aa[1]),min(aa[2],aa[3]));
        if(dd==aa[0])
        {
            circle.x=(a.x+c.x)/2;
            circle.y=(a.y+c.y)/2;
        }
        else if(dd==aa[1])
        {
            circle.x=(a.x+d.x)/2;
            circle.y=(a.y+d.y)/2;
        }
        else if(dd==aa[2]){
            circle.x=(b.x+c.x)/2;
            circle.y=(b.y+c.y)/2;
        }
        else if(dd==aa[3])
        {
            circle.x=(b.x+d.x)/2;
            circle.y=(b.y+d.y)/2;
        }
        r=dd/2.0+0.001;
        printf("%.4lf %.4lf %.4lf\n",circle.x,circle.y,r);
    }
    return 0;
}
