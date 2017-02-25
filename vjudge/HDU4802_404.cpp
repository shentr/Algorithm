// HDU4802
//http://acm.hdu.edu.cn/showproblem.php?pid=4802


#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;
string a;
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        // memset(a,0,sizeof(a));
        double sum=0.0;
        int ans=0;
        int x;
        for(int i=1; i<=n; i++)
        {
            cin>>x>>a ;
            if(a =="P"||a =="N")
                continue;
            else if(a =="A")
                sum+=x*4.0;
            else if(a =="A-")
                sum+=x*3.7;
            else if(a =="B+")
                sum+=x*3.3;
            else if(a =="B")
                sum+=x*3.0;
            else if(a =="B-")
                sum+=x*2.7;
            else if(a =="C+")
                sum+=x*2.3;
            else if(a =="C")
                sum+=x*2.0;
            else if(a =="C-")
                sum+=x*1.7;
            else if(a =="D")
                sum+=x*1.3;
            else if(a =="D-")
                sum+=x*1.0;
            else if(a =="F")
                sum+=x*0;
                ans+=x;

        }
        if(ans==0&&sum==0)
            printf("0.00\n");
       else printf("%.2lf\n",sum/ans);
        for(int i=0; i<a.length(); i++)
            a.clear();
    }
    return 0;
}
