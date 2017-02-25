// FZU1327
//http://acm.fzu.edu.cn/problem.php?pid=1327


#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
long long a[20005];
struct cmp
{
    bool operator()(long long x,long long y)
    {
        return x>y;
    }
};
int n;
int main()
{
    while(cin>>n)
    {
        memset(a,0,sizeof(a));
        long long sum=0;
        priority_queue<long long,vector<long long>,cmp>q;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            q.push(a[i]);
        }
        while(q.size()>1)
        {
            long long x=q.top();
            q.pop();
            long long y=q.top();
            q.pop();
            sum+=x+y;
            q.push(x+y);
        }
        cout<<sum<<endl;
    }
    return 0;
}
