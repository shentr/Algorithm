// ACdream1195
//http://acdream.info/problem?pid=1195


#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a[40][40];
int hs[40];

bool is_ok(int n)
{
    int n2=n*n;
    for(int i=0;i<n2;i++)
    {
        memset(hs,0,sizeof(hs));
        for(int j=0;j<n2;j++)
        {
            hs[a[i][j]]++;
        }
        for(int j=1;j<=n2;j++)
        {
            if(hs[j]!=1)
                return false;
        }
    }

    for(int i=0;i<n2;i++)
    {
        memset(hs,0,sizeof(hs));
        for(int j=0;j<n2;j++)
        {
            hs[a[j][i]]++;
        }
        for(int j=1;j<=n2;j++)
        {
            if(hs[j]!=1)
                return false;
        }
    }
    for(int k=0;k<n;k++)
    {
        for(int g=0;g<n;g++)
        {
            memset(hs,0,sizeof(hs));
            for(int i=k*n;i<k*n+n;i++)
            {
                for(int j=g*n;j<g*n+n;j++)
                {
                    hs[a[i][j]]=1;
                }
            }
            for(int i=1;i<=n;i++)
            {
                if(hs[i]!=1)
                    return false;
            }
        }
    }
    return true;
}

int main()
{
    std::ios::sync_with_stdio(false);
    int t;
    int n;
    cin>>t;
    for(int kase=1;kase<=t;kase++)
    {
        cin>>n;
        int flag=0,n2=n*n;
        for(int i=0;i<n2;i++)
        {
            for(int j=0;j<n2;j++)
            {
                cin>>a[i][j];
                if(a[i][j]>n2)
                    flag=1;
            }
        }
        if(flag)
        {
            cout<<"Case #"<<kase<<": No"<<endl;
            continue;
        }
        if(is_ok(n))
            cout<<"Case #"<<kase<<": Yes"<<endl;
        else
            cout<<"Case #"<<kase<<": No"<<endl;
    }
}
