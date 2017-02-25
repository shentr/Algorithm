// POJ1068
//http://poj.org/problem?id=1068


#include <iostream>
#include <string.h>
#include <stack>
using namespace std;
int a[105],b[105];
char s[105];
int T,n;
stack<int>q;
int main()
{
    cin>>T;
    while(T--)
    {
        int k=0,sum=0;
        memset(a,0,sizeof(a));
        memset(s,0,sizeof(s));
        cin>>n;
        for(int i=1; i<=n; i++)
        {
            cin>>a[i];
            int ans=a[i]-a[i-1];
            while(ans--)
                s[k++]='(';
            s[k++]=')';
        }
        for(int i=0; i<k; i++)
        {
            while(!q.empty())
                q.pop();
            if(s[i]==')')
            {
                if(s[i-1]=='(')
                    b[++sum]=1;
                else if(s[i-1]==')')
                {
                    int ans=i,sum2=0;
                    q.push(')');
                    while(ans--)
                    {
                        if(s[ans]=='(')
                        {
                            sum2++;
                            q.pop();
                        }
                        else if(s[ans]==')')
                            q.push(')');
                        if(q.empty())
                            break;

                    }
                    b[++sum]=sum2;
                }
            }
        }
        for(int i=1; i<=sum; i++)
            cout<<b[i]<<" ";
        cout<<endl;

    }
    return 0;
}