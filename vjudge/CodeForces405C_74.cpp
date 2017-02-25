// CodeForces405C
//http://codeforces.com/problemset/problem/405C


#include<iostream>
#include<cstdio>
using namespace std;
bool a[1005][1005];
int as[1000000];
int n;

int matrix_multi()
{
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            ans^=a[i][j]*a[j][i];
        }
    }
    return ans;
}

int main()
{
    while(~scanf("%d",&n))
    {
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
        {
            scanf("%d",&a[i][j]);
        }
        int q,kd,cnt=0;
        int ans=matrix_multi();
        cin>>q;
        while(q--)
        {
            scanf("%d",&kd);
            if(kd==3)
            {
                as[cnt++]=ans;
            }
            int i;
            if(kd==1)
            {
                scanf("%d",&i);
                ans^=1;
            }
            int j;
            if(kd==2)
            {
                scanf("%d",&j);
                ans^=1;
            }
        }
        for(int i=0;i<cnt;i++)
        {
            printf("%d",as[i]);
        }
        cout<<endl;
    }
}
