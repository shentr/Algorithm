// ACdream1220
//http://acdream.info/problem?pid=1220


#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
struct cmp
{
    bool operator()(long long x,long long y)
    {
        return x>y;
    }
};
priority_queue<long long,vector<long long>,cmp>q;
long long sum[500005];
int main()
{
    int n;
    long long a,x,y;
    ios::sync_with_stdio(false);
    while(cin>>n)
    {
        memset(sum,0,sizeof(sum));
        while(!q.empty())
            q.pop();
        long long ans=0;
        for(int i=1; i<=n; i++)
        {
            cin>>a;
            q.push(a);
        }
        int k=0;
        long long c=0;
//        bool flag=0;
        while(!q.empty())
        {
            if(q.size()==1)
            {
//                if(n==1)
//                    flag=1;
                c=q.top();
                //cout<<c<<endl;
                break;
            }
            else
            {
                long long x=q.top();
                q.pop();
                long long y=q.top();
                q.pop();
                sum[++k]=x+y;
                q.push(x+y);
            }
        }
//        if(flag==1)
//            cout<<c<<endl;
//        else
//        {
            for(int i=1; i<=k; i++)
                ans+=sum[i];
            cout<<ans<<endl;
       // }
    }
    return 0;
}
