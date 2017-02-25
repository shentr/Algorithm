// HDU4950
//http://acm.hdu.edu.cn/showproblem.php?pid=4950


#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    long long a,b,k,h;
    int cases=0;
    while(cin>>h>>a>>b>>k)
    {
        if(h==0&&a==0&&b==0&&k==0)
            break;
        cout<<"Case #"<<++cases<<": ";
        if(a*k-b*(k+1)>0)
            cout<<"YES"<<endl;
            else if(a*k-b*k>=h)
                 cout<<"YES"<<endl;
            else if(a>=h)
                cout<<"YES"<<endl;
                else if(a*k -b*(k-1)>=h)
                    cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}