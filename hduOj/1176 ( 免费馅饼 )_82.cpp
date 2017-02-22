// 1176 ( 免费馅饼 )
//acm.hdu.edu.cn/showproblem.php?pid=1176


#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include<cstring>
using namespace std;
int data[100002][11],inp[100002][11];
int main(int argc, char *argv[])
 { int n,x,t,t_max;
 while(cin>>n&&n!=0)
{ memset(data,0,sizeof(data)); memset(inp,0,sizeof(inp));
t_max=0;
for(int i=1;i<=n;i++)
{ scanf("%d%d",&x,&t);
data[t][x]++;
if (t>t_max) t_max=t;
}
for(int i=0;i<=10;i++) inp[t_max][i]=data[t_max][i];

for(int i=t_max-1;i>=0;i--)
for(int j=10;j>=0;j--)
{
if (j==10) inp[i][j]=data[i][j]+max(inp[i+1][j],inp[i+1][j-1]);
if (j>=1&&j<=9) inp[i][j]=data[i][j]+max(max(inp[i+1][j],inp[i+1][j+1]),inp[i+1][j-1]);
 if (j==0) inp[i][j]=data[i][j]+max(inp[i+1][j+1],inp[i+1][j]);
}
cout<<inp[0][5]<<endl;
}
return 0; }
