// CodeForces389B
//http://codeforces.com/problemset/problem/389B


#include<iostream>
#include<cstdio>
using namespace std;
char a[105][105];

int main()
{
    int n;
    while(cin>>n)
    {
        for(int i=0;i<n;i++)
            scanf("%s",a[i]);
        int flag=1,count=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
        {
            if(a[i][j]=='#')
                count++;
        }
        if(count%5!=0)
        {
            printf("NO\n");
            continue;
        }
        for (int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if (a[i][j]=='#')
                {
                    if ((a[i+1][j]=='#')&&(a[i+1][j-1]=='#')&&(a[i+1][j+1]=='#')&&(a[i+2][j]=='#'))
                    {
                        a[i][j]='.';
                        a[i+1][j]='.';
                        a[i+2][j]='.';
                        a[i+1][j-1]='.';
                        a[i+1][j+1]='.';
                    }
                    else
                    {
                        flag=0;
                        break;
                    }
                }
            }
            if (flag==0)
                break;
	}
	if (flag==0)
		printf("NO\n");
	else
		printf("YES\n");
    }
}
