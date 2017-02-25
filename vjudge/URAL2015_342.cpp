// URAL2015
//http://acm.timus.ru/problem.aspx?space=2.015&num=2015


#include <iostream>
#include <math.h>
#include <string.h>
#include <algorithm>
using namespace std;
struct sa
{
    int val;
    int happy;
} f[260];
struct sa2
{
    int num;
    int val;
    int happy;
} home[260];
int main()
{
    int pay,hone,htwo,n,m;
    while(cin>>pay>>hone>>htwo)
    {
        memset(f,0,sizeof(f));
        memset(home,0,sizeof(home));
        int maxn=-1;
        int max1=-4;
        int max2=-2;
        int max3=-3;
        cin>>n;
        for(int i=1; i<=n; i++)
            cin>>f[i].val>>f[i].happy;//朋友能出的钱和快乐值
        cin>>m;
        for(int i=1; i<=m; i++)
            cin>>home[i].num>>home[i].val>>home[i].happy;//房子的数量，价值，快乐值
        int hnum1=0,hnum2=0,fnum2=0,hnum3=0;
        for(int j=1; j<=m; j++)
        {
           // for(int i=1; i<=n; i++)
           // {
            if(home[j].num==1)
            {
                if(home[j].val<=pay)
                {
                    if(max1<home[j].happy+hone)
                    {
                        max1=home[j].happy+hone;
                        hnum1=j;
                    }
                }
            }
            else if(home[j].num==2)
            {
                for(int i=1; i<=n; i++)
                {
                    if(min(pay,f[i].val)*2>=home[j].val)
                    {
                        if(max2<home[j].happy+f[i].happy)
                        {
                            max2=home[j].happy+f[i].happy;
                            hnum2=j;
                            fnum2=i;
                        }

                    }
                }
                if(pay>=home[j].val)
                {
                    if(max3<home[j].happy+htwo)
                    {
                        max3=home[j].happy+htwo;
                        hnum3=j;
                    }
                }
            //}
            }
        }
        maxn=max(max(max(max1,max2),max3),maxn);
        if(maxn==-1)
            cout<<"Forget about apartments. Live in the dormitory."<<endl;
        if(maxn==max1)
        {
            cout<<"You should rent the apartment #"<<hnum1<<" alone."<<endl;
        }
        else if(maxn==max2)
        {
            cout<<"You should rent the apartment #"<<hnum2<<" with the friend #"<<fnum2<<"."<<endl;
        }
        else if(maxn==max3)
        {
            cout<<"You should rent the apartment #"<<hnum3<<" alone."<<endl;
        }
        //cout<<max1<<" "<<max2<<" "<<max3<<endl;

    }
    return 0;
}
