// 1370 ( Biorhythms )
//acm.hdu.edu.cn/showproblem.php?pid=1370


#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        for(int kase=1;;kase++)
        {
            int p,e,i,d;
            cin>>p>>e>>i>>d;
            if(p==-1&&e==-1&&i==-1)
            {
                //cout<<endl;
                break;
            }
            int ii=i-i/33*33;
            int j;
            for(j=d+1;j<=21252*2;j++)
            {
                if((j-ii)%33==0)
                    break;
            }
            for(;j<=21252*2;j+=33)
            {
                if((j-(e-e/28*28))%28==0&&(j-(p-p/23*23))%23==0)
                {
                    printf("Case %d: the next triple peak occurs in %d days.\n",kase,j-d);
                    break;
                }
            }
        }
    }
}
