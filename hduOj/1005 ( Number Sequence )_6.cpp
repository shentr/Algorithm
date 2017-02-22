// 1005 ( Number Sequence )
//acm.hdu.edu.cn/showproblem.php?pid=1005


#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    int a,b,n;
    int f[55],flaga[10][10];
    while(cin>>a>>b>>n&&(a||b||n))
    {
        memset(flaga,0,sizeof(flaga));
        f[1]=1;f[2]=1;
        int xhj=1;                    //循环节
        int af,bf;
        for(int i=3;i<=n;i++)
        {
            af=a*f[i-1]%7,bf=b*f[i-2]%7;
            f[i]=(af+bf)%7;
            if(flaga[af][bf]==1)
            {
                xhj=i;     //循环节
                break;
            }
            flaga[af][bf]=1;
        }
        int xhjb=3;
        for(int i=3;i<=n;i++)
        {
            if(af==a*f[i-1]%7&&bf==b*f[i-2]%7)
            {
                xhjb=i;
                break;
            }
        }
        if(n>=xhjb)
            cout<<f[(n-xhjb)%(xhj-xhjb)+xhjb]<<endl;
        else
            cout<<f[n]<<endl;
    }
}

