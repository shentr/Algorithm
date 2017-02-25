// LightOJ1253
//http://lightoj.com/login_main.php?url=volume_showproblem.php?problem=1253


#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int kase=1;kase<=t;kase++)
    {
        int k;
        cin>>k;
        long long a=0,b,cnt=0;
        for(int i=0;i<k;i++)
        {
            scanf("%lld",&b);
            if(b>1)
                cnt++;
            a=a^b;
        }
        if((!a&&!cnt)||(a&&cnt))
            printf("Case %d: Alice\n",kase);
        else
            printf("Case %d: Bob\n",kase);
    }
}
