// CodeForces390C
//http://codeforces.com/problemset/problem/390C


#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=1e5+10;
bool a[N];
int b[15][N],c[N];

int main()
{
    int n,k,w;
    while(cin>>n>>k>>w)
    {
        memset(b,0,sizeof(b));
        memset(c,0,sizeof(c));
        for(int i=0;i<n;i++)
            scanf("%1d",&a[i]);
        for(int i=1;i<=k;i++)
        {
            b[i%k][i]=a[i-1];
            c[i]+=(c[i-1]+a[i-1]);
        }
        for(int i=k+1;i<=n;i++)
        {
            c[i]+=(c[i-1]+a[i-1]);
            b[i%k][i]+=b[i%k][i-k];
            if(a[i-1]!=0)
                b[i%k][i]+=1;
        }
        while(w--)
        {
            int l,r,ans;
            scanf("%d%d",&l,&r);
            ans=(c[r]-c[l-1])+(r+1-l)/k-2*(b[r%k][r]-b[r%k][l-1]);
            printf("%d\n",ans);
        }
    }
}
