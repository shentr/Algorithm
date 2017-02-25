// POJ1734
//http://poj.org/problem?id=1734


#pragma warning(disable:4996)
#include <fstream>
#include <iostream>
#include <functional>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <cstdio>
#include <cmath>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>
using namespace std;
typedef long long ll;

#define LL_INF 0x3fffffffffffffff
#define INF 9999999
#define mem(a, b) memset(a, b, sizeof(a))
#define pper(i,n,m) for(int i = n;i >= m; i--)
#define repp(i, n, m) for (int i = n; i <= m; i++)
#define rep(i, n, m) for (int i = n; i < m; i++)
#define sa(n) scanf("%d", &(n))
#define mp make_pair
#define ff first
#define ss second
#define pb push_back

const int maxn = 110;
const ll mod = 1e9 + 7;
const double PI = acos(-1.0);

int n, m, ans, cnt;
int path[maxn];
int dis[maxn][maxn], d[maxn][maxn], res[maxn][maxn];

void init()
{
	int i, j, k;
	for (i = 1; i <= 100; i++)
	{
		for (j = 1; j <= 100; j++)
		{
			if (i == j)
			{
				dis[i][j] = 0;
			}
			else
			{
				dis[i][j] = INF;
			}
		}
	}
	mem(res, 0);
}

void road(int x, int y)
{
	if (res[x][y])
	{
		road(x, res[x][y]);
		road(res[x][y], y);
	}
	else
	{
		path[++cnt] = y;
	}
}

void cal()
{
	int i, j, k;
	cnt = 0;
	ans = INF;
	repp(k, 1, n)
	{
		repp(i, 1, k - 1)
		{
			repp(j, i + 1, k - 1)
			{
				if (ans > dis[i][j] + d[i][k] + d[k][j])
				{
					ans = dis[i][j] + d[i][k] + d[k][j];
					cnt = 0;
					path[++cnt] = i;
					road(i, j);
					path[++cnt] = k;
				}
			}
		}
		repp(i, 1, n)
		{
			repp(j, 1, n)
			{
				int s = dis[i][k] + dis[k][j];
				if (s < dis[i][j])
				{
					dis[i][j] = s;
					res[i][j] = k;
				}
			}
		}
	}
	if (ans == INF)
	{
		puts("No solution.");
	}
	else
	{
		repp(i, 1, cnt)
		{
			printf("%d%c", path[i], i == cnt ? '\n' : ' ');
		}
	}
}

void solve()
{
	int i, j, k;
	int u, v, w;
	for (i = 1; i <= m; i++)
	{
		sa(u), sa(v), sa(w);
		if (dis[u][v] > w)
		{
			dis[u][v] = dis[v][u] = w;
		}
	}
	repp(i, 1, n)
	{
		repp(j, 1, n)
		{
			d[i][j] = dis[i][j];
		}
	}
}

int main()
{
//#ifndef ONLINE_JUDGE
//	freopen("i.txt", "r", stdin);
//	freopen("o.txt", "w", stdout);
//#endif

	while (scanf("%d%d", &n, &m) != EOF)
	{
		init();
		solve();
		cal();
	}
	return 0;
}
