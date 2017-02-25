// UVALive6862
//https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=6862


#include"bits/stdc++.h"
using namespace std;

int hsz[105];
void init()
{
    memset(hsz,0,sizeof(hsz));
    int m=103;
    for(int x=1;x<=m;x++)
        for(int y=x;y<=m;y++)
            for(int z=y;z<=m;z++)
            {
                if(x*x+y*y==z*z)
                {
                    for(int i=z;i<101;i++)
                        hsz[i]++;
                }
            }
}

int main()
{
    init();
    int m,n;
    while(cin>>m>>n)
        cout<<(m+1)*(n-1)+hsz[m]<<endl;
}
