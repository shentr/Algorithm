// HDU5583
//http://acm.hdu.edu.cn/showproblem.php?pid=5583


#include"bits/stdc++.h"
using namespace std;
typedef long long LL;
const int N=1e5+5;

int main()
{
    int t,kase=1;
    string str;
    LL a[N];
    cin>>t;
    while(t--)
    {
        int maxn=0,left,cha,cnt=0;
        LL ans=0;
        cin>>str;
        left=0;
        int len=str.length();
        str[len]=str[len-1];
        for(int i=1;i<=len;i++)
        {
            if(str[i]!=str[i-1]||i==len)
            {
                a[cnt]=i-left;
                ans+=a[cnt]*a[cnt];
                left=i;
                cnt++;
            }
        }
        //cout<<ans<<endl;
        LL ans0,ans1,maxans=ans;
        a[-1]=0;a[cnt]=0;
        for(int i=0;i<cnt;i++)
        {
            if(a[i]==1)
            {
                ans0=a[i-1]*a[i-1]+a[i]*a[i]+a[i+1]*a[i+1];
                ans1=(a[i]+a[i-1]+a[i+1])*(a[i]+a[i-1]+a[i+1]);
                if(ans0<ans1)
                    maxans=max(maxans,ans-ans0+ans1);
            }
            else
            {
                ans0=a[i-1]*a[i-1]+a[i]*a[i];
                ans1=(a[i-1]+1)*(a[i-1]+1)+(a[i]-1)*(a[i]-1);
                if(ans0<ans1)
                    maxans=max(maxans,ans-ans0+ans1);
                ans0=a[i]*a[i]+a[i+1]*a[i+1];
                ans1=(a[i+1]+1)*(a[i+1]+1)+(a[i]-1)*(a[i]-1);
                if(ans0<ans1)
                    maxans=max(maxans,ans-ans0+ans1);
            }
        }
        cout<<"Case #"<<kase++<<": "<<maxans<<endl;
    }
}
