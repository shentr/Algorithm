// UVA11806
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=11806


#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,m,sec,k;
int C[505][505];
const int mod=1000007;
void pre()
{
    memset(C,0,sizeof(C));
    for(int i=0;i<=500;i++)
    C[i][0]=1;

    for(int i=1;i<=500;i++)
     for(int j=1;j<=i;j++)
     C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
}
int main()
{
    pre();
    scanf("%d",&sec);
    for(int z=1;z<=sec;z++)
    {
        scanf("%d%d%d",&n,&m,&k);
        int ans=0;
        for(int i=0;i<16;i++)
        {
            int b=0,r=n,c=m;
            if(i&1){r--;b++;}
            if(i&2){r--;b++;}
            if(i&4){c--;b++;}
            if(i&8){c--;b++;}

            if(b%2==0)ans=(ans+C[r*c][k])%mod;
            else ans=(ans+mod-C[r*c][k])%mod;
        }

        printf("Case %d: %d\n",z,ans);
    }
    return 0;
}
