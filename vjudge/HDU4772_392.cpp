// HDU4772
//http://acm.hdu.edu.cn/showproblem.php?pid=4772


#include"bits/stdc++.h"
using namespace std;
const int N=35;

int main()
{
    int n;
    int a[N][N],b[N][N];
    while(cin>>n&&n)
    {
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>a[i][j];
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>b[i][j];
        int maxn=0,cnt=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(a[i][j]==b[i][j])
                    cnt++;
        maxn=max(maxn,cnt);
        cnt=0;
        /*for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                cout<<b[n-j-1][i]<<' ';
            cout<<endl;
        }*/
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(a[i][j]==b[n-j-1][i])
                    cnt++;
        maxn=max(maxn,cnt);
        cnt=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(a[i][j]==b[n-i-1][n-j-1])
                    cnt++;
        maxn=max(maxn,cnt);
        cnt=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(a[i][j]==b[j][n-i-1])
                    cnt++;
        maxn=max(maxn,cnt);
        cout<<maxn<<endl;
    }
}
