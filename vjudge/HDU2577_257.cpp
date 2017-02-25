// HDU2577
//http://acm.hdu.edu.cn/showproblem.php?pid=2577


#include <iostream>
#include <string.h>
using namespace std;
int n;
char s[105];
int a[105];
int d[2][105];
int main()
{
    cin>>n;
    while(n--)
    {
        memset(d,0,sizeof(d));
        memset(a,0,sizeof(a));
        memset(s,0,sizeof(s));
        cin>>s;
        int sum=0,len=0;
        len=strlen(s);
        //a[0]=2;
        for(int i=0; i<len; i++)
        {
            if(s[i]>='A'&&s[i]<='Z')
                a[i+1]=1;
            else if(s[i]>='a'&&s[i]<='z')
                a[i+1]=2;
        }
        d[0][0]=0;
        d[1][0]=1;
        for(int i=1;i<=len;i++)
        {
            if(a[i]==2)
                {
                    d[0][i]=min(d[1][i-1]+2,d[0][i-1]+1);
                    d[1][i]=min(d[1][i-1]+2,d[0][i-1]+2);
                }
            else if(a[i]==1)
                {
                    d[0][i]=min(d[1][i-1]+2,d[0][i-1]+2);
                    d[1][i]=min(d[1][i-1]+1,d[0][i-1]+2);
                }
        }
        sum=min(d[0][len],d[1][len]+1);
        cout<<sum<<endl;
      /*  for(int i=1;i<=len;i++)
            cout<<d[0][i]<<" ";
        cout<<endl;
        for(int i=1;i<=len;i++)
            cout<<d[1][i]<<" ";
        cout<<endl;*/
    }

        /*if(len==1)
        {
            if(a[1]==1)
                cout<<2<<endl;
                else cout<<1<<endl;
                continue;
        }
        if(a[len]==2&&a[len-1]==2)
            sum+=1;
        else
            sum+=2;
        for(int i=len-1;i>=2;i--)
        {
            if((a[i]==a[i-1])||(a[i]==2&&a[i]!=a[i-1]&&a[i]==a[i-2]))
                sum+=1;
                else sum+=2;
        }
        if(a[1]==2)
            sum+=1;
        else if(a[1]==1)
            sum+=2;
        cout<<sum<<endl;
    }
    */
    return 0;
}
