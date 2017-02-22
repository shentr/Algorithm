// 5523 ( Game )
//acm.hdu.edu.cn/showproblem.php?pid=5523


#include<iostream>
using namespace std;

int main()
{
    int n,s,t;
    while(cin>>n>>s>>t)
    {
        if(s==t&&n!=1)
            cout<<-1<<endl;
        else if((s==1&&t==n)||(s==n&&t==1)||n==1)
            cout<<0<<endl;
        else if((s==t+1)||(t==s+1)||(s==1&&t!=n)||(s==n&&t!=1))
            cout<<1<<endl;
        else
        cout<<2<<endl;
    }
}
