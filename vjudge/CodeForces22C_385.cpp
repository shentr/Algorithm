// CodeForces22C
//http://codeforces.com/problemset/problem/22C


#include <iostream>

using namespace std;
int n,m,v;
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>n>>m>>v)
        //cin>>n>>m>>v;
    {
        bool flag=0;
        int sum=0;
        long long ans=(n-1)*(n-2)/2+1;
        if(m>ans||m<n-1)
            cout<<-1<<endl;
        else
        {
            for(int i=1; i<=n; i++)
                if(i!=v)
                {
                    cout<<i<<" "<<v<<endl;
                    //sum++;
                }
            m-=(n-1);
            if(m==0)
                break;
            if(v==1)
            {
                for(int i=3; i<=n; i++)
                {
                    for(int j=i+1; j<=n; j++)
                    {
                        if(i!=v&&j!=v)
                        {
                            cout<<i<<" "<<j<<endl;
                            m--;
                            if(m==0)
                            {
                                flag=1;
                                break;
                            }
                        }
                    }
                    if(flag==1)
                        break;
                }
            }
            else
            {
                for(int i=2; i<=n; i++)
                {
                    for(int j=i+1; j<=n; j++)
                    {
                        if(i!=v&&j!=v&&m>0)
                        {
                            cout<<i<<" "<<j<<endl;
                            m--;
                            if(m==0)
                            {
                                flag=1;
                                break;
                            }
                        }
                    }
                    if(flag==1)
                        break;
                }
            }
        }
    }
    return 0;
}
