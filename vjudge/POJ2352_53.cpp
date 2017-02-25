// POJ2352
//http://poj.org/problem?id=2352


#include"iostream"
#include"cstdio"
#include"cstring"
using namespace std;
const int N=32005;
const int M=15005;
int bit[N];
int du[M],hs[M];

void add(int i,int x)
{
     while(i<N)
     {
         bit[i]+=x;
         i+= i&-i;
     }
}

int sum(int i)
{
    int s=0;
    while(i>0)
    {
         s+=bit[i];
         i-= i&-i;
    }
    return s;
}

int main()
{
    int n;
     while(~scanf("%d",&n))
     {
         memset(bit,0,sizeof(bit));
         memset(du,0,sizeof(du));
         memset(hs,0,sizeof(hs));
         int x,y;
         for(int i=0;i<n;i++)
         {
             scanf("%d%d",&x,&y);
             x++;
             du[i]=sum(x);
             add(x,1);
         }
        for(int i=0;i<n;i++)
            hs[du[i]]++;
        for(int i=0;i<n;i++)
            printf("%d\n",hs[i]);
     }
     return 0;
}
