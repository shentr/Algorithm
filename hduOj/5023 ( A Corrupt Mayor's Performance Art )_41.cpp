// 5023 ( A Corrupt Mayor's Performance Art )
//acm.hdu.edu.cn/showproblem.php?pid=5023


#include"bits/stdc++.h"
using namespace std;
const int N=1000050;

struct node
{
    int left,right;
    int va,chg;
}ST[N<<2];

void pushUp(int num)
{
    if(ST[num<<1].va==ST[num<<1|1].va)
        ST[num].va=ST[num<<1].va;
    else
        ST[num].va=0;
}

void pushDown(int num)
{
    if(ST[num].chg!=0)
    {
        ST[num<<1].chg=ST[num<<1].va=ST[num].chg;
        ST[num<<1|1].chg=ST[num<<1|1].va=ST[num].chg;
        ST[num].chg = 0;
    }
}

void build(int left, int right, int num)
{
    ST[num].left=left;
    ST[num].right=right;
    ST[num].va=2;
    ST[num].chg=2;
    if (left==right)
    {
        ST[num].chg=2;
        return;
    }
    int mid=(left+right)>>1;
    build(left, mid, num<<1);
    build(mid+1, right, num<<1|1);
}

void update(int left, int right, int num, int col)
{
    if(left<= ST[num].left&&right>=ST[num].right)
    {
        ST[num].va=ST[num].chg=col;
        return;
    }
    pushDown(num);
    int mid=(ST[num].left+ST[num].right)>>1;
    if(left<=mid)
        update(left, right, num<<1, col);
    if(right>mid)
        update(left, right, num<<1|1, col);
    pushUp(num);
}

int a[50],t=0;
void query(int left, int right, int num)
{
    if(left>ST[num].right||right<ST[num].left)
        return;
    if(ST[num].va != 0)
    {
        int ok=0;
        for(int i=0;i<t;i++)
            {
              if(a[i]==ST[num].va)
                 ok=1;
            }
         if(ok==0)
          a[t++]=ST[num].va;
        return;
    }
    query(left, right, num<<1);
    query(left, right, num<<1|1);
}

int main()
{
    ios::sync_with_stdio(false);
    int n,m;
    while(cin>>n>>m&&(n!=0 || m!=0) )
    {
        build(1,n,1);
        while(m--)
        {
            char ch;
            cin>>ch;
            if(ch=='P')
            {
                int l,r,chg,root=1;
                cin>>l>>r>>chg;
                update(l,r,1,chg);
             }
            else
            {
                int l,r;
                t=0;
                cin>>l>>r;
                query(l,r,1);
                sort(a,a+t);
                for(int i=0;i<t;i++)
                {
                    if(i==0)
                        cout<<a[i];
                    else
                        cout<<" "<<a[i];
                }
                cout<<endl;
            }
        }
    }
}
