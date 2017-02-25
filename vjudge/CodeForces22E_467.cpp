// CodeForces22E
//http://codeforces.com/problemset/problem/22E


#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
const int maxn=100005;
int in[maxn],col[maxn];
vector<int>s[maxn],b,e;
int dfs(int p)
{
    col[p]=1;
    int v=s[p][0];
    if(!col[v])
        return col[p]=dfs(v);
    else return col[p]=p;
}
int main()
{
    int a,n;
    ios::sync_with_stdio(false);
    while(cin>>n)
  // cin>>n;
    {
        memset(in,0,sizeof(in));
        memset(col,0,sizeof(col));
        for(int i=1; i<=n; i++)
        {
            cin>>a;
            in[a]++;
            s[i].push_back(a);
        }
        int k=0;
        for(int i=1; i<=n; i++)
        {
            if(!in[i])
            {
                b.push_back(i);
                e.push_back(dfs(i));
                k++;
            }
        }
        int t=k;
        for(int i=1; i<=n; i++)
        {
            if(!col[i])
            {
                b.push_back(i);
                e.push_back(dfs(i));
                ++k;
            }
        }
        if(k==1&&t==0)//刚开始谁都没染色，如果成环的话，那么只染色一次，k=1，并且t=0，因为入度没有为0的
        {
            k=0;
        }
        cout<<k<<endl;
        for(int i=0; i<k; i++)
            cout<<e[i]<<" "<<b[(i+1)%k]<<endl;
           /* for(int i=1;i<=n;i++)
            {
                s[i].clear();
            }
            e.clear();
            b.clear();*/
    }
    return 0;
}
