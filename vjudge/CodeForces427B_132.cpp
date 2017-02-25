// CodeForces427B
//http://codeforces.com/problemset/problem/427B


#include<cstdio>
int main()
{
    int n,t,c;
    while(~scanf("%d%d%d",&n,&t,&c))
    {
        int count=0,flag=1;
        for(int i=1; i<=n; i++)
        {
            int a;
            scanf("%d",&a);
            if(a>t)
            {
                flag=i+1;
            }
            else if(i-flag>=c-1)
            {
                count++;
            }
        }
        printf("%d\n",count);
    }
    return 0;
}