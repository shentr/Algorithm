// CodeForces7A
//http://codeforces.com/problemset/problem/7A


#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
int sum,i,j;
char a[10][10];
int b[10][10];
int main()
{
    while(scanf("%s",a[0])!=EOF)
    {
        sum=0;
        for(i=1; i<8; i++)
            scanf("%s",a[i]);

        for(i=0; i<8; i++)
            for(j=0; j<8; j++)
            {
                if(a[i][j]=='W')
                    b[i][j]=0;
                else if(a[i][j]=='B')
                    b[i][j]=1;
            }
           /* for(i=0; i<8; i++)
            {
                for(j=0; j<8; j++)
            {
                cout<<b[i][j];
            }
            cout<<endl;
            }*/
        for(i=0; i<8; i++)
        {
            if(b[i][1]==1&&b[i][2]==1&&b[i][3]==1&&b[i][4]==1&&b[i][5]==1&&b[i][6]==1&&b[i][7]==1&&b[i][0]==1)
                sum++;
        }
        for(j=0; j<8; j++)
        {
            if(b[1][j]==1&&b[2][j]==1&&b[3][j]==1&&b[4][j]==1&&b[5][j]==1&&b[6][j]==1&&b[7][j]==1&&b[0][j]==1)
                sum++;
        }
        if(sum==16)
            sum=sum/2;

        cout<<sum<<endl;
    }
}
