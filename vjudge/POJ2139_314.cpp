// POJ2139
//http://poj.org/problem?id=2139


#include <iostream>
#include <string.h>
#include <stdio.h>
#define INF 99999999
using namespace std;
int n,m,t;
int a[305],e[1005][1005];
int main()
{
    while(cin>>n>>m)
    {
        double sum2=0.0;
        long long minn=INF;
        int flag=0,flag2=0;
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
            {
                e[i][j]=INF;
                if(i==j)
                 e[i][j]=0;
            }
        for(int q=1; q<=m; q++)
        {
            memset(a,0,sizeof(0));
            cin>>t;
            for(int p=1; p<=t; p++)
                cin>>a[p];
            for(int i=1; i<=t; i++)
                for(int j=i+1; j<=t; j++)
                {
                    e[a[i]][a[j]]=e[a[j]][a[i]]=1;
                }
        }
        for(int k=1; k<=n; k++)
            for(int i=1; i<=n; i++)
                for(int j=1; j<=n; j++)
                {
                    {
                        if(e[i][j]>e[i][k]+e[k][j])
                            e[i][j]=e[i][k]+e[k][j];
                    }
                }
        for(int i=1; i<=n; i++)
        {
            long long sum=0;
            for(int j=1; j<=n; j++)
            {
                sum+=e[i][j];
            }
             //cout<<sum<<endl;
            minn=min(sum,minn);

        }
        //cout<<minn<<endl;
        sum2=(double)minn/(n-1);
        //printf("%lf\n",sum2);
        cout<<(int)(sum2*100)<<endl;
         // for(int i=1; i<=n; i++)
              //  for(int j=1; j<=n; j++)
              //   cout<<e[i][j]<<endl;

    }
    return 0;
}
