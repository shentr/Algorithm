// ACdream1408
//http://acdream.info/problem?pid=1408


#include"iostream"
#include"cstdio"
#include"cstring"
using namespace std;

int main()
{
    long long n;
    while(cin>>n)
    {
        if(n%2==1)
            cout<<2<<' '<<2+n<<endl;
        else
            cout<<0<<' '<<0<<endl;
    }
}
