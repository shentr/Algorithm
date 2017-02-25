// LightOJ1315
//http://lightoj.com/login_main.php?url=volume_showproblem.php?problem=1315


#include<iostream>
#include<cstdio>
using namespace std;
int nxt[6][2] = { {-2,1}, {1,-2},{-2,-1},{-1,-2},{-3,-1},{-1,-3}};
#define mx 2000
bool on[mx][mx];
int sg[mx][mx];
int calcsg(int xx, int yy){
	int tmp[101];
	int a,b,c,d,e,f,g,h,x,y,z;
	if(on[xx][yy] != 0)
		return sg[xx][yy];
	on[xx][yy] = 1;
	for(x = 0; x < 100; x++)
		tmp[x] = 0;
	for(x = 0; x < 6;x++){
		a = xx + nxt[x][0];
		b = yy + nxt[x][1];
		if(a >= 0 && b >= 0)
			tmp[calcsg(a,b)] = 1;
	}
	for(x = 0; x < 100; x++)
		if(tmp[x] == 0)
			return sg[xx][yy] = x;
}
int main(){
	int a,b,c,d,e,f,g,h, x, y,z ;
	scanf("%d", &a);
	for(z = 1; z <= a; z++){
		cin >> b;
		c = 0;
		for(x = 0; x < b; x++){
			cin >> d >> e;
			c ^= calcsg(d,e);
		}
		printf("Case %d: %s\n",z,c?"Alice":"Bob");
	}
}