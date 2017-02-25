// HDU2647
//http://acm.hdu.edu.cn/showproblem.php?pid=2647


#include<cstdio>
#include<cstring>
#include<iostream>
#define M 20001
#define N 10001
int n,m;
using namespace std;

struct node
{
    int id;
    node *next;
}fa[N];

int toposort()
{
    int *queue=new int[n+1];
    node *p;
    int i,k,num;
    int sum=0;
    int temp=888;
    k=0;            
    while(1)    
    {
        memset(queue,0,(n+1)*sizeof(int));  
        num=0;          
        for(i=1;i<=n;++i)
        {
            if(fa[i].id==-1)   
                continue;
            if(fa[i].id==0)
            {
                queue[num++]=i;
                fa[i].id=-1;
                ++k;
            }
        }
        if(num==0&&k<=n)  
            return -1;
        sum+=temp*num;
        if(k==n)
            break;
        for(i=0;i<num;++i)      
        {
            p=fa[queue[i]].next;
            while(p)
            {
                --fa[p->id].id;
                p=p->next;
            }
        }
        ++temp;   //进入下一层之前钱数应加一
    }
    return sum;
}

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=0;i<=n;++i)
        {
            fa[i].id=0;   
            fa[i].next=NULL;
        }
        for(int i=0;i<m;++i)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            fa[a].id++;
            node *t=new node;
            t->id=a;
            t->next=fa[b].next;
            fa[b].next=t;
        }
        printf("%d\n",toposort());
    }
    return 0;
}
