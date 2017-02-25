// HDU5379
//http://acm.hdu.edu.cn/showproblem.php?pid=5379


#include <iostream>  
#include <cstdio>  
#include <queue>  
#include <vector>  
#include <cstring>  
#define MOD 1000000007  
using namespace std;  
long long ans;  
struct node  
{  
    int id;  
    //存真正的孩子  
    vector <int> child;  
    //存相邻的边  
    vector <int> edge;  
    int num;  
}store[100010];  
queue <int> qe;  
bool flag;  
bool vis[100010];  
void bfs(int x)  
{  
    while(!qe.empty())  
        qe.pop();  
    //先访问的是父亲  
    memset(vis,0,sizeof(vis));  
    int sz,yezi,qujian;  
    qe.push(x);  
    int tmp;  
    while(!qe.empty())  
    {  
        //叶子和区间数  
        yezi=qujian=0;  
        tmp=qe.front();  
        qe.pop();  
        //标记为访问过  
        vis[tmp]=1;  
        sz=store[tmp].num;  
        for(int i=0;i<sz;i++)  
        {  
            //如果没访问过，说明是孩子  
            if(!vis[store[tmp].edge[i]])  
            {  
                vis[store[tmp].edge[i]]=1;  
                store[tmp].child.push_back(store[tmp].edge[i]);  
            }  
        }  
        sz=store[tmp].child.size();  
        for(int i=0;i<sz;i++)  
        {  
            //不是叶子节点，是还能往下的节点  
            //叶子节点只有其父亲连向它的边，而根节点虽然也是，但不会出现在这里  
            if(store[store[tmp].child[i]].num>1)  
            {  
                qujian++;  
                qe.push(store[tmp].child[i]);  
            }  
            else  
            {  
                yezi++;  
            }  
        }  
        //开始这里没特判，太理想化了，一个节点有超过三个点还能继续向下，那么答案为0  
        if(qujian>=3)  
        {  
            flag=true;  
            return;  
        }  
        //全是叶子节点，全排列  
        if(yezi==sz)  
        {  
            for(int i=1;i<=sz;i++)  
              ans=ans*i%MOD;  
        }  
        //一个区间，其他全叶子，只能叶子一边，区间一边  
        //两边互换，叶子全排列  
        else if(yezi==sz-1)  
        {  
            ans=ans*2%MOD;  
            for(int i=1;i<sz;i++)  
              ans=ans*i%MOD;  
        }  
        //两个区间，其他全叶子，只能叶子在中间，区间在两边  
        //叶子全排列，左右俩区间互换  
        else if(yezi==sz-2)  
        {  
            ans=ans*2%MOD;  
            for(int i=1;i<sz-1;i++)  
            ans=ans*i%MOD;  
        }  
    }  
}  
int main()  
{  
    int t,n,fa,son;  
    scanf("%d",&t);  
    for(int i=1;i<=100000;i++)  
    {  
        store[i].id=i;      
    }  
    for(int i=1;i<=t;i++)  
    {  
        //初始化  
        scanf("%d",&n);  
        for(int j=1;j<=n;j++)  
        {  
            store[j].child.clear();  
            store[j].edge.clear();  
            store[j].num=0;  
        }  
        for(int j=1;j<n;j++)  
        {  
            scanf("%d%d",&son,&fa);  
            //连双向边，搜索后才能决定谁是父亲，谁是儿子  
            store[fa].edge.push_back(son);  
            store[son].edge.push_back(fa);  
            //连边的数量  
            store[fa].num++;  
            store[son].num++;  
        }  
        //一个节点特判  
        if(n==1)ans=1;  
        else  
        {  
          flag=false;  
          ans=2;  
          bfs(1);  
          if(flag)  
              ans=0;  
        }  
        printf("Case #%d: %lld\n",i,ans);  
    }  
    return 0;  
}  