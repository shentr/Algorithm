// UVALive7269
//https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=7269


#include"bits/stdc++.h"
using namespace std;

int main()
{
    int n,H,W;
    while(cin>>n)
    {
        H=(n+1)/2;
        W=n&1?n:n+1;
        cout<<H<<' '<<W<<endl;
        for(int i=1; i<=n; i++)
        {
            if(i&1)
            {
                int x=H,y=H-i/2;
                while(x>y)
                {
                    cout<<x<<' '<<y<<' ';
                    x--;
                }
                cout<<x<<' '<<y<<' ';
                y++;
                while(y<=H)
                {
                    cout<<x<<' '<<y<<' ';
                    y++;
                }
            }
            else
            {
                if(n%4==0||(n+1)%4==0)
                {
                    int len=i/2;
                    if(i%4==0)
                    {
                        int x=H,y=i/2;
                        while(x>H-len+1)
                        {
                            cout<<x<<' '<<y+H<<' ';
                            x--;
                        }
                        cout<<x<<' '<<y+H<<' ';
                        y++;
                        while(x<=H)
                        {
                            cout<<x<<' '<<y+H<<' ';
                            x++;
                        }
                    }
                    else
                    {
                        int x = H - i/2 + 1, y = 1;
                        while(y<len)
                        {
                            cout<<x<<' '<<y+H<<' ';
                            y++;
                        }
                        cout<<x<<' '<<y+H<<' ';
                        x--;
                        while(y>=1)
                        {
                            cout<<x<<' '<<y+H<<' ';
                            y--;
                        }
                    }
                }
                else
                {
                    int len=i/2;
                    if(i%4==0)
                    {
                        int x=H-i/2+1,y=1;
                        while(y < len)
                        {
                            cout<<x<<' '<<y+H<<' ';
                            y++;
                        }
                        cout<<x<<' '<<y+H<<' ';
                        x--;
                        while(y>=1)
                        {
                            cout<<x<<' '<<y+H<<' ';
                            y--;
                        }
                    }
                    else
                    {
                        int x=H,y=i/2;
                        while(x>H-len+1)
                        {
                            cout<<x<<' '<<y+H<<' ';
                            x--;
                        }
                        cout<<x<<' '<<y+H<<' ';
                        y++;
                        while(x<=H)
                        {
                            cout<<x<<' '<<y+H<<' ';
                            x++;
                        }
                    }
                }
            }
            cout<<endl;
        }
    }
}
