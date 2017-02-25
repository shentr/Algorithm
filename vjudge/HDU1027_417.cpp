// HDU1027
//http://acm.hdu.edu.cn/showproblem.php?pid=1027


#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
long long n,m,num;
int a[1005];
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>n>>m)
    {
        num=1;
        memset(a,0,sizeof(a));
        for(int i=0; i<n; i++)
        {
            a[i]=i+1;
        }
        do{
            if(num==m)
            {

                for(int i=0; i<n-1; i++)
                {
                    cout<<a[i]<<" ";
                }
                cout<<a[n-1];
                cout<<endl;
                //break;
            }
             num++;
             if(num>m)
                break;
        }while(next_permutation(a,a+n));
    }
    return 0;
}
