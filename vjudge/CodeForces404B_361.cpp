// CodeForces404B
//http://codeforces.com/problemset/problem/404B


#include <iostream>
#include <stdio.h>
#define INF 1.0e-6
#include <math.h>
using namespace std;
double a,d,q,x,y,s;
int n;
int main()
{
    while(scanf("%lf%lf",&a,&d)!=EOF)
    {
       scanf("%d",&n);
        double s=0.0;
        for(int i=1;i<=n;i++)
        {
            x=0.0,y=0.0;
            s=s+d;

                s=fmod(s,4*a);
                if(s<=a)
                {
                    x=s;
                    y=0.0;
                }
                else if(s<=2*a)
                {
                    x=a;
                    y=s-a;
                }
                else if(s<=3*a)
                {
                    x=3*a-s;
                    y=a;
                }
                else
                {
                    x=0.0;
                    y=4*a-s;
                }

            if(x<INF)
                x=0;
            if(y<INF)
                y=0;
            printf("%.10lf %.10lf\n",x,y);
        }

    }
    return 0;
}
