// CodeForces225A
//http://codeforces.com/problemset/problem/225A


#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    int n,c,a[105],b[105];
    while(cin>>n)
    {
        int d=0;
        int ans[105];
        memset(ans,0,sizeof(ans));
        cin>>c;
        if(c>3)
        c=7-c;
        for(int i=0;i<n;i++)
        {
            cin>>a[i]>>b[i];
            if(a[i]>3)
            a[i]=7-a[i];
            if(b[i]>3)
            b[i]=7-b[i];
        }
        for(int i=0;i<n;i++)
        {
            if((a[i]==2&&b[i]==3)||(a[i]==3&&b[i]==2))
            ans[i]=1;
            if((a[i]==1&&b[i]==3)||(a[i]==3&&b[i]==1))
            ans[i]=2;
            if((a[i]==1&&b[i]==2)||(a[i]==2&&b[i]==1))
            ans[i]=3;
        }
        for(int i=0;i<n;i++)
        {
            if(ans[i]!=c)
            {cout<<"NO"<<endl;d=1;break;}
        }
        if(d==0)
        cout<<"YES"<<endl;
    }
}
