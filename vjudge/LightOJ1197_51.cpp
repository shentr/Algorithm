// LightOJ1197
//http://lightoj.com/login_main.php?url=volume_showproblem.php?problem=1197


#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
const int MAXN=70000;
bool flag[MAXN+10],f[100010];
long long p[MAXN+10];
long long z;
void getPrime()
{
    long long i,j;
    z=0;
    memset(flag,true,sizeof(flag));
    for (i = 2; i <=MAXN; i++)
    {
        if (flag[i])
        {
            p[z++]=i;
            //z++;
            for (j = i * i; j <=MAXN; j += i)
            {
                flag[j]=0;
            }
        }
    }
}
int main()
{
	int T,kase=0;
	int cont;
    long long m,n,i,sz,k;
    getPrime();
	scanf("%d",&T);
    while(T--)
    {
		scanf("%lld%lld",&m,&n);
        cont=0;
        if(n<70000)
        {
            for(i=m;i<=n;i++)
            {
                if(flag[i] && i!=1)  cont++;
            }
		}
        else
        {
			if(m<=2) m=2;
            sz=n-m;
            for(i=0;i<=sz;i++) f[i]=true;
            for(i=0;i<z && p[i]*p[i]<=n;i++)
            {
                k=m/p[i];
                if(k*p[i]<m) k++;
                if(k<=1) ++k;
                while(k*p[i]<=n)
                {
                    f[k*p[i]-m]=false;
                    ++k;
                }
            }
            for(i=0;i<=sz;i++)
            {
                if(f[i])     cont++;
            }
		}
		printf("Case %d: %d\n",++kase,cont);
    }
    return 0;
}
