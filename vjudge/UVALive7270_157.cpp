// UVALive7270
//https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=7270


#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    while(cin>>n)
    {
        int a,b=-1,ans=0;
        for(int i=1;i<=n;i++)
        {
            string x;
            cin>>x;
            if(x=="S")
            {
                ans++;
                b=-1;
            }
            else
            {
                scanf("%d",&a);
                if(a!=b+1)
                    ans++;
                b=a;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
