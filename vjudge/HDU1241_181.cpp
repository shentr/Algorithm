// HDU1241
//http://acm.hdu.edu.cn/showproblem.php?pid=1241


#include <iostream>

using namespace std;
int n,m,sum;
char a[105][105];

void dfs(int x,int y)
{
    int xn,yn;
    a[x][y]='#';
    for(int i=-1;i<=1;i++)
        for(int j=-1;j<=1;j++)
    {
        xn=x+i;
        yn=y+j;
        if(a[xn][yn]=='@'&&xn>=0&&xn<m&&yn>=0&&yn<n)
            dfs(xn,yn);
    }
    /*if((i-1>=0)&&(a[i-1][j]=='.')) dfs(i-1,j);
    if((i+1<m)&&(a[i+1][j]=='.')) dfs(i+1,j);
    if((j-1>=0)&&(a[i][j-1]=='.')) dfs(i,j-1);
    if((j+1<n)&&(a[i][j+1]=='.')) dfs(i,j+1);*/
}
int main()
{

    while(cin>>m>>n)
    {
        if(n==0&&m==0)
            break;
        sum=0;
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                cin>>a[i][j];
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                if(a[i][j]=='@')
                  {
                    dfs(i,j);
                    sum++;
            }
        cout<<sum<<endl;
    }
    return 0;
}
