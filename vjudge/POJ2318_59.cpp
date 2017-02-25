// POJ2318
//http://poj.org/problem?id=2318


#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
#include <map>
#include <vector>
#include <set>
#include <string>
#include <math.h>

using namespace std;
struct Point
{
    int x,y;
    Point(){}
    Point(int _x,int _y)
    {
        x = _x;y = _y;
    }
    Point operator -(const Point &b)const
    {
        return Point(x - b.x,y - b.y);
    }
    int operator *(const Point &b)const
    {
        return x*b.x + y*b.y;
    }
    int operator ^(const Point &b)const
    {
        return x*b.y - y*b.x;
    }
};
struct Line
{
    Point s,e;
    Line(){}
    Line(Point _s,Point _e)    
    {
        s = _s;e = _e;
    }
};

int xmult(Point p0,Point p1,Point p2) //计算p0p1 X p0p2
{
    return (p1-p0)^(p2-p0);
}
const int MAXN = 5050;
Line line[MAXN];
int ans[MAXN];
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,m,x1,y1,x2,y2;
    bool first = true;
    while(scanf("%d",&n) == 1 && n)
    {
        if(first)first = false;
        else printf("\n");
        scanf("%d%d%d%d%d",&m,&x1,&y1,&x2,&y2);
        int Ui,Li;
        for(int i = 0;i < n;i++)
        {
            scanf("%d%d",&Ui,&Li);
            line[i] = Line(Point(Ui,y1),Point(Li,y2));
        }
        line[n] = Line(Point(x2,y1),Point(x2,y2));
        int x,y;
        Point p;
        memset(ans,0,sizeof(ans));
        while( m-- )
        {
            scanf("%d%d",&x,&y);
            p = Point(x,y);
            int l = 0,r = n;
            int tmp;
            while( l <= r)
            {
                int mid = (l + r)/2;
                if(xmult(p,line[mid].s,line[mid].e) < 0)
                {
                    tmp = mid;
                    r = mid - 1;
                }
                else l = mid + 1;
            }
            ans[tmp]++;
        }
        for(int i = 0; i <= n;i++)
            printf("%d: %d\n",i,ans[i]);
    }
    return 0;
}