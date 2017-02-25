// CodeForces754A
//http://codeforces.com/problemset/problem/754A


#include <bits/stdc++.h>

using namespace std;

const int maxn = 105;
int n;
int p[maxn];
int fa[maxn];

int main()
{
    ios::sync_with_stdio(false);
    while(cin>>n){
    int isNum = 0;
    for(int i=0;i<n;i++){
        cin>>p[i];
        if(p[i]) ++isNum;
        fa[i] = i;
    }
    if(n == 1){
        if(p[0]){
            cout<<"YES"<<endl;
            cout<<1<<endl;
            cout<<1<<" "<<1<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
        continue;
    }
    if(isNum == 0) {
        cout<<"NO"<<endl;
        continue;
    }
    int zeroIndex;
    int lastIndex = 0;
    for(int i=0;i<n;i++){
        if(!p[i]){
            zeroIndex = i;
            while(zeroIndex < n){
                fa[zeroIndex] = i;
                if(p[zeroIndex]){
                    lastIndex = zeroIndex;
                    i = zeroIndex;
                    break;
                }
                if(zeroIndex == n-1) {    //找不到了
                    for(int j=lastIndex;j<n;j++){
                        fa[j] = fa[lastIndex];
                    }
                }
                ++zeroIndex;
            }
        }
        else{
            lastIndex = i;
        }
    }
    int k = 0;
    pair <int ,int> res[maxn];
    res[0].first = 0;
    for(int i=1;i<n;i++){
        if(fa[i-1] != fa[i]){
            if(i == n-1){
                res[k++].second = i-1;
                res[k].first = i;
                res[k++].second = i;
                break;
            }
            res[k++].second = i-1;
            res[k].first = i;
        }
        if(i == n-1){
            res[k++].second = i;
        }
    }
    cout<<"YES"<<endl;
    cout<<k<<endl;
    for(int i=0;i<k;i++){
        cout<<res[i].first+1<<" "<<res[i].second+1<<endl;
    }
    }
    return 0;
}
