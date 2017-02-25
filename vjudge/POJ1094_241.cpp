// POJ1094
//http://poj.org/problem?id=1094


#include <iostream>
#include <queue>
#include <string.h>
#include <stdio.h>
using namespace std;
const int maxn=30;
int head[maxn],ip,indegree[maxn];
int n,m,seq[maxn];
struct note
{
    int v,next;
}edge[maxn*maxn];
void init()
{
    memset(head,-1,sizeof(head));
    memset(indegree,0,sizeof(indegree));
    memset(seq,0,sizeof(seq));
    ip=0;
}
void addedge(int u,int v)
{
    edge[ip].v=v;
    edge[ip].next=head[u];
    head[u]=ip++;
}
int topo()
{

    queue<int>q;
    int indeg[maxn];
    for(int i=0;i<n;i++)
    {
        indeg[i]=indegree[i];
        if(indeg[i]==0)
            q.push(i);
    }
    int k=0;
    bool res=false;

    while(!q.empty())
    {
        if(q.size()!=1)
            res=true;
        int u=q.front();
        q.pop();
        seq[k++]=u;
        for(int i=head[u];i!=-1;i=edge[i].next)
        {
            int v=edge[i].v;
            indeg[v]--;
            if(indeg[v]==0)
                q.push(v);
        }
    }
    if(k<n) return -1;
    if(res)
        return 0;
    return 1;
}
int main()
{
   while(cin>>n>>m)
   {
       init();
      int sign=0;
       if(n==0&&m==0)
        break;
       int flag=0;
       for(int i=0;i<m;i++)
       {
           char s1,s2,s3;
           cin>>s1>>s2>>s3;
           //cout<<sign<<endl;
           if(sign==1)
            continue;
           int u=s1-'A';
           int v=s3-'A';
            sign=0;
           addedge(u,v);
           indegree[v]++;
            flag=topo();
           if(flag==-1)
           {
               sign=1;
               cout<<"Inconsistency found after "<<i+1<<" relations."<<endl;

           }
           else if(flag==1)
           {
               sign=1;
               //cout<<i<<endl;
               cout<<"Sorted sequence determined after "<<i+1<<" relations: ";
               for(int j=0;j<n;j++)
                    putchar(seq[j]+'A');
               cout<<"."<<endl;
           }
           else
           {
               continue;
           }
       }
       if(sign==0)
        cout<<"Sorted sequence cannot be determined."<<endl;
   }
    return 0;
}
