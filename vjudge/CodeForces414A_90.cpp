// CodeForces414A
//http://codeforces.com/problemset/problem/414A


#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

int main()
{
    int n,k;
    while(cin>>n>>k)
    {
        if(n==1&&k==0)
        {
            cout<<1<<endl;
            continue;
        }
        if((n==1&&k!=0)||n/2>k)
        {
            cout<<-1<<endl;
            continue;
        }
        else
        {
            int num=n/2,ii=1;
            int a1=k-num+1,a2=(k-num+1)*2;
            printf("%d %d",k-num+1,(k-num+1)*2);
            num--;
            while(num>0)
            {
                if((ii!=a1&&ii!=a2)&&(ii+1!=a1&&ii+1!=a2)&&(ii-1!=a1&&ii-1!=a2))
                {
                    printf(" %d %d",ii,ii+1);
                    num--;
                }
                ii+=2;
            }
            if((n&1)&&(ii!=a1&&ii!=a2))
                cout<<" "<<ii;
            if((n&1)&&(ii==a1||ii==a2))
                cout<<" "<<ii+2;
            cout<<endl;
        }
    }
}
