// HDU4310
//http://acm.hdu.edu.cn/showproblem.php?pid=4310


#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
struct sa
{
    int x,y;
    double per;
}data[25];
int cmp(const sa a,const sa b)
{
    return a.per > b.per;
}

int main()
{
    int t;
    while(cin>>t)
    {
        int time=0,sumn=0;
        memset(data,0,sizeof(data));
        for(int i=1;i<=t;i++)
        {
            cin>>data[i].x>>data[i].y;
            data[i].per=(double)data[i].x/(double)data[i].y;
        }
        sort(data+1,data+t+1,cmp);
        for(int i=1;i<=t;i++)
        {
            time+=data[i].y;
            sumn+=data[i].x*time;
           // cout<<data[i].x<<" "<<data[i].y<<" "<<time<<" "<<sumn<<endl;
        }
        cout<<sumn<<endl;
    }
    return 0;
}
