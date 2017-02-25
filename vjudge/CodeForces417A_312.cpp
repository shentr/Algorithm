// CodeForces417A
//http://codeforces.com/problemset/problem/417A


#include <iostream>
#include <stdio.h>
using namespace std;
double t1,t2;
long long num,c,d,m,n,k,s1,s2;
int main()
{
    while(cin>>c>>d)
    {
        int sum=0;
        cin>>n>>m>>k;
        t1=c/n;
        t2=d;
        num=n*m;
        num=num-k;
        while(num>0)
        {
            if(t1<t2&&num>0)
            {
                s1=num/n;
                sum+=s1*c;
                s2=num%n;
                sum+=min(c,s2*d);
                break;

              //  printf("%lf\n",t1);
                //cout<<num<<endl;
            }
            else if(t1>t2&&num>0)
            {
                sum+=num*d;
                break;
            }
            else if(t1==t2)
            {
                sum+=num*d;
                break;
            }
        }
        cout<<sum<<endl;

    }
    return 0;
}
