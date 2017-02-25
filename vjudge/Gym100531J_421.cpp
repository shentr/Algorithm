// Gym100531J
//undefined100531J


#include"bits/stdc++.h"
using namespace std;
const int N=20005;
double sx,sy,fx,fy,v,wx[N],wy[N],vx,vy,winx=0,winy=0;
int n,k,t[N],ans=0;

bool solve(int mid)
{
    double ex=fx,ey=fy;
    ans=0,winx=winy=0;
    for(int i=0;i<mid;i++)
    {
        if(ans<n&&t[ans]==i)
        {
            winx=wx[ans],winy=wy[ans];
            ans++;
        }
        ex-=winx,ey-=winy;
    }
    double dis=sqrt((ex-sx)*(ex-sx)+(ey-sy)*(ey-sy));
    if(dis/v>mid)
        return 0;
    return 1;
}

int main()
{
    freopen("joy.in","r",stdin);
    freopen("joy.out","w",stdout);
    cin>>sx>>sy>>fx>>fy;
    cin>>n>>k>>v;
    for(int i=0;i<n;i++)
        cin>>t[i]>>wx[i]>>wy[i];
    int len = 0;
    for(len=0;len<=k+5;len++)
        if(solve(len))
            break;
    if(len>k)
    {
        cout<<"No"<<endl;
        return 0;
    }
    double ex=fx,ey=fy;
    ans=winx=winy=0;
    for(int i=0;i<len;i++)
    {
        if(ans<n&&t[ans]==i)
        {
            winx=wx[ans],winy=wy[ans];
            ans++;
        }
        fx-=winx,fy-=winy;
    }
    double l=fx-sx,h=fy-sy,dis=sqrt(l*l+h*h),vx=v*l/dis,vy=v*h/dis;
    ans=winx=winy=0;
    cout<<"Yes"<<endl;
    if(len==0)
        len++;
    for(int i=0;i<len-1;i++)
    {
        if(ans<n&&t[ans]==i)
        {
            winx=wx[ans],winy=wy[ans];
            ans++;
        }
        sx+=vx+winx;
        sy+=vy+winy;
        printf("%.6f %.6f\n",sx,sy);
    }
    for(int i=len;i<=k;i++)
        printf("%.6f %.6f\n",ex,ey);
}
