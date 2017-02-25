// FZU2147
//http://acm.fzu.edu.cn/problem.php?pid=2147


#include <iostream>

using namespace std;

int main()
{
    int T;
    long long a,b;
    cin>>T;
    long long k=0;
    while(T--)
    {
        long long sum=0;
        cin>>a>>b;
        while(a>b)
        {
            a-=(a+1)/2-1;
            sum++;
        }
        cout<<"Case "<<++k<<": ";
        cout<<sum<<endl;
    }
    return 0;
}
