// 1014 ( Uniform Generator )
//acm.hdu.edu.cn/showproblem.php?pid=1014


#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=1e5+5;
bool flag[N];

int main()
{
    int n,m;     //n:step m:mod
    while(cin>>n>>m)
    {
        memset(flag,0,sizeof(flag));
        int a=0;
        while(!flag[a])
        {
            flag[a]=1;
            a=(a+n)%m;
        }
        int flag2=0;
        for(int i=0;i<m;i++)
        {
            if(!flag[i])
            {
                printf("%10d%10d    Bad Choice\n\n",n,m);
                flag2=1;
                break;
            }
        }
        if(!flag2)
            printf("%10d%10d    Good Choice\n\n",n,m);
    }
}
