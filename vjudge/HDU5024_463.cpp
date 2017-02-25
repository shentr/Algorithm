// HDU5024
//http://acm.hdu.edu.cn/showproblem.php?pid=5024


#include <bits/stdc++.h>

using namespace std;

const int N = 105;
int dp[N][N][10];
char Map[N][N];

int main() {
    int n;
    ios::sync_with_stdio(false);
    int p[8][2] = {{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1},{0,1}};
	while(cin>>n&&n) {
        memset(Map,0,sizeof(Map));
		memset(dp, 0, sizeof(dp));
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				cin>>Map[i][j];
				if(Map[i][j] == '.') {
					for(int k = 0; k < 8; k++) {
						dp[i][j][k] = 1;
					}
				}
			}
		}
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				if(Map[i][j] == '#')
					continue;
				for(int k = 0; k < 4; k++) {
					int x = i + p[k][0];
					int y = j + p[k][1];
					if(x > 0 && y > 0 && x <= n && y <= n && Map[x][y] != '#') {
						dp[i][j][k] += dp[x][y][k];
					}
				}
			}
		}
		for(int i = n; i >= 1; i--) {
			for(int j = n; j >= 1; j--) {
				if(Map[i][j] == '#')
					continue;
				for(int k = 4; k < 8; k++) {
					int x = i + p[k][0];
					int y = j + p[k][1];
					if(x > 0 && y > 0 && x <= n && y <= n && Map[x][y] != '#') {
						dp[i][j][k] += dp[x][y][k];
					}
				}
			}
		}
		int res = 0;
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				for(int k = 0; k < 8; k++) {
					if(dp[i][j][k] + dp[i][j][(k + 2)%8] > res)
						res = dp[i][j][k] + dp[i][j][(k + 2)%8];
				}
			}
		}
		cout<<res-1<<endl;
	}
}
