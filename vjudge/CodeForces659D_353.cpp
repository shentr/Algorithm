// CodeForces659D
//http://codeforces.com/problemset/problem/659D


#include"iostream"
#include"cstdio"
#include"algorithm"
using namespace std;
const int N=1005;

struct point
{
    int x,y;
}p[N];

int main()
{
    cin.sync_with_stdio(false);
    int n;
    while(cin>>n)
    {
        for(int i=0;i<=n;i++)
        {
            cin>>p[i].x>>p[i].y;
        }
        cout<<(n-4)/2<<endl;
    }
}
