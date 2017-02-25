// HDU2094
//http://acm.hdu.edu.cn/showproblem.php?pid=2094


#include<iostream>
#include<string>
using namespace std;
const int N=1010;

struct node
{
    string name;
    int ru,chu;
    bool flag;
}p[N];

string a,b;

void init()
{
    for(int i=0;i<N;i++)
    {
        p[i].ru=0;
        p[i].chu=0;
        p[i].flag=0;
    }
}

int main()
{
    int n;
    while(cin>>n&&n)
    {
        init();
        int k=0,count=0;
        for(int i=0;i<n;i++)
        {
            cin>>a>>b;
            int flag=0;
            for(int j=0;j<k;j++)
            {
                if(a==p[j].name)
                {
                    p[j].chu++;
                    flag=1;
                    break;
                }
            }
            if(!flag)
            {
                p[k].name=a;
                p[k].flag=1;
                p[k].chu++;
                k++;
            }
            flag=0;
            for(int j=0;j<k;j++)
            {
                if(b==p[j].name)
                {
                    p[j].ru++;
                    flag=1;
                    break;
                }
            }
            if(!flag)
            {
                p[k].name=b;
                p[k].flag=1;
                p[k].ru++;
                k++;
            }
        }
        for(int i=0;i<k;i++)
        {
            if(p[i].ru==0)
                count++;
        }
        if(p[k].flag==1)
            if(p[k].ru==0)
            count++;
        if(count==1)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}
