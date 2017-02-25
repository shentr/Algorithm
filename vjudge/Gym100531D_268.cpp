// Gym100531D
//undefined100531D


#include"bits/stdc++.h"
using namespace std;

int solve(int x)
{
    int sum = 0;
    while(x)
    {
        sum += (x%10);
        x/=10;
    }
    return sum;
}
map<int,long long>ans,vis,sum;

int main()
{
    freopen("digits.in","r",stdin);
    freopen("digits.out","w",stdout);
    //ofstream fout("f://digits.out");
    for(int i=1;i<=100000;i++)
    {
        int k = solve(i);
        vis[k]++;
        sum[k]+=i;
        if(ans[vis[k]]==0)
            ans[vis[k]]=sum[k];
        else
            ans[vis[k]]=min(ans[vis[k]],sum[k]);
    }
    int n;
    while(cin>>n)
        cout<<ans[n]<<endl;
    //for(int i=1;i<=5000;i++)
        //fout<<ans[i]<<',';

}
