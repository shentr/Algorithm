// 2955 ( Robberies )
//acm.hdu.edu.cn/showproblem.php?pid=2955


#include<iostream>
#include<cstdio>
#include<cstring>
#define M 105
using namespace std;
struct ss {
    double p;
    int m;
} s[M];
int main() {
    int t, i, j, n, sum[M];
    double dp[M * M], P;
    scanf("%d", &t);
    while (t-- && scanf("%lf %d", &P, &n)) {
        P = 1 - P;
        memset(dp, 0, sizeof (dp));
        dp[0] = 1;
        sum[0] = 0;
        for (i = 1; i <= n; i++) {
            scanf("%d %lf", &s[i].m, &s[i].p);
            s[i].p = 1 - s[i].p;
            sum[i] = sum[i - 1] + s[i].m;
        }
        for (i = 1; i <= n; i++)
            for (j = sum[n]; j >= s[i].m; j--)
                dp[j] = max(dp[j], dp[j - s[i].m] * s[i].p);
        for (j = sum[n]; j >= 1; j--)
            if (dp[j] > P)break;
        printf("%d\n", j);
    }
    return 0;
}
