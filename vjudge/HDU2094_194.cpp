// HDU2094
//http://acm.hdu.edu.cn/showproblem.php?pid=2094


#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
char str1[1005][30],str2[1005][30];
int sum[1005],c[1005];
int n;
int main()
{
    while(cin>>n)
    {
        if(n==0)
            break;
        memset(sum,0,sizeof(sum));
        getchar();
        for(int i=0; i<n; i++)
        {
            scanf("%s",str1[i]);
             getchar();
            scanf("%s",str2[i]);
            sum[i]=1;
        }

        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
            {
                if(strcmp(str1[i],str2[j])==0)
                {
                    sum[i]=0;
                }
            }
        int k=0;
        for(int i=0; i<n; i++)
        {
            if(sum[i])
            {
                c[k++]=i;
            }
        }
        int flag=0;
        for(int i=1; i<k; i++)
        {
            if(strcmp(str1[c[i]],str1[c[i-1]])==0)
            {
                flag++;
            }
        }
        if(flag==k-1)
            cout<<"Yes"<<endl;
        else cout<<"No"<<endl;


    }
    return 0;
}
