// CodeForces677A
//http://codeforces.com/problemset/problem/677A


#include<bits\stdc++.h>
using namespace std;

int main()
{
     int n,h,x;
     int ans = 0;
     cin >> n >> h;
     for(int i = 1;i<=n;i++)
     {
         cin >> x;
         if(x<=h)
             ans+=1;
         else
             ans+=2;
     }
     cout << ans << endl;
}
