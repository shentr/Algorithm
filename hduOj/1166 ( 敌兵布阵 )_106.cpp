// 1166 ( 敌兵布阵 )
//acm.hdu.edu.cn/showproblem.php?pid=1166


#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn = 55555;
int sum[maxn << 2];//按位左偏一位相当于乘以2，偏移2位相当于乘以2的平方
void PushUp(int rt)
{
    sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];//这个按位或就是+1的意思
}

void build(int l, int r, int rt)//建立线段树
{
    if (l == r)
    {
        scanf("%d", &sum[rt]);
        return;
    }
    int m = (l + r) >> 1;//按位右偏1位相当于除以2
    build(l, m, rt << 1);
    build(m + 1, r, rt << 1 | 1);
    PushUp(rt);
}

void update(int p, int add, int l, int r, int rt)
{
    if (l == r)
    {
        sum[rt] += add;
        return;
    }
    int m = (l + r) >> 1;
    if (p <= m) update(p, add, l, m, rt << 1);
    else update(p, add, m + 1, r, rt << 1 | 1);
    PushUp(rt);
}

int query(int ll, int rr, int l, int r, int rt)//查询线段树
{
    if (ll <= l && rr >= r) return sum[rt];
    int m = (l + r) >> 1;
    int ret = 0;
    if (ll <= m) ret += query(ll, rr, l, m, rt << 1);
    if (rr > m) ret += query(ll, rr, m + 1, r, rt << 1 | 1);
    return ret;
}

int main()
{
    int t, c;
    char d[10];
    scanf("%d", &t);
    for (c = 1; c <= t; c++)
    {
        printf("Case %d:\n", c);
        int n;
        scanf("%d", &n);
        build(1, n, 1);
        while (scanf("%s", d) != EOF)
        {
            if (d[0] == 'E') break;
            int x, y;
            scanf("%d%d", &x, &y);
            if (d[0] == 'Q')
            {
                int ans = query(x, y, 1, n, 1);
                printf("%d\n", ans);
            }
            if (d[0] == 'S') update(x, -y, 1, n, 1);
            if (d[0] == 'A') update(x, y, 1, n, 1);
        }
    }
    return 0;
}
