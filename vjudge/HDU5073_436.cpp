// HDU5073
//http://acm.hdu.edu.cn/showproblem.php?pid=5073


#include <bits/stdc++.h>
using namespace std;
const int maxn = 50005;
double p[maxn];

int main()
{
    int T;
    scanf("%d",&T);
    while(T--){
        int n,k;
        scanf("%d%d",&n,&k);
        int t = n-k;
        for(int i=0;i<n;i++){
            scanf("%lf",&p[i]);
        }
        if(t==0)
        {
            printf("0.0\n");
            continue;
        }
        sort(p,p+n);
        double ans;
        double sum = 0.0;
        double sumf = 0.0;
        for(int i=0;i<t;i++){
            sum += p[i];
            sumf += p[i] * p[i];
        }
        double pj = sum / (double)t;
        ans = sumf-2*pj*sum+pj*pj*(double)t;
        for(int i=t;i<n;i++){
            sum += p[i];
            sum -= p[i-t];
            sumf += p[i] * p[i];
            sumf -= p[i-t] * p[i-t];
            double pj = sum / (double)t;
            ans = min(ans, sumf-2.0*pj*sum+pj*pj*(double)t);
        }
        printf("%.12lf\n",ans);
    }
    return 0;
}
