// 2099 ( 整除的尾数 )
//acm.hdu.edu.cn/showproblem.php?pid=2099


#include<iostream>
#include<cstdio>
int main()
{
    using namespace std;
    int a,b,i,c;
    while(cin>>a>>b&&(a||b))
    {
        a*=100;
        for(i=a;i<=a+99;i++)
            {
            if(i%b==0)
            {
            printf("%02d",i-a);
            c=i;
            break;}
            }
        for(i=c+1;i<=a+99;i++)
            {if(i%b==0)
            cout<<' '<<i-a;
            }
            cout<<endl;
    }
    return 0;
}
