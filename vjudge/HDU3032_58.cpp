// HDU3032
//http://acm.hdu.edu.cn/showproblem.php?pid=3032


#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long LL;
/*const int N=1e4+5;
int sg[N],hs[N];
void Init_SG()
{
    memset(sg,0,sizeof(sg));
    //sg[0]=sg[1]=sg[2]=0;
    for(int i=1;i<N;i++)
    {
        memset(hs,0,sizeof(hs));
        for(int j=0;j<i;j++)
            hs[sg[j]]=1;
        for(int j=1;j<=i/2;j++)
        {
            hs[sg[j]^sg[i-j]]=1;
        }
        for(int j=0;j<=N;j++)
        {
            if(hs[j]==0)
            {
                sg[i]=j;
                break;
            }
        }
    }
}

void test()
{
    Init_SG();
    for(int i=0;i<=100;i++)
        cout<<i<<' '<<sg[i]<<endl;
}*/

int sg(int a)
{
    if(a==0)
        return 0;
    if(a%4==0)
        return a-1;
    if(a%4==3)
        return a+1;
    return a;
}

int main()
{
    //test();
    int t;
    scanf("%d",&t);
    //Init_SG();
    for(int kase=1;kase<=t;kase++)
    {
        int n;
        scanf("%d",&n);
        LL a,ans=0;
        for(int i=0;i<n;i++)
        {
            scanf("%lld",&a);
            ans^=sg(a);
        }
        if(ans==0)
            printf("Bob\n");
        else
            printf("Alice\n");
    }
}
