// CodeForces754A
//http://codeforces.com/problemset/problem/754A


#include <iostream>
#include <string.h>
using namespace std;
struct sa
{
    int left,right;
}p[105];
int a[105];
int n;
int main()
{
    //cin>>n;
    while(cin>>n)
    {
        int sum=0;
        memset(a,0,sizeof(a));
        memset(p,0,sizeof(p));
        int k=1;
        bool flag=true;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            if(a[i]!=0)
                sum++;
        }
        if(sum==0)
        {
            cout<<"NO"<<endl;
            continue;
        }
        if(n==1)
        {
            if(a[1]==0)
            {
                cout<<"NO"<<endl;
            }
            else if(a[1]!=0)
            {
                cout<<"YES"<<endl;
                cout<<1<<endl;
                cout<<1<<" "<<1<<endl;
            }
            continue;
        }
        else if(n>=2)
        {
            for(int i=1;i<=n;i++)
            {
                if(a[i]==0)
                {
                    if(flag)
                    {
                        p[k].left=i;
                        flag=false;
                    }
                    continue;
                }
                else if(a[i]!=0)
                {
                    if(flag==false)
                    {
                        p[k].right=i;
                        k++;
                        flag=true;
                    }
                    else
                    {
                        p[k].left=i;
                        p[k].right=i;
                        k++;
                    }

                }

            }
            if(a[n]==0)
                p[k-1].right=n;
        }
        cout<<"YES"<<endl;
        cout<<k-1<<endl;
        for(int i=1;i<k;i++)
        {
            cout<<p[i].left<<" "<<p[i].right<<endl;
        }
    }
    return 0;
}
