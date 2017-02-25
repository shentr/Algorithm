// CodeForces400A
//http://codeforces.com/problemset/problem/400A


#include <iostream>
#include <string.h>
using namespace std;
struct sa
{
    int x,y;
} a[15];
int main()
{
    int r[15];
    char s[15];
    int n,q;
    while(cin>>n)
    {

        for(int i=1; i<=n; i++)
        {
            int j=0,sum=0,q=0,t=0;
            memset(r,0,sizeof(r));
            cin>>s;
            for(int i=0; i<12; i++)
            {
                if(s[i]=='X')
                    r[i]=1;
                else r[i]=0;
            }
            for(int i=0; i<12; i++)
            {
                if(r[i]==1)
                    q++;
            }
            if(q==0)
                cout<<0<<endl;
            else if(q!=0)
            {
                a[j].x=1;
                a[j].y=12;
                j++;
                sum++;
                for(int i=0; i<6; i++)
                {
                    if(r[i]==1&&r[i+6]==1)
                    {
                        a[j].x=2;
                        a[j].y=6;
                        j++;
                        sum++;
                        break;
                    }
                }
                for(int i=0; i<4; i++)
                {
                    if(r[i]==1&&r[i+4]==1&&r[i+8]==1)
                    {
                        a[j].x=3;
                        a[j].y=4;
                        j++;
                        sum++;
                        break;
                    }
                }
                for(int i=0; i<3; i++)
                {
                    if(r[i]==1&&r[i+3]==1&&r[i+6]==1&&r[i+9]==1)
                    {
                        a[j].x=4;
                        a[j].y=3;
                        j++;
                        sum++;
                        break;
                    }
                }
                for(int i=0; i<2; i++)
                {
                    if(r[i]==1&&r[i+2]==1&&r[i+4]==1&&r[i+6]==1&&r[i+8]==1&&r[i+10]==1)
                    {
                        a[j].x=6;
                        a[j].y=2;
                        j++;
                        sum++;
                        break;
                    }
                }
                if(q==12)
                {
                    a[j].x=12;
                    a[j].y=1;
                    sum++;
                }
            }

            if(q!=0)
            {
                cout<<sum<<" ";
                for(int k=0; k<sum; k++)
                    cout<<a[k].x<<'x'<<a[k].y<<" ";
                cout<<endl;
            }

        }
    }
    return 0;
}
