// HDU1312
//http://acm.hdu.edu.cn/showproblem.php?pid=1312


#include <iostream>

using namespace std;
int n,m,sum;
char a[25][25];

void dfs(int i,int j)
{
    a[i][j]='#';
    sum++;
    if((i-1>=0)&&(a[i-1][j]=='.')) dfs(i-1,j);
    if((i+1<m)&&(a[i+1][j]=='.')) dfs(i+1,j);
    if((j-1>=0)&&(a[i][j-1]=='.')) dfs(i,j-1);
    if((j+1<n)&&(a[i][j+1]=='.')) dfs(i,j+1);
}
int main()
{

    while(cin>>n>>m)
    {
        if(n==0&&m==0)
            break;
        sum=0;
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                cin>>a[i][j];
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
            {

                if(a[i][j]=='@')
                    dfs(i,j);
            }
        cout<<sum<<endl;
    }
    return 0;
}
