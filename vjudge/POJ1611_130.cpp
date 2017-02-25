// POJ1611
//http://poj.org/problem?id=1611


#include<iostream>
#include<cstdio>
using namespace std;
int pre[30010];

void init(int n)
{
    for(int i=0;i<n;i++)
        pre[i]=i;
}

int find(int a)
{
    int r=a;
    while(r!=pre[r])
        r=pre[r];
    int i=a;
    while(pre[i]!=r)
    {
        int j=pre[i];
        pre[i]=r;
        i=j;
    }
    return r;
}

void join(int a,int b)
{
    int fa=find(a),fb=find(b);
    if(fa!=fb)
        pre[fb]=fa;
}

int main()
{
    int n,m,a,k;
    while(cin>>n>>m&&(n||m))
    {
        init(n);
        while(m--)
        {
            cin>>k;
            cin>>a;
            int pr=a;
            for(int i=1;i<k;i++)
            {
                cin>>a;
                join(pr,a);
                pr=a;
            }
        }
        int ans=0,f=find(0);
        for(int i=0;i<n;i++)
        {
            if(find(i)==f)
                ans++;
        }
        cout<<ans<<endl;
    }
}
