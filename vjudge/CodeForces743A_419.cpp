// CodeForces743A
//http://codeforces.com/problemset/problem/743A


#include <iostream>

using namespace std;
string s;
int n,a,b;
int main()
{
    while(cin>>n>>a>>b)
    {
        cin>>s;
        if(s[a-1]==s[b-1])
            cout<<0<<endl;
        else cout<<1<<endl;
        s.clear();
    }
    return 0;
}
