// 2043 ( 密码 )
//acm.hdu.edu.cn/showproblem.php?pid=2043


#include<stdio.h>
#include<string.h>
int main()
{
    int i,m,b,c,d,n,s;
    char a[51];
    scanf("%d%*c",&n);
    while(n--)
    {
        m=b=c=d=0;
        gets(a);
        if(strlen(a)>=8 && strlen(a)<=16)
        {
            for(i=0;i<strlen(a);i++)
            {
                if(a[i]>='a' && a[i]<='z')
                    m=1;
                if(a[i]>='A' && a[i]<='Z')
                    b=1;
                if(a[i]>='0' && a[i]<='9')
                    c=1;
                if(a[i]=='~'||a[i]=='!'||a[i]=='@'||a[i]=='#'||a[i]=='$'||a[i]=='%'&a[i]=='^')
                    d=1;
            }
            s=m+b+c+d;
            if(s>=3)
                printf("YES\n");
            else
                printf("NO\n");
        }
        else
            printf("NO\n");
    }
    return 0;
}
