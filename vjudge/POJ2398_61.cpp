// POJ2398
//http://poj.org/problem?id=2398


#include"iostream"
#include"cstdio"
#include"algorithm"
#include"cstring"
using namespace std;
const int N=1005;

struct edge
{
    int x1,x2;
}e[N];

struct point
{
    int x,y;
}p[N];

int cmp(edge a,edge b)
{
    return a.x1<=b.x1;
}

int x1,y1,x2,y2;

bool is_z(point e1,point e2)                // /斜线
{
    if((e1.y-e2.y)*(e1.x-e2.x)>=0)
        return true;
    else
        return false;
}

bool is_f(point e1,point e2)                  // \斜线
{
    if((e1.y-e2.y)*(e1.x-e2.x)<=0)
        return true;
    else
        return false;
}

bool is_inzr(point e1,point e2,point p) //   针对/斜线的右边
{
    if((e1.y-e2.y)*(e1.x-e2.x)>=0)
    {
        if((p.x-e2.x>0)&&(e1.y-e2.y)*(p.x-e2.x)>(p.y-e2.y)*(e1.x-e2.x))
            return true;
    }
    return false;
}

bool is_infl(point e1,point e2,point p)        //   针对\斜线的左边
{
    if((e1.y-e2.y)*(e1.x-e2.x)<=0)
    {
        if((p.x-e2.x<0)&&(e1.y-e2.y)*(p.x-e2.x)<(p.y-e2.y)*(e1.x-e2.x))
            return true;
    }
    return false;
}

bool is_in(point e1,point e2,point e3,point e4,point p)
{
    if((is_z(e1,e2)&&is_inzr(e1,e2,p))&&(is_f(e3,e4)&&is_infl(e3,e4,p)))
        return true;
    if((is_z(e1,e2)&&is_inzr(e1,e2,p))&&(is_z(e3,e4)&&!is_inzr(e3,e4,p)))
        return true;
    if((is_f(e1,e2)&&!is_infl(e1,e2,p))&&(is_f(e3,e4)&&is_infl(e3,e4,p)))
        return true;
    if((is_f(e1,e2)&&!is_infl(e1,e2,p))&&(is_z(e3,e4)&&!is_inzr(e3,e4,p)))
        return true;
    return false;
}

int main()
{
    int n,m;
    while(cin>>n)
    {
        if(n==0)
            return 0;
        e[0].x1=0,e[0].x2=0;
        cin>>m>>x1>>y1>>x2>>y2;
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d",&e[i].x1,&e[i].x2);
        }
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&p[i].x,&p[i].y);
        }
        e[n+1].x1=x2,e[n+1].x2=x2;
        sort(e,e+n+2,cmp);
        int cnt[N];
        memset(cnt,0,sizeof(cnt));
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<m;j++)
            {

                point e1,e2;
                e1.x=e[i].x1,e1.y=y1;
                e2.x=e[i].x2,e2.y=y2;
                point e3,e4;
                e3.x=e[i+1].x1,e3.y=y1;
                e4.x=e[i+1].x2,e4.y=y2;
                /*{
                    cout<<'('<<e1.x<<','<<e1.y<<')'<<"   "<<'('<<e2.x<<','<<e2.y<<')'<<endl;
                    cout<<'('<<e3.x<<','<<e3.y<<')'<<"   "<<'('<<e4.x<<','<<e4.y<<')'<<endl;
                    cout<<'('<<p[j].x<<','<<p[j].y<<')'<<endl;
                }*/
                if(is_in(e1,e2,e3,e4,p[j]))
                {
                    cnt[i]++;
                    //cout<<"cnt"<<i<<"++++++++++++++++++++++"<<endl;
                }
            }
            //cout<<"-------------------------------------------"<<endl;
        }
        /*for(int i=0;i<=n;i++)
        {
            cout<<cnt[i]<<' ';
        }*/
        sort(cnt,cnt+n+1);
        puts("Box");
        int j=cnt[0],count=1;
        cnt[n+1]=-10;
        for(int i=1;i<=n+1;i++)
        {
            if(cnt[i]==j)
            {
                count++;
            }
            else
            {
                if(j!=0)
                    printf("%d: %d\n",j,count);
                j=cnt[i];
                count=1;
            }
        }
    }
}
