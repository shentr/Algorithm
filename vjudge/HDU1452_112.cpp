// HDU1452
//http://acm.hdu.edu.cn/showproblem.php?pid=1452


#include<iostream>
using namespace std;
int a[]={6,16,8,10,25,7,14,3,23,17,13,17,0,27,7,14,15,17,26,26,20,17,9,22,22,23,0,1};

int main()
{
    int x;
    while(cin>>x&&x)
    {
        cout<<a[(x-1)%28]<<endl;
    }
    /*for(x=1;x<=100;x++)
    {
        int a2=1,a3=1,a167=1,ans2=0,ans3=0,ans167=0;
        for(int i=0;i<=x*2;i++)
        {
            ans2+=a2;
            a2*=2;
            ans2%=29;
            a2%=29;
        }
        for(int i=0;i<=x;i++)
        {
            ans3+=a3;
            a3*=3;
            ans3%=29;
            a3%=29;
        }
        for(int i=0;i<=x;i++)
        {
            ans167+=a167;
            a167*=167;
            ans167%=29;
            a167%=29;
        }
        cout<<ans2*ans3*ans167%29<<endl;
    }*/
    return 0;
}
