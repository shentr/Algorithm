// CodeForces401B
//http://codeforces.com/problemset/problem/401B


#include<iostream>
#include<cstring>
using namespace std;

bool data[4010];
int da[4010];

int main()
{
    int x,k,a,b,c;
    while(cin>>x>>k)
    {
        memset(data,0,sizeof(data));
        int maxi=0,mini=0,p=0;
        for(int i=1;i<=k;i++)
        {
            cin>>a;
            if(a==1)
            {
                cin>>b>>c;
                data[b]=1;
                data[c]=1;
            }
            if(a==2)
            {
                cin>>b;
                data[b]=1;
            }
        }
        for(int i=1;i<x;i++)
        {
            if(data[i]==0)
            {
                maxi++;
                da[p++]=i;
            }
        }
        mini=maxi;
        for(int i=0;i<p;i++)
        {
            if(da[i]==da[i+1]-1)
            {
                mini--;
                i++;
            }
        }
        cout<<mini<<" "<<maxi<<endl;
    }
}
