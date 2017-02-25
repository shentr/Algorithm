// HDU1521
//http://acm.hdu.edu.cn/showproblem.php?pid=1521


#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long LL;
double a[15],b[15],num[15];

double jiecheng(int n)
{
    double ans=1.0;
    for(int i=1;i<=n;i++)
        ans*=i;
    return ans;
}

int main()
{
    int n,m;
    while(cin>>n>>m){
    for(int i=1;i<=n;i++)
        cin>>num[i];
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    //a[0]=1.0;
    for(int i=0;i<=num[1];i++)
        a[i]=1.0/jiecheng(i);
    for(int i=2;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            for(int k=0;k<=num[i]&&j+k<=m;k++)
            {
                b[j+k]+=a[j]/jiecheng(k);
            }
        }
        for(int j=0;j<=m;j++)
        {
            a[j]=b[j];
            b[j]=0;
        }
    }
    printf("%.0lf\n",a[m]*jiecheng(m));
    }
    
}


/*
3 2
5 3 2
6 3
2 5 3 5 2 1
10 6
8 7 6 5 7 8 0 6 3 2

*/
