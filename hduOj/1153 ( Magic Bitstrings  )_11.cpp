// 1153 ( Magic Bitstrings  )
//acm.hdu.edu.cn/showproblem.php?pid=1153


#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=100000;
bool a[maxn];

int main()
{
    int n;
    while(~scanf("%d",&n)&&n)
    {
        if(n==2)
        {
            printf("Impossible\n");
            continue;
        }
        memset(a,0,sizeof(a));
        for(long long i=1;i<=n/2+1;i++)
        {
            a[i*i%n]=1;
        }
        for(int i=1;i<n;i++)
        {
            if(a[i])
                printf("0");
            else
                printf("1");
        }
        printf("\n");
    }
    return 0;
}
