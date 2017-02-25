// POJ2492
//http://poj.org/problem?id=2492


#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 2000;
int pre[MAX+5];
int relroot[MAX+5];
bool mark;

void init(int n){
    int i;
    for(i=1;i<=n;++i){
        pre[i] = i;
        relroot[i] = 0;
    }
    mark = true;
}

int root(int x){
    int px;
    if(x!=pre[x]){
        px = pre[x];
        pre[x] = root(pre[x]);
        relroot[x] = (relroot[px] + relroot[x])%2;
    }
    return pre[x];
}

void merge(int x,int y){
    int fx = root(x);
    int fy = root(y);

    if(fx!=fy){
        pre[fx] = fy;
        relroot[fx] = (1 + relroot[y] - relroot[x])%2;
    }
    root(x);
}

int main(){
    int t,i,n,m,x,y,k;
    scanf("%d",&t);
    for(i=1;i<=t;++i){
        scanf("%d %d",&n,&m);
        init(n);
        for(k=1;k<=m;++k){
            scanf("%d %d",&x,&y);
            if(mark){
                merge(x,y);
            }
            if(relroot[x]==relroot[y]){
                mark = false;
            }
        }
        printf("Scenario #%d:\n",i);
        if(mark){
            printf("No suspicious bugs found!\n");
        }else{
            printf("Suspicious bugs found!\n");
        }
        printf("\n");
    }
    return 0;
}
