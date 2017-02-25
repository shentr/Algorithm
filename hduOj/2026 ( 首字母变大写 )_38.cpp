// 2026 ( 首字母变大写 )
//acm.hdu.edu.cn/showproblem.php?pid=2026


#include<stdio.h>
#include<string.h>
int main()
{
    int i;
    char a[10000];
    while(gets(a))
    {
        for(i=0;i<strlen(a);i++)
        {
            if(a[i+1]>='a'&&a[i+1]<='z'||a[i+1]==' ')
            {
                a[0]=a[0]-32;
                if(a[i]==' ')
                a[i+1]=a[i+1]-32;
                }
                putchar(a[i]);
        }
        putchar('\n');
    }
    return 0;
}

