// POJ2386
//http://poj.org/problem?id=2386


#include<cstdio>
const int N=105;

char a[N][N];
int n,m;

void dfs(int r,int c)
{
    if(r<0||c<0||r>=n||c>=m||a[r][c]!='W')
        return ;
    if(a[r][c]=='W')
    {
        a[r][c]='.';
        dfs(r+1,c-1);
        dfs(r+1,c);
        dfs(r+1,c+1);
        dfs(r-1,c);
        dfs(r-1,c-1);
        dfs(r-1,c+1);
        dfs(r,c-1);
        dfs(r,c+1);
    }
    return ;
}

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        getchar();
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            scanf("%c",&a[i][j]);
            getchar();
        }
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                if(a[i][j]=='W')
                {
                    count++;
                    dfs(i,j);
                }
            }
        printf("%d\n",count);
    }
}
