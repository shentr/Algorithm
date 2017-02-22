// 2024 ( C语言合法标识符 )
//acm.hdu.edu.cn/showproblem.php?pid=2024


#include<stdio.h>
#include<string.h>
int main()
{
    int n,i,d;
    char a[55];
    scanf("%d%*d",&n);
    while(n--)
    {
       gets(a);
         d=0;
         if((a[0]>='A'&&a[0]<='Z')||(a[0]>='a'&&a[0]<='z')||a[0]=='_')
            d=0;
            else d++;
         for(i=0;i<strlen(a);i++)
             if(a[i]=='_'||(a[i]>='a'&&a[i]<='z')||(a[i]>='A'&&a[i]<='Z')||(a[i]>='0'&&a[i]<='9'))
                d==0;
                else d++;
         if(d==0)
         printf("yes\n");
         else
         printf("no\n");
    }

}




