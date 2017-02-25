// CodeForces420A
//http://codeforces.com/problemset/problem/420A


#include <cstdio>
#include <cstring>
#include <cstdlib>

int main()
{ 
	char s[100001];
	scanf("%s",s);
	int n=strlen(s);
	int m=n/2+n%2;
	char ss[100]="AHIMOTUVWXY";
	int ln=strlen(ss); 
	bool b[256];
	for(int i=0;i<ln;i++){
		b[ss[i]]=1;
	} 
	for(int i=0;i<m;i++){ 
		if(!b[s[i]]|!b[s[n-1-i]]||s[i]!=s[n-1-i]){
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	return 0;
} 