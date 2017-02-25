// LightOJ1199
//http://lightoj.com/login_main.php?url=volume_showproblem.php?problem=1199


#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long LL;
const LL N=1e4+5;
int sg[N],hs[N];
//sg[x] = mex(sg[1]^sg[x-1],sg[2]^sg[x-2],...,sg[(x-1)/2]^sg[x-(x-1)/2]);
void Init_SG()
{
    memset(sg,0,sizeof(sg));
    sg[0]=sg[1]=sg[2]=0;
    for(int i=3;i<=N;i++)
    {
        memset(hs,0,sizeof(hs));
        for(int j=1;j<=(i-1)/2;j++)
        {
            hs[sg[j]^sg[i-j]]=1;
        }
        for(int j=0;j<=i;j++)
        {
            if(hs[j]==0)
            {
                sg[i]=j;
                break;
            }
        }
    }
}

/*void test()
{
    Init_SG();
    for(int i=0;i<=100;i++)
        cout<<i<<' '<<sg[i]<<endl;
}*/

int main()
{
    //test();
    int t;
    scanf("%d",&t);
    Init_SG();
    for(int kase=1;kase<=t;kase++)
    {
        int n;
        scanf("%d",&n);
        LL a,ans=0;
        for(int i=0;i<n;i++)
        {
            scanf("%lld",&a);
            ans^=sg[a];
        }
        if(ans==0)
            printf("Case %d: Bob\n",kase);
        else
            printf("Case %d: Alice\n",kase);
    }
}
