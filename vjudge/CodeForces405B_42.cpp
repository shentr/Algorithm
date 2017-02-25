// CodeForces405B
//http://codeforces.com/problemset/problem/405B


#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int n;
	char a[3005];
	while(cin>>n)
    {
        getchar();
        int cur=-1,ans=0,flag=0;
        for(int i=0;i<n;i++)
            scanf("%c",&a[i]);
        for (int i=0;i<n;i++)
        {
            if (a[i]=='.'&&cur==-1)
                ans++;
            if (a[i]=='R')
                cur=i;
            if (a[i]=='L'&&cur==-1)
                ans-=i;
            if (a[i]=='L'&&cur!=-1)
            {
                ans+=(i-cur+1)%2;
                cur=-1;
            }
        }
        cout<<ans<<endl;
    }
}
