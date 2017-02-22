// 2081 ( 手机短号 )
//acm.hdu.edu.cn/showproblem.php?pid=2081


#include<iostream>
int main()
{
    using namespace std;
    int N,i;
    char a[11];
    cin>>N;
    while(N--)
    {
        for(i=0;i<11;i++)
        {
            cin>>a[i];
        }
        cout<<'6';
        for(i=6;i<11;i++)
        {
            cout<<a[i];
        }
        cout<<endl;
    }
    return 0;
}
