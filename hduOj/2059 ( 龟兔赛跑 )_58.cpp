// 2059 ( 龟兔赛跑 )
//acm.hdu.edu.cn/showproblem.php?pid=2059


#include<iostream>
#include<algorithm>
double DP[102];
int s[102];
using namespace std;
int main()
{
    double L;
    int n,i,j;
    double electricity_l,electricity_t;
    double vt_rabbit,vt_ele,vt_none;
    double len,sum,Time;
    while(cin>>L)
    {
        cin>>n>>electricity_l>>electricity_t;
        cin>>vt_rabbit>>vt_ele>>vt_none;
        for(i=1;i<=n;i++)
        cin>>s[i];
        s[n+1]=L;
        s[0]=0;
        DP[0]=0;
        for(i=1;i<=n+1;i++)
        {
            DP[i]=0xfffff;
            for(j=0;j<i;j++)
            {
                len=s[i]-s[j];
                if(len>electricity_l)
                Time=electricity_l/vt_ele+(len-electricity_l)/vt_none;
                else
                Time=len/vt_ele;
                Time+=DP[j];
                if(j>0)
                    Time+=electricity_t;
                DP[i]=min(DP[i],Time);
            }
        }
        if(DP[n+1]<(L/vt_rabbit))
        cout<<"What a pity rabbit!"<<endl;
        else
        cout<<"Good job,rabbit!"<<endl;
    }
    return 0;
}

