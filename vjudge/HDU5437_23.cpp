// HDU5437
//http://acm.hdu.edu.cn/showproblem.php?pid=5437


#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
const int N=15e4+10;

struct people
{
    char name[210];
    long long v;
    int come;    //来的顺序
}a[N];

struct opendoor
{
    int rk;   //第几个到
    int ac;   //让几个进
    opendoor()
    {
        rk=0;
        ac=0;
    }
}d[N];

struct cmp
{
    bool operator () (const people &a,const people &b)
    {
        if(a.v==b.v)
            return a.come>b.come;
        return a.v<b.v;
    }
};

int cmp1(const opendoor &a,const opendoor &b)
{
    return a.rk<b.rk;
}

void init(int k)
{
    for(int i=1;i<=k;i++)
        a[i].come=i;
}

int main()
{
    int t,k,m,q;
    scanf("%d",&t);
    while(t--)
    {
        priority_queue<people,vector<people>,cmp> que;
        scanf("%d%d%d",&k,&m,&q);
        init(k);
        for(int i=1;i<=k;i++)
        {
            scanf("%s%lld",a[i].name,&a[i].v);
        }
        int rk,ac,record[N],r=1;
        int pre_rk=0;            //上一个rk
        memset(record,0,sizeof(record));
        //memset(d,0,sizeof(d));
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d",&d[i].rk,&d[i].ac);
        }
        sort(d+1,d+m+1,cmp1);
        for(int i=1;i<=m;i++)
        {
            //scanf("%d%d",&rk,&ac);   //第rk到，放ac人
            for(int j=pre_rk+1;j<=d[i].rk;j++)
            {
                que.push(a[j]);
            }
            int h;
            for(h=1;h<=d[i].ac;h++)
            {
                if(que.empty())
                    break;
                record[r++]=que.top().come;
                que.pop();
            }
            pre_rk=d[i].rk;
        }
        while(d[m].rk<k)
        {
            d[m].rk++;
            que.push(a[d[m].rk]);
        }
        while(!que.empty())
        {
            record[r++]=que.top().come;
            que.pop();
        }
        int ask[110];
        for(int i=1;i<=q;i++)
        {
            scanf("%d",&ask[i]);
        }
        for(int i=1;i<q;i++)
        {
            printf("%s ",a[record[ask[i]]].name);
        }
        printf("%s\n",a[record[ask[q]]].name);
    }
}
