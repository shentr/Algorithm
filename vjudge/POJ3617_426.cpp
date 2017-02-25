// POJ3617
//http://poj.org/problem?id=3617


#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
    //freopen("cin.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    char s[2005],ss[2005];
    int n;
    while(cin>>n)
    {
        memset(s,0,sizeof(s));
        memset(ss,0,sizeof(ss));
        int a=1,b=n,k=1,a0,b0,sum=1,j;
        for(int i=1;i<=n;i++)
           {
               getchar();
               cin>>s[i];
           }
           while(a<b)
           {
               if(s[a]<s[b]&&(a<b))
               {
                   ss[k]=s[a];
                   a++;
                   k++;
               }
               else if(s[a]>s[b]&&(a<b))
               {
                   ss[k]=s[b];
                   b--;
                   k++;
               }
               else if(s[a]==s[b]&&(a<b))
               {
                   a0=a;
                   b0=b;
                   while(s[a0]==s[b0])
                   {
                       a0++;
                       b0--;
                   }
                   if(a0==b0)
                       {
                           ss[k]=s[a];
                           a++;
                           a0++;
                           k++;
                       }
                       else if(s[a0]<s[b0])
                       {
                           ss[k]=s[a];
                           a++;
                           a0++;
                           k++;
                       }
                       else if(s[a0]>s[b0])
                       {
                           ss[k]=s[b];
                           b--;
                           b0--;
                           k++;
                       }

               }
           }
           ss[k]=s[b];
         /*  for(int i=1;i<=k;i++)
           {

               cout<<ss[i];
               if(i%80==0&&i*sum!=k)
               {
                   sum++;
                   cout<<endl;
               }
           }
           cout<<endl;*/
           j=0;
           for(int i=1;i<=k;i++)
           {
               cout<<ss[i];
               j++;
               if(j==80)
               {
                   cout<<endl;
                   j=0;
               }
           }
           if(j)
            cout<<endl;


    }
    return 0;
}
