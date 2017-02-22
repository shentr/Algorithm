// 2029 ( Palindromes _easy version )
//acm.hdu.edu.cn/showproblem.php?pid=2029


#include<stdio.h>
#include<string.h>
int main()
{
    int n,i,m,d,j;
    char a[1000];
    while(scanf("%d%*c",&n)!=EOF)
    {
        for(i=0;i<n;i++)
            {d=0;
            gets(a);
            m=strlen(a);
            for(j=1;j<=m/2;j++)
            {
                if(a[j]==a[m-j-1])
                    d++;
            }
            if(d>=m/2)
                printf("yes\n");
            else
                printf("no\n");
            }
    }
    return 0;
}
