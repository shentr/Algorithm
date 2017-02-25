// HDU1599
//http://acm.hdu.edu.cn/showproblem.php?pid=1599


#include<iostream>
using namespace std;

const int inf=99999999;
int map[102][102],sp[102][102];
int minn,n,m;

void floyd()
{
 minn=inf;
 for(int k=1;k<=n;k++)
 {
  for(int i=1;i<k;i++)
   for(int j=1;j<i;j++)
    minn=min(minn,sp[i][j]+map[i][k]+map[k][j]);
  for(int i=1;i<=n;i++)
   for(int j=1;j<=n;j++)
    sp[i][j]=min(sp[i][j],sp[i][k]+sp[k][j]);
 }
 if(minn!=inf)
  cout<<minn<<endl;
 else
  cout<<"It's impossible."<<endl;
}

int main()
{
 int x,y,s;
 while(cin>>n>>m)
 {
  for(int i=1;i<=n;i++)
   for(int j=1;j<=n;j++)
    map[i][j]=inf;
  for(int i=1;i<=m;i++)
  {
   cin>>x>>y>>s;
   if(s<map[x][y])
    map[x][y]=map[y][x]=s;
  }
  for(int i=1;i<=n;i++)
   for(int j=1;j<=n;j++)
    sp[i][j]=map[i][j];
  floyd();
 }
 return 0;
}
