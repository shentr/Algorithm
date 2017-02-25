// CodeForces404A
//http://codeforces.com/problemset/problem/404A


#include<iostream>
#include<cstdio>
using namespace std;
const int N=310;

int main()
{
    int n;
    char a[N][N];
    while(cin>>n)
    {
        getchar();
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                scanf("%c",&a[i][j]);
            }
            getchar();
        }
        int flag=0;
        for(int i=1;i<=n;i++)
        {
         for(int j=1;j<=n;j++)
        {
            if(((i==j)&&(a[i][j]!=a[1][1]))||((i+j==n+1)&&(a[i][j]!=a[1][1]))||(a[1][1]==a[1][2]))
            {
                flag=1;
                break;
            }
            if((i!=j)&&((i+j)!=n+1)&&a[i][j]!=a[1][2])
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
                break;
        }
        if(flag==1)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
    }
}

