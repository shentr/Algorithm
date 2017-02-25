// HDU2082
//http://acm.hdu.edu.cn/showproblem.php?pid=2082


#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
long long a[60],b[60];

int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        a[0]=1;
        int x;
        for(int i=1;i<=26;i++)
        {
            scanf("%d",&x);
            for(int j=0;j<=50;j++)
            {
                for(int k=0;k<=x&&(j+k*i<=50);k++)
                {
                    b[j+k*i]+=a[j];
                }
            }
            for(int j=0;j<=50;j++)
            {
                a[j]=b[j];
                b[j]=0;
            }
        }
        long long ans=0;
        for(int i=1;i<=50;i++)
            ans+=a[i];
        cout<<ans<<endl;
    }
}
