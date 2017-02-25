// UVALive7454
//https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=7454


#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
char s[105];
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n,sum=0,ans=0;
        queue<int>q;
        memset(s,0,sizeof(s));
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>s[i];
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
                q.push(1);
            else if(s[i]==')')
            {
                if(!q.empty())
                {
                    q.pop();
                }
                else
                {
                    q.push(1);
                    sum++;
                }
            }
        }
        while(!q.empty())
        {
            q.pop();
            ans++;
        }
        cout<<sum+ans/2<<endl;
    }
    return 0;
}
