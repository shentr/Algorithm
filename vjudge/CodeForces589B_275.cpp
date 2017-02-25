// CodeForces589B
//http://codeforces.com/problemset/problem/589B


#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;

const int maxn=100100;
typedef long long LL;
typedef pair <LL,LL> P;
P a[maxn];

int main()
{
    ios::sync_with_stdio(false);
    LL n;
    cin>>n;
    for (LL i = 0; i < n; ++i)
    {
        cin>>a[i].x>>a[i].y;
        if (a[i].x < a[i].y) a[i].x ^= a[i].y ^= a[i].x ^= a[i].y;//交换
    }
    sort(a, a + n);//排序

    LL ans = 0, num1, num2;
    for (LL i = 0; i < n; ++i)//枚举长
    {
        LL l = 0;
        LL b[maxn/20];//放宽的数组
        for (LL j = i; j < n; ++j)
        {
            b[l++] = a[j].y;
        }
        sort(b, b + l);//排序
        for (LL j = 0; j < l; ++j)//枚举宽
        {
            if (ans < (l - j) * a[i].x * b[j])//计算体积，更新
            {
                ans = (l - j) * a[i].x * b[j];
                num1 = a[i].x;
                num2 = b[j];
            }
        }
    }
    cout<<ans<<"\n"<<num1<<" "<<num2<<endl;
    return 0;
}
