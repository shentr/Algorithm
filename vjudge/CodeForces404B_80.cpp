// CodeForces404B
//http://codeforces.com/problemset/problem/404B


#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    int n;
    double a,d,r,c,x,y;
    long long k,i;
	while(~scanf("%lf%lf",&a,&d))
	{
	    cin>>n;
        for(int i=1;i<=n;i++)
        {
            k=i*d/a;
            c=i*d-k*a;
            switch(k%4)
            {
                case 0: x=c,y=0;break;
                case 1: x=a,y=c;break;
                case 2: x=a-c,y=a;break;
                case 3: x=0,y=a-c;break;
            }
            printf("%.10lf %.10lf\n",x,y);
	}
	}
}
