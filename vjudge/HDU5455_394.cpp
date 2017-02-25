// HDU5455
//http://acm.hdu.edu.cn/showproblem.php?pid=5455


#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6+10;
char p[maxn];
int jl[maxn];

int main()
{
    ios::sync_with_stdio(false);
    int T,cnt=0;
    cin>>T;
    while(T--){
        cin>>p;
        int len = strlen(p);
        cout<<"Case #"<<++cnt<<": ";
        int Count = 0;
        int vis = false;
        for(int i=0;i<len;i++){
            if(p[i]=='c') jl[Count++] = i;
            if(p[i] != 'c' && p[i] != 'f'){
                vis = true;
            }
        }
        if(vis){
            cout<<"-1"<<endl;
            continue;
        }
        int ans = 0;
        if(!Count) {
            //cout<<len<<endl;
            if(len % 2 == 0) cout<<len/2<<endl;
            else        cout<<len/2+1<<endl;
            continue;
        }
        if(jl[0]!=0){
            int zh;
            zh = len-1-jl[Count-1]+(jl[0]);
            //cout<<zh<<"*****"<<endl;
            if(zh < 2) {
                vis = true;
            }
            else ++ans;
            if(!vis) for(int i=1;i<Count;i++){

                if(jl[i] - jl[i-1] -1 < 2) {
                    vis = true;
                    break;
                }
                else                    ++ans;
            }
        }
        else{
            int zh;
            zh = len-1-jl[Count-1];
            //cout<<zh<<endl;
            if(zh < 2) {
                vis = true;
            }
            else ++ans;
            if(!vis) for(int i=1;i<Count;i++){
                if(jl[i] - jl[i-1] -1 < 2) {
                    vis = true;
                    break;
                }
                else    ++ans;
            }
        }
        if(vis) cout<<"-1"<<endl;
        else    cout<<ans<<endl;
    }
    return 0;
}
