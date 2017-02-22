// 1864 ( 最大报销额 )
//acm.hdu.edu.cn/showproblem.php?pid=1864


#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=35;
double dp[3000010];

int main()
{
    char type;
    int n,m,z,flag;
    double q,tpa,tpb,tpc,mon,all,per[N];
    while(~scanf("%lf%d",&q,&n)&&n)
    {
        z=0;
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++)              // i zhang stamp
        {
            tpa=0,tpb=0,tpc=0,all=0;
            flag=0;
            scanf("%d",&m);
            while(m--)                   //type
            {
                scanf("%*c%c:%lf",&type,&mon);
                all+=mon;
                if(type=='A')
                    tpa+=mon;
                else if(type=='B')
                    tpb+=mon;
                else if(type=='C')
                    tpc+=mon;
                else
                    flag=1;
            }
            if(tpa<=600&&tpb<=600&&tpc<=600&&all<=1000&&!flag)
                per[z++]=all*100;
        }
        int Q=(int)(q*100.0);
        for(int i=0;i<z;i++)
        {
            for(int j=Q;j-(int)per[i]>=0;j--)
                dp[j]=max(dp[j],dp[j-(int)per[i]]+(int)per[i]);
        }
        printf("%.2lf\n",dp[Q]*0.01);
    }
}

