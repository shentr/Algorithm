// POJ3299
//http://poj.org/problem?id=3299


#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;
char c,s,first,second;
double t,d,h,H,e,a,b;
int main()
{
    while(cin>>first)
    {
        if(first=='E')
            break;
        cin>>a>>second>>b;
        if((first=='T'&&second=='D')||(first=='D'&&second=='T'))
        {
            if(first=='T'&&second=='D')
                {
                    t=a;
                    d=b;
                }
                else if(first=='D'&&second=='T')
                {
                    t=b;
                    d=a;
                }
            e=6.11*exp(5417.7530*((1/273.16)-(1/(d+273.16))));
            h=(0.5555)*(e-10.0);
            H=t+h;
            printf("T %.1f D %.1f H %.1f\n",t,d,H);
        }
        else if((first=='D'&&second=='H')||(first=='H'&&second=='D'))
        {
            if(first=='H'&&second=='D')
            {
                H=a;
                d=b;
            }
            else if(first=='D'&&second=='H')
            {
                d=a;
                H=b;
            }
            e=6.11*exp(5417.7530*((1/273.16)-(1/(d+273.16))));
            h=(0.5555)*(e-10.0);
            t=H-h;
            printf("T %.1f D %.1f H %.1f\n",t,d,H);
            //D =( 1/(-log(e/6.11)/5417.7530 + (1/273.16))-273.16);
        }
        else if((first=='T'&&second=='H')||(first=='H'&&second=='T'))
        {
            if(first=='T'&&second=='H')
            {
                t=a;
                H=b;
            }
            else if(first=='H'&&second=='T')
            {
               t=b;
               H=a;
            }
            h=H-t;
            //h=(0.5555)*(e-10.0);
            e=h/0.5555+10.0;
            d=1/(-log(e/6.11)/5417.7530+1/273.16)-273.16;
            printf("T %.1f D %.1f H %.1f\n",t,d,H);
        }



    }
    return 0;
}
