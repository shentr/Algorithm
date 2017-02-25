// POJ1611
//http://poj.org/problem?id=1611


#include <iostream>
#include <stdio.h>

using namespace std;

const int N=30005;
int father[N];
int num[N];//num[]存储节点所在集合元素的个数，father[]存储节点的父亲节点

void make_set(int x)//初始化集合
{
    father[x]=-1;
    num[x]=1;
}

int find_set(int x)//查找x元素所在的集合，并返回根节点
{
    int r,tmp;
    r=x;//记录下待查找值x
    while(father[r]!=-1)
    {
        r=father[r];//找到根节点
    }
    while(x!=r)//压缩路径，将路径上所有x的子孙都连接到r上
    {
        tmp=father[x];
        father[x]=r;
        x=tmp;
    }
    return x;
}
void union_set(int a,int b)
{
    a=find_set(a);
    b=find_set(b);//若两个元素在同一个集合，不需要合并
    if(a==b)
    return;
    if(num[a]<=num[b])//将小集合合并到大集合中
    {
        father[a]=b;
        num[b]+=num[a];
    }
    else
    {
        father[b]=a;
        num[a]+=num[b];
    }
}

int main()
{
    int n,m,k,a,b;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(n==0&&m==0)break;//if(n+m==0)break;
        for(int i=0;i<n;i++)
        {
            make_set(i);
        }
        for(int i=0;i<m;i++)
        {
            scanf("%d",&k);
            scanf("%d",&a);
            for(int j=1;j<k;j++)
            {
                scanf("%d",&b);
                union_set(a,b);
            }
        }
        printf("%d\n",num[find_set(0)]);
    }
    return 0;
}