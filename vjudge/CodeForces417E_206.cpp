// CodeForces417E
//http://codeforces.com/problemset/problem/417E


#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include<cstring>
using namespace std;
bool num[1000003];
int main()
{
    //freopen("cin.txt","r",stdin);
    int n,m;
    memset(num,0,sizeof(num));
    for(int i=0;i<=1000;i++) num[i*i]=1;
    while(~scanf("%d%d",&n,&m)){
        int a,b,c,d;
        while(true){
            a=rand()%100+1;
            b=rand()%100+1;
            c=rand()%100+1;
            d=rand()%100+1;
            int s1=(m-1)*a*a+b*b;
            int s2=(n-1)*a*a+c*c;
            int s3=(m-1)*c*c+d*d;
            int s4=(n-1)*b*b+d*d;
            if(num[s1]&&num[s2]&&num[s3]&&num[s4]) break;
        }
        for(int i=0;i<n-1;i++){
            for(int j=0;j<m-1;j++) printf("%d ",a);
            printf("%d\n",b);
        }
        for(int j=0;j<m-1;j++) printf("%d ",c);
        printf("%d\n",d);
    }
    return 0;
}
