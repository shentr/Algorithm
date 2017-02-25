// HDU3835
//http://acm.hdu.edu.cn/showproblem.php?pid=3835


#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int n;
    while(cin>>n)
    {
        int count=0;
        for(int i=1;i*i<=n;i++)
        {
            int x=n-i*i;
            if(ceil(sqrt(x))*ceil(sqrt(x))==x)
            count++;
        }
        cout<<count*4<<endl;}
}
