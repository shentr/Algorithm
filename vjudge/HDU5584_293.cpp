// HDU5584
//http://acm.hdu.edu.cn/showproblem.php?pid=5584


#include <bits/stdc++.h>

using namespace std;

long long gcd(int a,int b){
    return b == 0 ? a : gcd(b,a%b);
}

long long lcm(int a,int b){
    return a*b/gcd(a,b);
}

int main()
{
    ios::sync_with_stdio(false);
    int T,cnt=0;
    cin>>T;
    while(T--){
        int ex,ey;
        cin>>ex>>ey;
        int maxa = max(ex,ey);
        int maxb = min(ex,ey);
        int Count = 1;
        while(true){
            if(maxa % (maxb + gcd(maxa,maxb))) break;
            int temp = 1+maxb/gcd(maxa,maxb);
            int sx = maxa/temp;
            int sy = maxb;
            ++Count;
            maxa = max(sx,sy);
            maxb = min(sx,sy);
        }
        cout<<"Case #"<<++cnt<<": ";
        cout<<Count<<endl;;
    }
    return 0;
}
