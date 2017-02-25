// UVALive6858
//https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=6858


#include <iostream>

using namespace std;
int x,y,n,a;
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>x>>y)
    {
        cin>>n;
        for(int i=1; i<=n; i++)
        {
            bool flag=0;
            cin>>a;
            if((x-2)%a==0&&y%a==0)
            {
                flag=1;
            }
            if((x%a==0)&&(y-2)%a==0)
                flag=1;
            if((x-1)%a==0&&(y-1)%a==0)
                flag=1;
            if((x-2)%a==0&&(y-1)%a==0&&x%a==0)
                flag=1;
            if((y-2)%a==0&&(x-1)%a==0&&y%a==0)
                flag=1;
            if(y%a==0&&(y-1)%2==0&&(x-1)%a==0&&(x-2)%a==0)
                flag=1;
            if(x%a==0&&(x-1)%2==0&&(y-1)%a==0&&(y-2)%a==0)
                flag=1;
            if(flag)
                cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
    return 0;
}
