// 2009 ( 求数列的和 )
//acm.hdu.edu.cn/showproblem.php?pid=2009


#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main()
{
    int m;
    double n;
    while(cin>>n>>m)
    {
        double sum=0;
        while(m--)
        {
            sum+=n;
            n=sqrt(n);
        }
        printf("%.2lf\n",sum);
    }
}
