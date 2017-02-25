// UVALive6910
//https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=6910


#include <iostream>
#include <string.h>
using namespace std;
const int maxn=20005;
char s;
int fa[maxn],a[maxn];
int find(int x)
{
    while(x!=fa[x]) x = fa[x];
        return x;
}

int main()
{
    int T,n,k,x,y,z;
    cin>>T;
    int cases=1;
    while(T--)
    {
        cin>>n>>k;
        for(int i=1;i<=n;i++)
            fa[i]=i;
        //memset(fa,-1,sizeof(fa));
        memset(a,0,sizeof(a));
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            if(a[i]==0)
               // fa[i]=i;
                continue;
            else fa[i]=a[i];
            //else bing(i,a[i]);
        }
        //fa[2]=2;
//       for(int i=1;i<=n;i++)
//       cout<<find(i)<<" ";
//       cout<<endl;
        cout<<"Case #"<<cases++<<":"<<endl;
        for(int i=1;i<=k;i++)
        {
            cin>>s;
            if(s=='Q')

            {
                cin>>x>>y;
                //cout<<find(x)<<" "<<find(y)<<endl;
                //cout<<fa[x]<<" "<<fa[y]<<endl;
                if(find(x)==find(y))
                    cout<<"YES"<<endl;
                else cout<<"NO"<<endl;
            }
            else if(s=='C')
            {
                cin>>z;

                fa[z]=z;
                //cout<<fa[z]<<endl;
            }
        }

    }
    return 0;
}
/**
4
7 4
0 1 1 2 2 2 3
Q 5 7
C 2
Q 5 7
Q 4 6
4 4
2 0 2 3
C 3
Q 1 2
C 1
Q 1 2
3 5
0 3 0
C 1
Q 1 2
C 3
C 1
Q 2 3
1 1
0
Q 1 1
*/
