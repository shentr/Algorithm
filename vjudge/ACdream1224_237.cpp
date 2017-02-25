// ACdream1224
//http://acdream.info/problem?pid=1224


#include <iostream>
#include<cstdio>
using namespace std;
const int N=1e4+5;
int k[N], x[N];
bool flag[N];

int main()
{
    int n, m, y, sum;
    while(cin>>n>>m>>y)
    {
        sum = 0;
        for(int i=0; i<n; i++)
        {
            cin>>x[i];
            k[i] = m * x[i] / y;
            if(m * x[i] % y == 0) flag[i] = true;
            sum += k[i];
        }
        int tx = m - sum;
        while(tx--)
        {
            double t = 0;
            int j = 0;
            for(int i=0; i<n; i++)
            {
                if(flag[i])
                    continue;
                double foo = (double)x[i]/y - (double)k[i]/m;
                if(t < foo)
                {
                    t = foo;
                    j = i;
                }
            }
            k[j] ++;
        }
        for(int i=0; i<n-1; i++)
            printf("%d ", k[i]);
        printf("%d\n", k[n-1]);
    }
}
