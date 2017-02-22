// 2033 ( 人见人爱A+B )
//acm.hdu.edu.cn/showproblem.php?pid=2033


#include<stdio.h>
int main()
{
    int ah,am,as,bh,bm,bs,cs,ch,cm,m,s,n;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d%d%d%d%d%d",&ah,&am,&as,&bh,&bm,&bs);
        ch=ah+bh;cm=am+bm;cs=as+bs;
        m=cm;s=cs;
        cs=cs%60;cm=(s/60+cm)%60;ch=m/60+ch;
        printf("%d %d %d\n",ch,cm,cs);
    }return 0;
}
