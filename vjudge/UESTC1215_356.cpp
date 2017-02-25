// UESTC1215
//http://acm.uestc.edu.cn/#/problem/show/1215


#include <iostream>
#define INF  99999999
using namespace std;

int main()
{
    int n,a0,a1,a2,a3,b0,b1,b2,b3,t;
    while(cin>>n)
    {

        for(int k=1; k<=n; k++)
        {
            cin>>a0>>a1>>a3>>a2;
            cin>>b0>>b1>>b3>>b2;
            int flag=0;
            for(int i=1; i<=4; i++)
            {


                    if(a0==b0&&a1==b1&&a2==b2&&a3==b3)
                        flag=1;
                    else
                    {
                        t=a0;
                        a0=a1;
                        a1=a2;
                        a2=a3;
                        a3=t;
                    }

            }
            if(flag==1)
               {
                   cout<<"Case #"<<k<<": ";
            cout<< "POSSIBLE"<<endl;
               }
            else
            {
                cout<<"Case #"<<k<<": ";
                cout<< "IMPOSSIBLE"<<endl;
            }
        }
    }
    return 0;
}
