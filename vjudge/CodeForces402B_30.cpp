// CodeForces402B
//http://codeforces.com/problemset/problem/402B


#include<iostream>
using namespace std;
int a[1010];

int main()
{
    int n,k,m,mini,aa;
    while(cin>>n>>k)
    {
        mini=999999;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        for(int i=1;i<=n;i++)
        {
            int count=0,flag=0;
            aa=a[i];
            for(int j=1;j<=i;j++)
            {
                int ans=aa-k*(i-j);
                if(ans<=0)
                {
                    flag=1;         ///
                    break;
                }
                if(ans>0&&ans!=a[j])
                    count++;
            }
            if(!flag)
            {
                aa=a[i];
                for(int j=i+1;j<=n;j++)
                {
                    int ans=aa+(j-i)*k;
                    if(ans<=0)
                    {
                        flag=1;         ///
                        break;
                    }
                    if(ans>0&&ans!=a[j])
                        count++;
                }
            }
            if(!flag)
            {
                if(count<mini)
                {
                    mini=count;
                    m=i;
                }
            }
        }
        if(mini==0)
            cout<<0<<endl;
        else
        {
            cout<<mini<<endl;
            for(int i=1;i<=m;i++)
            {
                int ans=a[m]-k*(m-i);
                if(a[i]<ans)
                    cout<<"+ "<<i<<" "<<ans-a[i]<<endl;
                else if(a[i]>ans)
                    cout<<"- "<<i<<" "<<a[i]-ans<<endl;
            }
            for(int i=m+1;i<=n;i++)
            {
                int ans=(i-m)*k+a[m];
                if(a[i]<ans)
                    cout<<"+ "<<i<<" "<<ans-a[i]<<endl;
                else if(a[i]>ans)
                    cout<<"- "<<i<<" "<<a[i]-ans<<endl;
            }
        }
    }
}
