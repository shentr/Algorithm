// HDU1568
//http://acm.hdu.edu.cn/showproblem.php?pid=1568


#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n,i,s;
    double y;
    int f[100];
    while(cin>>n)
    {
        f[0]=0;
        f[1]=1;
        for(i=2;i<=20;i++)
        f[i]=f[i-1]+f[i-2];
       if(n<=20)
       cout<<f[n]<<endl;
       else
       {
        y=log10(1/sqrt(5))+n*log10((1+sqrt(5))/2)+4-(int)(log10(1/sqrt(5))+n*log10((1+sqrt(5))/2)+1);
        s=(int)(pow(10,y));
        cout<<s<<endl;
       }
    }
    return 0;
}
