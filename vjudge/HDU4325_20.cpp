// HDU4325
//http://acm.hdu.edu.cn/showproblem.php?pid=4325


#include <bits/stdc++.h>

using namespace std;

const int MAX=1e5+5;
int s[MAX],e[MAX],q[MAX];
int rec[MAX];
int add[MAX<<2];
int sum[MAX<<2];
int le[MAX],ri[MAX];

void pushup(int o)
{
    sum[o]=sum[o<<1]+sum[o<<1|1];
}

void pushdown(int o,int m)
{
    if(add[o])
    {
        add[o<<1]+=add[o];
        add[o<<1|1]+=add[o];
        sum[o<<1]+=add[o]*(m-(m>>1));
        sum[o<<1|1]+=add[o]*(m>>1);
        add[o]=0;
    }
}

void gettree(int o,int l,int r)
{
    add[o]=0;
    if(l==r)
    {
        sum[o]=0;
        return ;
    }
    int mid=(l+r)>>1;
    gettree(o<<1,l,mid);
    gettree(o<<1|1,mid+1,r);
    pushup(o);
}

void update(int o,int l,int r,int L,int R,int val)
{
    if(L<=l&&R>=r)
    {
        add[o]+=val;
        sum[o]+=val*(r-l+1);
        return ;
    }
    pushdown(o,r-l+1);
    int mid=(l+r)>>1;
    if(L<=mid)
        update(o<<1,l,mid,L,R,val);
    if(R>mid)
        update(o<<1|1,mid+1,r,L,R,val);
    pushup(o);
}

int find(int o,int l,int r,int pos)
{
    if(l==r)
    {
        return sum[o];
    }
    pushdown(o,r-l+1);
    int ans=0;
    int mid=(l+r)>>1;
    if(pos<=mid)
        ans=find(o<<1,l,mid,pos);
    else
        ans=find(o<<1|1,mid+1,r,pos);
    return ans;
}

int query(int l,int r,int pos)//查找输入当前值，在树中对应的位置
{
    while(r>=l)
    {
        int mid=(l+r)>>1;
        if(rec[mid]==pos)
            return mid;
        else if(rec[mid]>pos)
            r=mid-1;
        else
            l=mid+1;
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    int t,n,m,k,i;
    cin>>t;
    k=1;
    int maxx;
    while(t--)
    {
        cin>>n>>m;
        int p=1;
        for(i=0;i<n;i++)
        {
            cin>>s[i]>>e[i];
            rec[p++]=s[i];
            rec[p++]=e[i];
        }
        for(i=0;i<m;i++)
        {
            cin>>q[i];
            rec[p++]=q[i];
        }
        sort(rec+1,rec+p);
        int R=2;
        for(i=2;i<p;i++)
        {
            if(rec[i]!=rec[i-1])
                rec[R++]=rec[i];
        }
        sort(rec+1,rec+R);
        gettree(1,1,R-1);
        for(int i=0;i<n;i++)
        {
            int x=query(1,R-1,s[i]);
            int y=query(1,R-1,e[i]);
            update(1,1,R-1,x,y,1);
        }
        cout<<"Case #"<<k++<<":"<<endl;
        for(i=0;i<m;i++)
        {
            int x=query(1,R-1,q[i]);
            cout<<find(1,1,R-1,x)<<endl;
        }
    }
}
