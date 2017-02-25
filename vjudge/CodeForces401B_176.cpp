// CodeForces401B
//http://codeforces.com/problemset/problem/401B


#include <iostream>
#include <string.h>
using namespace std;
int b[4005],c[4005];
int x,k,a1,s1,s2,s3;
int main()
{
    while(cin>>x>>k)
    {
        memset(b,0,sizeof(c));
        memset(c,0,sizeof(c));
        int sum=0,t=1,num=0;
        for(int i=1; i<=k; i++)
        {
            cin>>a1;
            if(a1==2)
            {
                cin>>s1;
                b[s1]=1;
            }
            else
            {
                cin>>s2>>s3;
            b[s2]=1;
            b[s3]=1;
            }
        }
        for(int i=1;i<x;i++)
            if(b[i]!=1)
            {

                c[t]=i;
                t++;
                num++;
            }
           // cout<<t<<endl;
          //   for(int j=1;j<t;j++)
          //  cout<<c[j]<<"  ";
        for(int j=1;j<t;j++)
        {
            if(c[j+1]-c[j]==1)
               {
                   j++;
               }
                sum++;
        }
        cout<<sum<<" "<<num<<endl;
    }
        return 0;
    }
