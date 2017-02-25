// HDU5317
//http://acm.hdu.edu.cn/showproblem.php?pid=5317


#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
const int N=1e6+5;

int f[N],num[N][10],b[10];
void init()
{
    memset(f,0,sizeof(f));
    for(int i=2;i<N;i++)
    {
        if(f[i]==0)
        {
            f[i]=1;
            for(int j=i+i;j<N;j+=i)
            {
                f[j]++;
            }
        }
    }
    for(int i=2;i<N;i++)
    {
        for(int j=1;j<8;j++)
        {
            num[i][j]=num[i-1][j];
        }
        num[i][f[i]]++;
    }
}

int main()
{
    int t,l,r;
    init();
    cin>>t;
    while(t--)
    {
        scanf("%d%d",&l,&r);
        int ans=0;
        for(int i=1;i<8;i++)
        {
            b[i]=num[r][i]-num[l-1][i];
            if(num[r][i]-num[l-1][i]>1)
                ans=i;
        }
        if(ans!=0)
            printf("%d\n",ans);
        else if((b[2]>0&&b[4]>0)||(b[2]>0&&b[6]>0)||(b[6]>0&&b[4]>0))
            printf("2\n");
        else if(b[3]>0&&b[6]>0)
            printf("3\n");
        else
            printf("1\n");
    }
    return 0;
}
