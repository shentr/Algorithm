// 2053 ( Switch Game )
//acm.hdu.edu.cn/showproblem.php?pid=2053


#include<iostream>
int c;
void yinzi(int a)
{
    int i;
    c=0;
    for(i=1;i<=a;i++)
        if(a%i==0)
            c++;
}
int main()
{
    using namespace std;
    void yinzi(int a);
    int n;
    while(cin>>n)
    {
        yinzi(n);
        if(c%2==0)
            cout<<'0'<<endl;
        else
            cout<<'1'<<endl;
    }
    return 0;
}

