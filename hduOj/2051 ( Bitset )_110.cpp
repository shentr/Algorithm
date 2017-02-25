// 2051 ( Bitset )
//acm.hdu.edu.cn/showproblem.php?pid=2051


#include<iostream>
#include<cstdio>
int main()
{
    using namespace std;
    int ten,a[10000],i,c;
    while(cin>>ten)
    {
        i=0;
        for(i=0;ten!=0;i++)
        {
          a[i]=ten%2;
          ten=ten/2;
          c=i;
        }
        for(i=c;i>=0;i--)
            cout<<a[i];
            cout<<endl;
    }
    return 0;
}
