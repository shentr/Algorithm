// 5877 ( Weak Pair )
//acm.hdu.edu.cn/showproblem.php?pid=5877


#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define maxn 100010
ll bit[maxn*2], a[maxn], b[maxn*2], ans, K;
int N, n, tot, head[maxn];
bool vis[maxn];
void add(ll bit[], int i, ll x){
    while(i <= n){
        bit[i] += x;
        i += i&-i;
    }
}
ll sum(ll bit[], int i){
    ll s = 0;
    while(i > 0){
        s += bit[i];
        i -= i&-i;
    }
    return s;
}
struct Edge{
    int to, next;
}edge[maxn];
void addedge(int u, int v){
    edge[tot].to = v;
    edge[tot].next = head[u];
    head[u] = tot++;
}
void dfs(int now){
    vis[now] = 1;
    //printf("%d ", now);
    ll loc1, loc2;
    if(a[now] == 0) loc1 = 0;
    else {
        ll point = K/a[now];
        //printf("%I64d ", point);
        loc1 = lower_bound(b, b+n, point)-b+1;
        //cout<<endl<<now<<' '<<point<<' '<<lower_bound(b, b+n, point)<<endl;
    }
    loc2 = lower_bound(b, b+n, a[now])-b+1;
    //printf("%I64d\n", sum(bit, loc1));
    ans += sum(bit, loc1);
    add(bit, loc2, 1);
    for(int i = head[now];i != -1;i = edge[i].next){
        int son = edge[i].to;
        if(vis[son]) continue;
        dfs(son);
    }
    add(bit, loc2, -1);
}

int main()
{
    int i, T, top;
    scanf("%d", &T);
    while(T--){
        scanf("%d %I64d", &N, &K);
        top = 0;
        for(i = 1;i <= N;i++){
            scanf("%I64d", &a[i]);
            b[top++] = a[i];
            if(a[i] != 0) b[top++] = K/a[i];
        }
        sort(b, b+top);
        n = unique(b, b+top)-b;
        //for(int i=0;i<n;i++)
           // cout<<b[i]<<' ';
        int u, v;
        memset(head, -1, sizeof head);
        memset(bit, 0, sizeof bit);
        memset(vis, 0, sizeof vis);
        tot = 0;
        ans = 0;
        for(i = 0;i < N-1;i++){
            scanf("%d %d", &u, &v);
            addedge(u, v);
            vis[v] = 1;
        }
        int start;
        for(i = 1;i <= N;i++)
            if(!vis[i]){
                start = i;
                break;
            }
        memset(vis, 0, sizeof vis);
        dfs(start);
        printf("%I64d\n", ans);
    }
}
/*1
6 3
4 6 3 9 4 2
4 6
3 6
6 9
4 3
2 4*/
