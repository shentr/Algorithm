// HDU2102
//http://acm.hdu.edu.cn/showproblem.php?pid=2102


#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

int c, n, m, t;
char map[2][12][12];
bool vis[2][12][12];
struct node
{
	int x, y, z;
	int step;
};
queue<node> q;
int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

bool bfs(int n,int m)
{
	while (!q.empty())
	{
		node now = q.front();
		q.pop();
		if (map[now.z][now.x][now.y] == 'P')
		{
			if (now.step >= 0)
				return true;
			else
				break;
		}
		node next;
		for (int i=0; i<4; i++)
		{
			next.x = now.x + dir[i][0];
			next.y = now.y + dir[i][1];
			next.z = now.z;
			next.step = now.step - 1;
			if (map[now.z][next.x][next.y] == '#')
				next.z ^= 1;
			if (map[next.z][next.x][next.y] != '*'&&next.x>=0&&next.x<n&&next.y>=0&&next.y<m&& next.step >= 0 && !vis[next.z][next.x][next.y])
			{
				vis[next.z][next.x][next.y] = true;
				q.push(next);
			}
		}
	}
	return false;
}

int main()
{
	scanf("%d", &c);
	while (c--)
	{
		scanf("%d %d %d", &n, &m, &t);
		memset(vis, false, sizeof(vis));
		while (!q.empty()) q.pop();
		for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                cin>>map[0][i][j];
            getchar();
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                cin>>map[1][i][j];
		node s;
		for (int i=0; i<2; i++)
			for (int j=0; j<n; j++)
				for (int k=0; k<m; k++)
				{
					if (map[i][j][k] == 'S')
						s.x = j, s.y = k, s.z = i,s.step = t;
					else if (map[i][j][k] == '#' &&map[1^i][j][k] == '#')
					{
						map[i][j][k] = '*';
						map[1^i][j][k] = '*';
					}
					else if (map[i][j][k] == '#' &&map[1^i][j][k] == '*')
						map[i][j][k] = '*';
				}
		vis[s.z][s.x][s.y] = true;
		q.push(s);
		if (bfs(n,m))
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
