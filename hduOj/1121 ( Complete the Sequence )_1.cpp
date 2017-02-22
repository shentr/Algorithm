// 1121 ( Complete the Sequence )
//acm.hdu.edu.cn/showproblem.php?pid=1121


#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
long long a[105][105];

bool cha(int i,int s)
{
    for(int j=0;j<s-i;j++)
        if(a[i][j]!=a[i][0])
            return false;
    return true;
}

int main()
{
    int kase;
    cin>>kase;
    while(kase--)
    {
        memset(a,0,sizeof(a));
        int s,c;
        cin>>s>>c;
        for(int j=0;j<s;j++)
            scanf("%lld",&a[0][j]);
        int degree=0;
        int i=0,j=0;
        while(true)
        {
            i++;
            for(int j=0;j<s-i;j++)
                a[i][j]=a[i-1][j+1]-a[i-1][j];
            if(cha(i,s))
            {
                break;
            }
        }

        for(int j=0;j<s+c;j++)
            a[s+c-1][j]=a[s+c-1][0];
        for(int i=s+c-2;i>=0;i--)
            for(int j=1;j<s+c;j++)
                a[i][j]=a[i][j-1]+a[i+1][j-1];
        printf("%lld",a[0][s]);
        for(int j=s+1;j<s+c;j++)
            printf(" %lld",a[0][j]);
        printf("\n");
    }
    return 0;
}
