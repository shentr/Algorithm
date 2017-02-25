// Gym100286G
//undefined100286G


#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;
const int INF=0x3f3f3f3f;
const int maxn=105;
struct sa
{
    int rh,rv,sh,sv,p;
}x[maxn],b;
int main()
{
    freopen("giant.in","r",stdin);
    freopen("giant.out","w",stdout);
    int n;
    while(cin>>b.rh>>b.rv>>b.sh>>b.sv)
    {
        cin>>n;
       long long minn=INF;

        for(int i=1;i<=n;i++)
        {
            memset(x,0,sizeof(x));
            long long sum1=0,sum2=0,sum3=0,sum4=0;
            cin>>x[i].rh>>x[i].rv>>x[i].sh>>x[i].sv>>x[i].p;
            if(x[i].rh>=b.rh&&x[i].sh>=b.sh)
                sum1=1;
            else
            {
                sum1=max(b.rh/x[i].rh,b.sh/x[i].sh);
                if(sum1*x[i].rh<b.rh||sum1*x[i].sh<b.sh)
                    sum1++;
            }


            if(x[i].rv>=b.rv&&x[i].sv>=b.sv)
                sum2=1;
            else
            {
                sum2=max(b.rv/x[i].rv,b.sv/x[i].sv);
                if(sum2*x[i].rv<b.rv||sum2*x[i].sv<b.sv)
                    sum2++;
            }


            minn=min(minn,sum1*sum2*x[i].p);


            if(x[i].rv>=b.rh&&x[i].sv>=b.sh)
            sum3=1;
            else
            {
                sum3=max(b.rh/x[i].rv,b.sh/x[i].sv);
                if(sum3*x[i].rv<b.rh||sum3*x[i].sv<b.sh)
                    sum3++;
            }


           if(x[i].rh>=b.rv&&x[i].sh>=b.sv)
                sum4=1;
           else
            {
                sum4=max(b.rv/x[i].rh,b.sv/x[i].sh);
                if(sum4*x[i].rh<b.rv||sum4*x[i].sh<b.sv)
                    sum4++;
            }
            minn=min(minn,sum3*sum4*x[i].p);
        }
        cout<<minn<<endl;
    }
    return 0;
}
/**
1024 1024 300 300
3
1024 768 295 270 200
1280 1024 365 301 250
1280 800 350 270 210
2400 2000 800 700
3
1024 768 295 270 200
1280 1024 365 301 250
1280 800 350 270 210
*/

