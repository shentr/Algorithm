// LightOJ1296
//http://lightoj.com/login_main.php?url=volume_showproblem.php?problem=1296


#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long LL;
/*const LL N=505;
int sgv[N],hs[N];

void Init_SG()
{
    memset(sgv,0,sizeof(0));
    for(int i=1;i<=N;i++)
    {
        memset(hs,0,sizeof(hs));
        for(int j=1;j<=i/2;j++)
        {
            hs[sgv[i-j]]=1;
        }
        for(int j=0;j<=i/2;j++)
        {
            if(hs[j]==0)
            {
                sgv[i]=j;
                break;
            }
        }
    }
}

void test()
{
    Init_SG();
    for(int i=0;i<=500;i++)
        if(i&1&&(i-1)%4!=0&&(i-3)%8!=0&&(i-7)%16!=0)
        cout<<i<<' '<<sgv[i]<<endl;
}
*/

LL sg(LL n)
{
    if(n&1)
    {
        LL m=1;
        while(m<n)
        {
            m*=2;
            if((n-m+1)%(m*2)==0)
                return (n-m+1)/(m*2);
        }
    }
    if(n%2==0)
        return n/2;
    return 0;
}

int main()
{
    //test();
    int t;
    scanf("%d",&t);
    for(int kase=1;kase<=t;kase++)
    {
        int n;
        scanf("%d",&n);
        LL a;
        scanf("%lld",&a);
        LL ans=sg(a);
        for(int i=1;i<n;i++)
        {
            scanf("%lld",&a);
            ans^=sg(a);
        }
        if(ans==0)
            printf("Case %d: Bob\n",kase);
        else
            printf("Case %d: Alice\n",kase);
    }
}
