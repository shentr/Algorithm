// CodeForces417E
//http://codeforces.com/problemset/problem/417E


#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;
bool cmp(long long s)
{
    long long t;
    t=sqrt(s);
    if(t*t==s)
        return 1;
    else return 0;
}
long long s1,s2,s3,s4;
int a,b,c,d,n,m;
int main()
{
    //while(scanf("%d%d",&n,&m)!=EOF)
        scanf("%d%d",&n,&m);
   // freopen("cin.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    {
        s1=0,s2=0,s3=0,s4=0;
        for(int a=1; a<=100; a++)
        {
             for(int b=1; b<=100; b++)
            {
                for(int c=1; c<=100; c++)
                {
                    for(int d=1; d<=100; d++)
                    {
                        s1=a*a*(m-1)+c*c;
                        s2=a*a*(n-1)+b*b;
                        s3=b*b*(m-1)+d*d;
                        s4=c*c*(n-1)+d*d;
                        if(cmp(s1)&&cmp(s2)&&cmp(s3)&&cmp(s4))
                        {
                            // cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
                            // cout<<s1<<" "<<s2<<" "<<s3<<" "<<s4<<endl;
                            for(int i=1; i<=n-1; i++)
                            {
                                for(int j=1; j<=m-1; j++)
                                    printf("%d ",a);
                                //printf(" ");
                                printf("%d\n",c);
                            }

                            for(int k=1; k<=m-1; k++)
                                printf("%d ",b);
                            printf("%d\n",d);
                            //break;
                            return 0;
                        }
                        // break;
                    }
                    // break;
                }
                // break;
            }
            //break;
        }
    }


}
