// CodeForces412A
//http://codeforces.com/problemset/problem/412A


#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
    char a[105];
    int n,m;
    while(cin>>n>>m)
    {
        getchar();
       // memset(a,0,sizeof(a));
        for(int i=1;i<=n;i++)
            scanf("%c",&a[i]);
           // getchar();

            if(n-m>=m-1)
            {
                for(int i=1;i<=m-1;i++)
                {
                    printf("LEFT\n");
                   // m--;
                }

            for(int j=1;j<n;j++)
            {
                cout<<"PRINT"<<" ";
                cout<<a[j]<<endl;
                cout<<"RIGHT"<<endl;

            }

            cout<<"PRINT"<<" "<<a[n]<<endl;
            }
         else
            {
                 for(int i=1;i<=n-m;i++)
                {
                    printf("RIGHT\n");
                   // m++;
                }

            for(int j=n;j>1;j--)
            {
                cout<<"PRINT"<<" ";
                cout<<a[j]<<endl;
                cout<<"LEFT"<<endl;

            }

            cout<<"PRINT"<<" "<<a[1]<<endl;
            }
 //for(int i=1;i<=n;i++)
        //    printf("%c",a[i]);

    }
    return 0;
}
