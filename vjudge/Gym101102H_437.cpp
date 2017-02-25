// Gym101102H
//undefined101102H


#include <iostream>
#include <string.h>
using namespace std;
string s;
int main()
{
    ios::sync_with_stdio(false);
    int T,c,k;
    cin>>T;
    while(T--)
    {
//        memset(s,0,sizeof(s));
       bool flag=0;
        int sum=0,maxn=0;
        cin>>c>>k;
        cin>>s;
        for(int i=0;i<c;i++)
        {
           // cin>>s[i];
           // cout<<s[i]<<endl;
           if(s[i]=='0')
                {
                    sum++;
                    maxn=max(maxn,sum);
                }
            else sum=0;
            if(maxn>=k+1)
            {
                flag=1;
                break;
            }
        }
        //cout<<maxn<<endl;
        if(!flag)
            cout<<"no"<<endl;
        else cout<<"yes"<<endl;
    }
    return 0;
}
