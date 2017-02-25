// POJ3907
//http://poj.org/problem?id=3907


#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int main()
{
    int n,i;
    double sum;
    double x0,x1,x2,y0,y1,y2;
    while(cin>>n)
    {
        sum=0;
        if(n==0)
            break;
        cin>>x0>>y0;
        x2=x0;
        y2=y0;
        for(i=1; i<n; i++)
        {
            cin>>x1>>y1;
            sum+=x0*y1-x1*y0;
            x0=x1;
            y0=y1;
        }
        x1=x2;
        y1=y2;
        sum+=x0*y1-x1*y0;
        printf("%.0f\n",fabs(sum/2));

    }
    return 0;
}
