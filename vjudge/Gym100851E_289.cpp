// Gym100851E
//undefined100851E


#include"bits/stdc++.h"
using namespace std;
int a[55][55];
int n,k,m;
int main()
{
    freopen("easy.in","r",stdin);
    freopen("easy.out","w",stdout);
    cin>>n>>k;
        for(int i=0;i<=50;i++)
            for(int j=0;j<=50;j++)
                a[i][j]=50;
        int p;
        for(int i=1;i<=n;i++)
        {
            cin>>m;
            for(int j=1;j<=m;j++)
            {
                cin>>p;
                a[i][j]=p;
            }
        }
        int sum=0,cnt=0;
        for(int i=1;i<50;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(a[j][i]>=sum||a[j][i]==50)
                {
                    sum+=a[j][i];
                    cnt++;
                }
                if(cnt==k)
                {
                    cout<<sum<<endl;
                    return 0;
                }
            }
    }
    return 0;
}
