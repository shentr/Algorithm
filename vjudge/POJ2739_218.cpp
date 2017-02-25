// POJ2739
//http://poj.org/problem?id=2739


#include <iostream>
#include <stdio.h>
using namespace std;
int s[1235];
void sushu()
{
    int k=1;
    bool num[10005];
    for(int i=1; i<=10000; i++)
        num[i]=1;
    for(int i=2; i<=10000; i++)
    {
        if(num[i])
        {
            for(int j=i*i; j<=10000; j+=i)
                num[j]=0;
        }
    }
    for(int i=2; i<=10000; i++)
    {
        if(num[i])
            {
                s[k]=i;
                k++;
            }

    }//cout<<k<<endl;
}
int main()
{
    int x;
    sushu();
    while(scanf("%d",&x)!=EOF)
    {
        if(x==0)
            break;
        int sum=0,sum2=0,j=1,k=1;
        while(k<=1229&&sum<x)
        {
                while(sum<x)
                {
                    sum+=s[j];
                     j++;
                }
                 if(sum==x)
                {
                    sum2++;
                    k++;
                    j=k;
                    sum=0;
                    continue;
                }
                else if(sum>x)
                {
                   k++;
                   j=k;
                   sum=0;
                   continue;
               }
        }
        printf("%d\n",sum2);
    }
    return 0;
}
