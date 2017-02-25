// POJ1321
//http://poj.org/problem?id=1321


//#include "bits/stdc++.h"
#include "iostream"
#include "cstring"
using namespace std;
const int maxn=10;
bool visi[maxn],visj[maxn];
char ch[maxn][maxn];
int vi[maxn],vj[maxn],count,n,k;

void dfs(int cnt){
    if(cnt==k) {
        count++;
        /*for(int i=0;i<cnt;i++){
            cout<<"("<<a[i]<<","<<b[i]<<")";
        }*/
        return ;
    }
    for(int i=vi[cnt-1];i<n;i++){                             ///avoid duplicate(重复) answers
        for(int j=0;j<n;j++){
            if(!visi[i] && !visj[j] && ch[i][j]=='#'){
                visi[i]=true,visj[j]=true;
                vi[cnt]=i,vj[cnt]=j;
               // cout<<cnt<<" "<<a[cnt]<< " "<<b[cnt]<<"---------";
                dfs(cnt+1);
                visi[i]=false,visj[j]=false;
               // cout<<cnt<<" "<<a[cnt]<< " "<<b[cnt]<<"+++++++++";
            }
        }
    }
}

int main() {
    while(cin>>n>>k && (n>-1&&k>-1)){
        count=0;
        memset(visi,false,sizeof(visi));
        memset(visj,false,sizeof(visj));
        /*memset(vi,0,sizeof(vi));
        memset(vj,0,sizeof(vj));
        vi[-1]=0,vj[-1]=0;*/
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>ch[i][j];
            }
        }
        dfs(0);
        cout<<count<<endl;
    }
}

/*
4 3
#..#
.#.#
####
#.#.

2 1
##
##

3 3
###
###
###
 **/
