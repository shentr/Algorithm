// POJ1321
//http://poj.org/problem?id=1321


//#include "bits/stdc++.h"
#include "iostream"
#include "cstring"
using namespace std;
bool visi[20],visj[20];
char ch[20][20];
int a[20],b[20],count,n,k;

void dfs(int cnt){
    if(cnt==k) {
        count++;
        /*for(int i=0;i<cnt;i++){
            cout<<"("<<a[i]<<","<<b[i]<<")";
        }*/
        return ;
    }
    for(int i=a[cnt-1];i<n;i++){
        for(int j=0;j<n;j++){
            if(!visi[i] && !visj[j] && ch[i][j]=='#'){
                visi[i]=true,visj[j]=true;
                a[cnt]=i,b[cnt]=j;
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
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        a[-1]=0,b[-1]=0;
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
