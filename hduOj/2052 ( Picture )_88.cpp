// 2052 ( Picture )
//acm.hdu.edu.cn/showproblem.php?pid=2052


#include<iostream>
#include<cstdio>
int main()
{
    using namespace std;
    int width,height,i,j;
    while(cin>>width>>height)
    {
        for(i=1;i<=height+2;i++)
        {
            if(i==1||(i==height+2))
            {
                for(j=1;j<=width+2;j++)
                {
                    if(j==1||j==width+2)
                        cout<<'+';
                    else
                        cout<<'-';
                }
            }
            else
                for(j=1;j<=width+2;j++)
            {
                if(j==1||j==width+2)
                    cout<<'|';
                else
                    cout<<' ';
            }
            cout<<endl;
        }
            cout<<endl;
    }
    return 0;
}
