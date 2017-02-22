// 1211 ( RSA )
//acm.hdu.edu.cn/showproblem.php?pid=1211


#include<stdio.h>
#include<math.h>
int x,y;
int GCD(int a,int b)
{
    __int64 t,d;
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    d=GCD(b,a%b);
    t=x;
    x=y;
    y=t-(a/b)*(y);
    return d;
}
int main()
{
    int p,q,e,n,d,m,c,fn,i,j,t,gcd,k;
    while(scanf("%d %d %d %d",&p,&q,&e,&t)!=EOF)
    {
        n=p*q;
        fn=(p-1)*(q-1);
        gcd=GCD(e,fn);//a,b
        //d=x*(1/gcd);//d就是模板中的x0
        //k=d/(fn/gcd);
       // d=d-k*(fn/gcd);
        d=x>0?(x%fn):(x%fn+fn);
        //if(d<0) d=d+fn/gcd;
        for(i=0;i<t;i++)
        {
            scanf("%d",&c);
            m=1;
            for(j=0;j<d;j++)
            {
                m*=c;
                m%=n;
            }
            printf("%c",m);
        }
        printf("\n");
    }
    return 0;
}
