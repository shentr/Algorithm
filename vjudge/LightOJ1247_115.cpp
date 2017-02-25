// LightOJ1247
//http://lightoj.com/login_main.php?url=volume_showproblem.php?problem=1247


#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    int t;
    int n,m;
    long long sum,a,ans;
    cin>>t;
    for(int kase=1;kase<=t;kase++)
    {
        scanf("%d%d",&n,&m);
        sum=0;
        for(int j=0;j<m;j++)
        {
            scanf("%lld",&a);
            sum+=a;
        }
        ans=sum;
        for(int i=1;i<n;i++)
        {
            sum=0;
            for(int j=0;j<m;j++)
            {
                scanf("%lld",&a);
                sum+=a;
            }
            ans=ans^sum;
        }
        if(ans==0)
        {
            printf("Case %d: Bob\n",kase);
        }
        else
            printf("Case %d: Alice\n",kase);
    }
}
