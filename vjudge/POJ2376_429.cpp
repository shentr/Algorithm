// POJ2376
//http://poj.org/problem?id=2376


#include <iostream>
#include <string.h>
#include <algorithm>
#include <stdio.h>
using namespace std;
struct sa
{
    int begin,end;
} data[1000050];
int cmp(const sa&x,const sa&y)
{
    if(x.begin==y.begin)
        return x.end>y.end;
    else return x.begin<y.begin;
}
int main()
{
    sa tmp;
    int n,t;
    while(scanf("%d%d",&n,&t)!=EOF)
    {
        memset(data,0,sizeof(data));
//        memset(tmp,0,sizeof(tmp));
        for(int i=0; i<n; i++)
            cin>>data[i].begin>>data[i].end;
        sort(data,data+n,cmp);
        tmp=data[0];
        //cout<<tmp.begin<<" "<<tmp.end<<endl;;
        if(tmp.begin!=1)
        {
            //cout<<-1<<endl;
            printf("-1\n");
            //break;
            continue;
        }
        int maxn=-1,sum=1,flag=0,b=0;
        while(tmp.end<t&&flag<n)
        {
            for(int i=0; i<n; i++)
            {
                if(data[i].begin<=tmp.end+1)
                {
                    if(data[i].end>maxn)
                    {
                        maxn=data[i].end;
                        b=i;
                    }

                }
                else break;
                //cout<<tmp.begin<<" "<<tmp.end<<endl;
                // cout<<b<endl;

            }
            // printf("%d\n",b);
            tmp=data[b];
            if(tmp.end<=t)
            {
                sum++;

                // cout<<sum<<endl;
            }
            flag++;
            //   cout<<flag<<"  "<<'a'<<endl;
            //  cout<<tmp.begin<<" "<<tmp.end<<endl;
        }

        if(tmp.end!=t)
        {

            cout<<-1<<endl;
        }
        else
        {
            cout<<sum<<endl;
        }
        //for(int i=0;i<n;i++)
        //  cout<<tmp.begin<<" "<<tmp.end<<endl;
    }
    return 0;
}
/**
8 14
1 2
1 3
2 3
2 10
3 9
5 7
8 11
11 14
*/
