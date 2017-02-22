// 2027 ( 统计元音 )
//acm.hdu.edu.cn/showproblem.php?pid=2027


#include<stdio.h>
#include<string.h>
int main()
{
    int a,e,i,o,u,n,j,k;
    char s[101];
    scanf("%d%*d",&n);
    for(j=0;j<n;j++)
    {
        a=e=i=o=u=0;
        gets(s);
        for(k=0;k<strlen(s);k++)
       {if(s[k]=='a')   a++;
         if(s[k]=='e')   e++;
         if(s[k]=='i')   i++;
         if(s[k]=='o')   o++;
         if(s[k]=='u')   u++;
        }
        printf("a:%d\ne:%d\ni:%d\no:%d\nu:%d\n",a,e,i,o,u);
        if(j>=0&&j<n-1) printf("\n");
    }
    return 0;
}
