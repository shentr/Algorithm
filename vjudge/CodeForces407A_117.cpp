// CodeForces407A
//http://codeforces.com/problemset/problem/407A


#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
int f[1000005];

int main()
{
    int a,b;
    int c2,d,e;
	while(~scanf("%d%d",&a,&b))
    {
        bool flag=0;
        //memset(f,0,sizeof(0));
        for(int i=0;i<=1000;i++)
            f[i*i]=i;
        for (int i=1;i<a;i++)
        {
            c2=a*a-i*i;
            d=i*b/a;
            if(f[c2]&&i*b%a==0&&f[c2]!=d&&f[b*b-d*d])
            {
                e=-i;
                flag=1;
                break;
            }
        }
        if(flag)
        printf("YES\n0 0\n%d %d\n%d %d\n",e,f[c2],f[b*b-d*d],d);
        else
        printf("NO\n");
	}
}
