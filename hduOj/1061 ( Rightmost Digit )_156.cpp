// 1061 ( Rightmost Digit )
//acm.hdu.edu.cn/showproblem.php?pid=1061


#include<iostream>
#include<cmath>
int main()
{
    using namespace std;
    int n,t,ans;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int mo=(n-1)%4+1;
        ans=pow(n%10,mo);
        ans=ans%10;
        cout<<ans<<endl;
    }
    return 0;
}

