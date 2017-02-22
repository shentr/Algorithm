// 2058 ( The sum problem )
//acm.hdu.edu.cn/showproblem.php?pid=2058


#include<iostream>
#include<cmath>
int main()
{
        using namespace std;
    int n,m,b,a,k;
    while(cin>>n>>m,n||m)
    {
       b=sqrt(2.0*m);
       for(k=b;k>0;k--)
       {
           a=m/k-(k-1)/2;
           if((2*a-1+k)*k==2*m)
           cout<<"["<<a<<","<<a+k-1<<"]"<<endl;
        }
        cout<<endl;
    }
    return 0;
}