// CodeForces589J
//http://codeforces.com/problemset/problem/589J


#include<bits/stdc++.h>
#define LL long long
#define P pair<int,int>
#define X first
#define Y second
#define pb push_back
#define cl(a,b) memset(a,b,sizeof(a));

using namespace std;

const int maxn=113;
const int inf=1<<27;
int n,m;
int si,sj;
char a[maxn][maxn];
int vis[maxn][maxn];
bool pan(int x,int y){
    if(x<0||x>=n||y<0||y>=m||a[x][y]=='*'||vis[x][y]>4)return false;
    return true;
}

struct node{
    int x,y;
    char dir;
    node(int a,int b,char c){
        x=a;y=b;dir=c;
    }
    node(){}
};
void bfs(){
    queue<node> q;
    cl(vis,0);
    q.push(node(si,sj,a[si][sj]));
    vis[si][sj]=1;
    while(!q.empty()){
        node t=q.front();q.pop();
        int x=t.x,y=t.y;
        char dir=t.dir;
        if(vis[x][y]>4)break;
        if(dir=='U'){
            if(pan(x-1,y)){
                q.push(node(x-1,y,'U'));
                vis[x-1][y]++;
            }
            else {
                q.push(node(x,y,'R'));
                vis[x][y]++;
            }
        }
        if(dir=='D'){
            if(pan(x+1,y)){
                q.push(node(x+1,y,'D'));
                vis[x+1][y]++;
            }
            else {
                q.push(node(x,y,'L'));
                vis[x][y]++;
            }
        }
        if(dir=='L'){
            if(pan(x,y-1)){
                q.push(node(x,y-1,'L'));
                vis[x][y-1]++;
            }
            else {
                q.push(node(x,y,'U'));
                vis[x][y]++;
            }
        }
        if(dir=='R'){
            if(pan(x,y+1)){
                q.push(node(x,y+1,'R'));
                vis[x][y+1]++;
            }
            else {
                q.push(node(x,y,'D'));
                vis[x][y]++;
            }
        }

    }
}
int main(){

    while(~scanf("%d%d",&n,&m)){
        for(int i=0;i<n;i++){
            scanf("%s",a[i]);
            for(int j=0;j<m;j++){
                if(isalpha(a[i][j])){
                    si=i;sj=j;
                }
            }
        }
        bfs();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)if(vis[i][j])ans++;
        }
        printf("%d\n",ans);

    }
    return 0;
}
