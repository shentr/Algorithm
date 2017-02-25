// UVA10474
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=10474


#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int main()
{
    int n,q,x;
    int a[10005];
    ios::sync_with_stdio(false);
    int cases=1;
    while(cin>>n>>q)
    {
        if(n==0&&q==0)
            break;
            //cout<<100<<endl;
        int qq=q;

        cout<<"CASE# "<<cases++<<":"<<endl;
        //cout<<cases
       // while(qq--)
        {
            memset(a,0,sizeof(a));
            for(int i=0; i<n; i++)
            {
                cin>>a[i];
                // b[i]=a[i];
            }
            sort(a,a+n);
            for(int i=1; i<=q; i++)
            {

                cin>>x;
                /*for(int i=0; i<n; i++)
                    cout<<a[i]<<" ";
                cout<<endl;*/
                int pos1=upper_bound(a,a+n,x)-a;
                int pos2=lower_bound(a,a+n,x)-a;
                //cout<<pos1<<"*****"<<pos2<<endl;
                if(pos1==pos2)
                {
                    cout<<x<<" not found"<<endl;
                }
                else
                {
                    cout<<x<<" found at "<<pos2+1<<endl;
                }
            }

        }

    }
    return 0;
}
