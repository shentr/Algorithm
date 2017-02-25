// HDU5578
//http://acm.hdu.edu.cn/showproblem.php?pid=5578


#include <bits/stdc++.h>

using namespace std;

const int INF = 1005;
struct D{
    bool C;
    int pre;
    int S;
    D(){
        C = false;
        pre = 0;
        S = INF;
    }
};

bool cmp(const D & A,const D & B){
    return A.S < B.S;
}

char p[1005];

int main()
{
    ios::sync_with_stdio(false);
    int T,cnt=0;
    cin>>T;
    while(T--){
        D Hash[30];
        cin>>p;
        int len = strlen(p);
        for(int i=0;i<len;i++){
            if(Hash[ p[i]-'a' ].C){
                if(!Hash[ p[i]-'a' ].S) Hash[ p[i]-'a' ].S = i - Hash[ p[i]-'a' ].pre;
                else Hash[ p[i]-'a' ].S = min(i - Hash[ p[i]-'a' ].pre,Hash[ p[i]-'a' ].S);
            }
            else{
                Hash[ p[i]-'a' ].C = 1;
            }
            Hash[ p[i]-'a' ].pre = i;
        }
        sort(Hash,Hash+27,cmp);
        int vis = 1;
        if(Hash[0].S == INF) vis = 0;
        cout<<"Case #"<<++cnt<<": ";
        if(!vis) cout<<"-1"<<endl;
        else cout<<Hash[0].S<<endl;
    }
    return 0;
}
