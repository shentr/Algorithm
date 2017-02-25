// 1573 ( X问题 )
//acm.hdu.edu.cn/showproblem.php?pid=1573


#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int x,y;
int extend_gcd(int a,int b)
{
    int t,g;
    if(b==0)
    {
        x=1,y=0;
        return a;
    }
    g=extend_gcd(b,a%b);
    t=x,x=y,y=t-a/b*y;
    return g;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        int a[15],b[15];
        for(int i=0;i<m;i++)
            scanf("%d",&a[i]);
        for(int i=0;i<m;i++)
            scanf("%d",&b[i]);
        int aa=a[0],bb=b[0];
        bool flag=0;
        for(int i=1;i<m;i++)
        {
            int g=__gcd(a[i],aa);
            if((b[i]-bb)%g!=0)
            {
                cout<<0<<endl;
                flag=1;
                break;
            }
            extend_gcd(aa/g,a[i]/g);
            bb=aa*(b[i]-bb)/g*x+bb;
            aa=aa*a[i]/g;
            bb=bb%aa;        ///
            if(bb<0)
                bb=(bb+aa)%aa;
            //cout<<aa<<' '<<bb<<endl;
        }
        if(flag==0)
            if(n>=bb)
                if(bb==0)
                    cout<<(n-bb)/aa<<endl;
                else
                    cout<<(n-bb)/aa+1<<endl;
            if(n<bb)
                cout<<0<<endl;
    }
}
