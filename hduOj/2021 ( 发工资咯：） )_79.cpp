// 2021 ( 发工资咯：） )
//acm.hdu.edu.cn/showproblem.php?pid=2021


#include<stdio.h>
int main()
{
    int n,i,a[100],t[100],B,W,S,F,E,Y;
    while(scanf("%d",&n),n!=0)
    {
        for(i=1;i<=n;i++)
            {scanf("%d",&a[i]);
            B=a[i]/100;
            W=(a[i]-100*B)/50;
            S=(a[i]-100*B-50*W)/10;
            F=(a[i]-100*B-50*W-10*S)/5;
            E=(a[i]-100*B-50*W-10*S-F*5)/2;
            Y=(a[i]-100*B-50*W-10*S-F*5-E*2);
            t[0]=0;
            t[i]=B+W+S+F+E+Y;
            t[i]=t[i-1]+t[i];
            }
            printf("%d\n",t[n]);
    }return 0;
}
